/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:26:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/19 14:15:48 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	make_room(t_li_master *master)
{
	if (!(master->room.arr))
		ft_initialize_vec(&master->room, sizeof(t_room *), 10, 1);
	return (1);
}

/*
** Read_commands will check the lines for comments and commands. If the line
** is a command
*/

static char	read_commands(t_li_master *master, char *line, char position)
{
	if (ft_strequ(line, "##start"))
	 	position = 1;
	else if (ft_strequ(line, "##end"))
	 	position = -1;
	return (position);
}

/*
** Read_rooms is responsible for formatting the rooms properly
*/

static int	read_rooms(t_li_master *master, char *line, char position)
{
	if (line[0] == '#')
		return (1);
	return (1);
}

/*
** get_rooms is the hub function for parsing the room data retrieved from the
** standard input.
*/

int	get_rooms(t_li_master *master)
{
	char	*line;
	int		ern;
	char	position;

	position = 0;
	while ((ern = get_next_line(0, &line)) > 0)
	{
		//ft_putendl("iterate");
		position = read_commands(master, line, position);
		ern = add_line(&master->map, line, ern);
		ft_strdel(&line);
		if (ern == ERROR || ern == 0)
			break;
	}
	//ft_putendl("exit while loop");
	return (ern);
}
