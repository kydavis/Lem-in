/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:27:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/11 14:37:37 by kdavis           ###   ########.fr       */
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
	"Error 8: Two start commands",
	"Error 9: Two end commands",
	"Error 10: No path between start and end",
	"Error 11: No start",
	"Error 12: No end",
	"Error 13: No start or end",
};

static void	remove_rooms(t_li_master *master)
{
	t_room	*del;
	size_t	i;

	i = 0;
	while (i < ROOM.len)
	{
		del = *((t_room **)ROOM.arr + i);
		ft_strdel(&del->name);
		ft_memdel(&del->links.arr);
		ft_memdel((void*)&del);
		i++;
	}
	ft_memdel(&ROOM.arr);
}

/*
** Cleanup memory allocations at the end of the program
** while loop at the end is meant to purge any leftover
** memory get_next_line may be holding in its static
** variables.
*/

int			li_cleanup(int ern, t_li_master *master)
{
	char *line;

	remove_rooms(master);
	ft_memdel(&MAP.arr);
	if (ern < 0 || g_error != 0)
		ft_putendl_fd(g_error_message[g_error], 2);
	while (get_next_line(0, &line) > 0)
		ft_strdel(&line);
	ft_strdel(&line);
	return (ern);
}
