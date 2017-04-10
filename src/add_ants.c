/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:44:04 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/10 13:44:46 by kdavis           ###   ########.fr       */
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

uintmax_t	add_ants(t_marching *order, t_room *start,
		uintmax_t max, uintmax_t current)
{
	if (!())
	return (1);
}
