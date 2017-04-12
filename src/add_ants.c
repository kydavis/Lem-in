/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:44:04 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/12 11:38:01 by kdavis           ###   ########.fr       */
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

t_ant		*create_ant(t_room *start, uintmax_t nbr)
{
	t_ant	*ret;

	if (!(ret = (t_ant*)malloc(sizeof(*ret))))
		return (NULL);
	ret->nbr = nbr;
	ret->location = start;
	ret->next = NULL;
	ret->moved = 0;
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
