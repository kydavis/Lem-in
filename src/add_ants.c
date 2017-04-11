/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:44:04 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/11 13:13:45 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	push_ant(t_marching *order, t_ant *ant)
{
	if (!(order->first))
		order->first = ant;
	else if (order->last)
		order->last->next = ant;
	order->last = ant;
}

t_ant	*create_ant(t_room *start, uintmax_t nbr)
{
	t_ant	*ret;

	if (!(ret = (t_ant*)malloc(sizeof(*ret))))
		return (NULL);
	ret->nbr = nbr;
	ret->location = start;
	ret->next = NULL;
	ret->color = nbr % 7 + 1;
	return (ret);
}

/*
** Responsible for releasing the ants into the appropriate rooms in the map
*/

uintmax_t	add_ants(t_marching *order, t_room *start,
		uintmax_t max, uintmax_t ant_id)
{
	t_ant		*ant;
	t_room		*next;
	t_room		*current;
	uintmax_t	dist;
	size_t		i;

	i = 1;
	next = NULL;
	dist = 0;
	while (i <= start->links.len && ant_id < max && dist < max - ant_id)
	{
		ant_id++;
		if (!(ant = create_ant(start, ant_id)))
			return (~0);
		push_ant(order, ant);
		next = ((t_room**)start->links.arr)[i];
		current = ((t_room**)start->links.arr)[i - 1];
		if (next)
			dist = (uintmax_t)(next->dist - current->dist);
		i++;
	}
	return (i - 1);
}

/*	ft_printf("max:%ju ant id:%ju location:%s dist:%d next:%s\n",
			max, ant->nbr, ant->location->name, ant->location->dist,
			ant->next ? "yes" : "no");*/
/*static int		print_ant(t_ant *ant)
{
	char	*nbr_str;

	ft_putchar('L');
	printf("\n\nbefore ft_ulltoa_base next:%p\n", ant->next);///
	if (!(nbr_str = ft_ulltoa_base(ant->nbr, 10, 0)))
		return (ERROR);
	printf("after ft_ulltoa_base next:%p\n\n", ant->next);///
	ft_putstr(nbr_str);
	ft_putchar('-');
	ft_putstr(ant->location->name);
	if (ant->next)
		ft_putchar(' ');
	ft_strdel(&nbr_str);
	return (OK);*/
