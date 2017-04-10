/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:45:21 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/10 13:43:33 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** For dispersal maximum number of ants to create is the number of links to end
** Also use the number of ants left and the distance of the link to decide if 
** you are going to use that pathway.
** if (current->dist - prev->dist < nbr_ants)
**		send ant to current;
*/

t_ant	*create_ant(t_room *start, int nbr)
{
	t_ant	*ret;

	if (!(ret = (t_ant*)malloc(sizeof(ret))))
		return (NULL);
	ret->nbr = nbr;
	ret->location = start;
	ret->next = NULL;
	return (ret);
}

static void		move_ant(t_marching *ordr, t_room *end, t_ant *ant, t_ant *prev)
{
	size_t	i;
	t_room	*prospect;
	
	i = 0;
	while (i < ant->location->links.len)
	{
		prospect = ((t_room**)ant->location->links.arr)[i];
		if (prospect.vacant)
			break;
		i++;
	}
	if (i == ant->location->links.len)
		return ;
	ant->location.vacant = 1;
	if (prospect != end)
	{
		prospect->location.vacant = 0;
		ant->location = prospect;
		return ;
	}
	else if (order->first == ant)
		order->first = ant->next;
	else if (prev)
		prev->next = ant->next;
	ft_memdel((void*)&ant);
}

static void	push_ant(t_marching *order, t_ant *ant)
{
	if (!(order->first))
		order->first = ant;
	else if (order->last)
		order->last->next = ant;
	order->last = ant;
}

uintmax_t	add_ants(t_marching *order, t_room *start,
		uintmax_t max, uintmax_t current)
{
	if (!())
	return (1);
}

int	send_ants(t_li_master *master)
{
	t_marching	order;
	t_ant		*ant;
	t_ant		*prev;
	uintmax_t	i;
	uintmax_t	add;

	ft_bzero(&order, sizeof(order));
	i = 0;
	while (i < master->nbr_ant || order.first)
	{
		ant = order.first;
		prev = NULL;
		while (ant)
		{
			move_ant(&order, master->end, ant, prev);
			prev = ant;
			ant = ant->next;
		}
		if ((add = add_ants(&order, master->start, master->nbr_ant, i)) == ~0)
			return (delete_ants(ERROR, order));
		i += add;
	}
}
