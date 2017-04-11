/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:29:10 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/11 14:43:11 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	print_format(t_li_master *master, t_room *room, char parent)
{
	if (parent)
	{
		if (room == master->start)
			ft_printf("Room:\e[92m\e[1m%s dist:%d\e[0m connected to\n{\n",
					room->name, room->dist);
		else if (room == master->end)
			ft_printf("Room:\e[91m\e[1m%s dist:%d\e[0m connected to\n{\n",
					room->name, room->dist);
		else
			ft_printf("Room:\e[93m\e[1m%s dist:%d\e[0m connected to\n{\n",
					room->name, room->dist);
	}
	else
	{
		if (room == master->start)
			ft_printf("\e[92m\t%s dist:%d\e[0m\n", room->name, room->dist);
		else if (room == master->end)
			ft_printf("\e[91m\t%s dist:%d\e[0m\n", room->name, room->dist);
		else
			ft_printf("\e[93m\t%s dist:%d\e[0m\n", room->name, room->dist);
	}
}

void		print_map(t_li_master *master)
{
	t_room	*current;
	t_room	*child;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ROOM.len)
	{
		j = 0;
		current = ((t_room**)ROOM.arr)[i];
		print_format(master, current, 1);
		while (j < current->links.len)
		{
			child = ((t_room**)current->links.arr)[j];
			print_format(master, child, 0);
			j++;
		}
		ft_printf("}\n\n");
		i++;
	}
}
