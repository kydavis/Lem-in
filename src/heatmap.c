/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:06:30 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/11 14:42:49 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Insertion sort to sort the linked rooms in current so that the distances
** for the linked rooms are in ascending order.
*/

void	sort_links(t_room *current)
{
	size_t	i;
	size_t	j;
	t_room	**array;
	t_room	*temp;

	i = 1;
	array = ((t_room**)current->links.arr);
	while (i < current->links.len)
	{
		j = i;
		while (j > 0 && array[j - 1]->dist > array[j]->dist)
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
		i++;
	}
}

/*
** Create a heatmap using Breadth first traversal.
*/

void	add_to_heatmap(t_vec *queue, t_room *current)
{
	size_t	i;
	t_room	*dest;

	i = 0;
	while (i < current->links.len)
	{
		dest = ((t_room**)current->links.arr)[i];
		if (dest->dist == (size_t)~0)
		{
			dest->dist = current->dist + 1;
			dest->vacant = 1;
			((t_room**)queue->arr)[queue->len] = dest;
			queue->len++;
		}
		i++;
	}
}

int		create_heatmap(t_li_master *master)
{
	t_vec	queue;
	t_room	*current;
	size_t	i;

	if (!ft_initialize_vec(&queue, sizeof(t_room *), ROOM.len, 1))
		return (ERROR);
	((t_room**)queue.arr)[0] = master->end;
	master->end->dist = 0;
	master->end->vacant = 1;
	i = 0;
	while (i < queue.len)
	{
		current = ((t_room**)queue.arr)[i];
		if (current != master->start)
			add_to_heatmap(&queue, current);
		sort_links(current);
		i++;
	}
	ft_memdel(&queue.arr);
	if (master->start->dist == (size_t)~0)
	{
		g_error = 10;
		return (ERROR);
	}
	return (OK);
}
