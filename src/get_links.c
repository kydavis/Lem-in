/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:26:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/07 14:49:24 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

#define	LINK_R1TO2 (ft_vecapp(&(*r2)->links, r1, sizeof(*r1)))
#define	LINK_R2TO1 (ft_vecapp(&(*r1)->links, r2, sizeof(*r2)))

#define R1LINKS r1[0]->links///
static int	make_links(t_vec *rooms, char *room1, char *room2)
{
	t_room	**room;
	size_t	i;
	t_room	**r1;
	t_room	**r2;

	room = (t_room**)rooms->arr;
	i = 0;
	r1 = NULL;
	r2 = NULL;
	while (i < rooms->len && (!r1 || !r2))
	{
		if (ft_strcmp(room1, room[i]->name) == 0)
			r1 = room + i;
		else if (ft_strcmp(room2, room[i]->name) == 0)
			r2 = room + i;
		i++;
	}
	if (i == rooms->len || !LINK_R1TO2 || !LINK_R2TO1)
	{
		g_error = 6;
		return (ERROR);
	}
	ft_printf("\nname:%s\nposition:%d\nx:%d\ny:%d\ndist:%d\naddress:%p\n\n",
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]->name,
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]->position,
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]->coord[0],
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]->coord[1],
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]->dist,
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]);
	return (OK);
}

int	read_links(t_li_master *master, char *line)
{
	char	**link_info;
	int		ret;

	master->room_f = 1;
	ret = ERROR;
	if (!(link_info = parse_line(line, '-', 2)))
		return (ERROR);
/*	ft_printf("r1:%s r2:%s\n", link_info[0], link_info[1]);*/
	if (ft_strcmp(link_info[0], link_info[1]) == 0)
		g_error = 3;
	else
		ret = make_links(&master->room, link_info[0], link_info[1]);
	return (delete_grid(ret, link_info));
}

/*int	get_links(t_li_master *master)
{
	char	*line;
	int		len;
	int		ern;
	char	position;

	position = 0;
	while ((len = get_next_line(0, &line)) >= 0)
	{
		position = read_commands(line, position);
		if (line[0] == 'L' || read_rooms(master, line, &position) == ERROR)
			g_error = 2;
		ern = add_line(&master->map, &line, len);
		if (g_error != 0 || ern == ERROR)
			break ;
	}
}*/
