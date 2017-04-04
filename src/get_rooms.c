/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:26:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/03 22:08:55 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Make_room intializes each room with the appropriate name and coordinates
*/

static int	make_room(t_li_master *master, char	*line[3], char position)
{
	t_room *new_room;

	if (!(ROOM.arr))
	{
		if (!(ft_initialize_vec(&ROOM, sizeof(t_room **), 10, 0)))
			return (ERROR);
	}
	if (!(new_room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (ERROR);
	new_room->coord[0] = ft_atoi(line[1]);
	new_room->coord[1] = ft_atoi(line[2]);
	new_room->name = ft_strndup(line[0], ((line[1] - 1) - line[0]));
	new_room->position = position;
	((t_room **)ROOM.arr)[ROOM.len] = new_room;
/*	ft_printf("name:%s\nposition:%d\nx:%d\ny:%d\ndist:%d\naddress:%p\n",
			new_room->name, new_room->position, new_room->x,
			new_room->y, new_room->dist, new_room);*/
	ROOM.len += 1;
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
	(void)master;
}

/*
** Read_rooms is responsible for formatting the rooms properly
**
**	crd[0] = location of head of name substring.
**	crd[1] = location of head of x substring.
**	crd[2] = location of head of y substring.
*/

static int	read_rooms(t_li_master *master, char *line, char *position)
{
	char	*crd[3];
	int		i;

	if (line[0] == '#')
		return (1);
	i = 0;
	crd[0] = line;
	while (i++ < 2)
	{
		if (!(crd[i] = ft_strchr(crd[i - 1], ' ')))
			return (ERROR);
		crd[i] += 1;
	}
	if (ft_strchr(crd[2], ' ') || (make_room(master, crd, *position) == ERROR))
		return (ERROR);
	*position = 0;
	return (1);
}

/*
** get_rooms is the hub function for parsing the room data retrieved from the
** standard input.
*/

int	get_rooms(t_li_master *master)
{
	char	*line;
	int		len;
	int		ern;
	char	position;

	position = 0;
	while ((len = get_next_line(0, &line)) >= 0 &&
			(line[0] == '#' || !(ft_strchr(line, '-'))))
	{
		position = read_commands(master, line, position);
		if (line[0] == 'L' || read_rooms(master, line, &position) == ERROR)
			g_error = 2;
		ern = add_line(&master->map, &line, len);
		if (g_error != 0 || ern == ERROR)
			break ;
	}
	if (len < 0)
		return (ERROR);
/*	ern = read_link(master, line);
	if (ern == ERROR)
		g_error = 3;*/
	ern = add_line(&master->map, &line, len);
	return (ern);
}
