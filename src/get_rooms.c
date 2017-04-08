/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:26:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/07 18:25:45 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Make_room intializes each room with the appropriate name and coordinates
*/

#define LINK_INIT (ft_initialize_vec(&new_room->links, sizeof(t_room*), 10, 0))
#define VALID_X (validate_atoi(&new_room->coord[0], room_info[1]))
#define VALID_Y (validate_atoi(&new_room->coord[1], room_info[2]))
#define NAME (new_room->name = ft_strdup(room_info[0]))

static int	make_room(t_li_master *master, char **room_info, char position)
{
	t_room *new_room;

	if (!(ROOM.arr))
	{
		if (!(ft_initialize_vec(&ROOM, sizeof(t_room**), 10, 0)))
			return (ERROR);
	}
	if (!(new_room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (ERROR);
	if (!LINK_INIT || !VALID_X || !VALID_Y || !NAME)
	{
		ft_memdel((void*)&new_room->links.arr);
		ft_memdel((void*)&new_room);
		return (ERROR);
	}
	new_room->position = position;
	new_room->dist = ~0;
/*	if (!(ft_vecapp(&ROOM, &new_room, sizeof(new_room))))
		return (ERROR);*/
	if (!(ft_grow_vec(&ROOM, ROOM.size * (ROOM.len + 1))))
		return (ERROR);
	((t_room**)ROOM.arr)[ROOM.len] = new_room;
	ROOM.len += 1;
/*	ft_printf("\nname:%s\nposition:%d\nx:%d\ny:%d\ndist:%d\naddress:%p\n",
			new_room->name,
			new_room->position,
			new_room->coord[0],
			new_room->coord[1],
			new_room->dist,
			new_room);*/
/*	ft_printf("\nAfter appending")
	ft_printf("\nname:%s\nposition:%d\nx:%d\ny:%d\ndist:%d\naddress:%p\n",
			((t_room**)ROOM.arr)[ROOM.len - 1]->name,
			((t_room**)ROOM.arr)[ROOM.len - 1]->position,
			((t_room**)ROOM.arr)[ROOM.len - 1]->coord[0],
			((t_room**)ROOM.arr)[ROOM.len - 1]->coord[1],
			((t_room**)ROOM.arr)[ROOM.len - 1]->dist,
			((t_room**)ROOM.arr)[ROOM.len - 1]);*/
	return (OK);
}

/*	((t_room **)ROOM.arr)[ROOM.len] = new_room;
	ROOM.len += 1;*/
/*
** Read_rooms is responsible for formatting the rooms properly
*/

int	read_rooms(t_li_master *master, char *line, char *position)
{
	char	**room_info;
	size_t	i;
	int		ret;

	if (!(room_info = parse_line(line, ' ', 3)))
		return (ERROR);
	i = 0;
	while (i < ROOM.len)
	{
		if (ft_strcmp(room_info[0], ((t_room**)ROOM.arr)[i]->name) == 0)
			g_error = 7;
		i++;
	}
	ret = make_room(master, room_info, *position);
	*position = 0;
	return (delete_grid(ret, room_info));
}

/*
** get_rooms is the hub function for parsing the room data retrieved from the
** standard input.
*/

/*int	get_rooms(t_li_master *master)
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
	ern = read_links(master, line);
	if (ern == ERROR)
		g_error = 3;
	ern = add_line(&master->map, &line, len);
	return (ern);
}*/
