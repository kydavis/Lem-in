/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:27:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/07 18:25:24 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>


static const char	*g_error_message[] =
{
	"Error 0: Error allocating memory",
	"Error 1: Improper number of ants",
	"Error 2: Improper Room format",
	"Error 3: Improper Link format",
	"Error 4: leading 'L' character in input",
	"Error 5: Applying start and end command to the same room",
	"Error 6: Could not find rooms to apply links to",
	"Error 7: Duplicate room name",
};

static void	remove_rooms(t_li_master *master)
{
	t_room	*del;
	size_t	i;

	i = 0;
/*	ft_printf("room len:%zu total:%zu size:%u array address:%p\n",
			ROOM.len, ROOM.total, ROOM.size, ROOM.arr);*/
	while (i < ROOM.len)
	{
		del = *((t_room **)ROOM.arr + i);
/*	ft_printf("name:%s\nposition:%d\nx:%d\ny:%d\ndist:%d\naddress:%p\n",
			del->name, del->position, del->coord[0], del->coord[1], del->dist, del);*/
		ft_strdel(&del->name);
		ft_memdel(&del->links.arr);
		ft_memdel((void*)&del);
		i++;
	}
	ft_memdel(&ROOM.arr);
}

int			li_cleanup(int ern, t_li_master *master)
{
	char *line;

	remove_rooms(master);
	ft_memdel(&MAP.arr);
	if (ern < 0 || g_error != 0)
		ft_putendl_fd(g_error_message[g_error], 2);
//This portion is used for cleaning up any remaining memory
	while (get_next_line(0, &line) > 0)
		ft_strdel(&line);
	ft_strdel(&line);
	return (ern);
}
