/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:45:21 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/11 14:40:06 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		move_ant(t_room *start, t_room *end, t_ant *ant)
{
	size_t	i;
	t_room	*prospect;

	i = 0;
	while (i < ant->location->links.len)
	{
		prospect = ((t_room**)ant->location->links.arr)[i];
		if (prospect->vacant && prospect != start)
			break ;
		i++;
	}
	if (i == ant->location->links.len)
		return ;
	ant->location->vacant = 1;
	if (prospect != end)
		prospect->vacant = 0;
	ant->location = prospect;
}

static int		delete_ants(int ern, t_marching *order)
{
	t_ant	*ant;
	t_ant	*temp;

	ant = order->first;
	while (ant)
	{
		temp = ant;
		ant = ant->next;
		ft_memdel((void*)&temp);
	}
	return (ern);
}

static t_ant	*remove_ant(t_ant *prev, t_ant *ant, t_marching *order)
{
	if (prev)
		prev->next = ant->next;
	else if (ant == order->first)
		order->first = ant->next;
	ft_memdel((void*)&ant);
	if (prev)
		return (prev->next);
	return (order->first);
}

static void		print_ants(t_room *start, t_room *end, t_marching *order)
{
	t_ant *ant;
	t_ant *prev;

	ant = order->first;
	prev = NULL;
	while (ant)
	{
		if ((g_flags & 0x4) && ant->location != start)
			ft_printf("\e[9%dmL%ju-%s\e[0m", ant->color, ant->nbr,
					ant->location->name);
		else if (ant->location != start)
			ft_printf("L%ju-%s", ant->nbr, ant->location->name);
		if (ant->next && ant->location != start)
			ft_putchar(' ');
		if (ant->location == end)
		{
			ant = remove_ant(prev, ant, order);
		}
		else
		{
			prev = ant;
			ant = ant->next;
		}
	}
	ft_putchar('\n');
}

int				send_ants(t_li_master *master)
{
	t_marching	order;
	t_ant		*ant;
	uintmax_t	i;
	uintmax_t	add;

	ft_bzero(&order, sizeof(order));
	i = 0;
	while (order.first || i == 0)
	{
		if ((add = add_ants(&order, master->start, ANT_MAX, i)) == ~0ULL)
			return (delete_ants(ERROR, &order));
		ant = order.first;
		while (ant)
		{
			move_ant(master->start, master->end, ant);
			ant = ant->next;
		}
		print_ants(master->start, master->end, &order);
		i += add;
	}
	return (delete_ants(OK, &order));
}
