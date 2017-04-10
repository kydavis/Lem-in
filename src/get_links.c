/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:26:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/08 12:33:32 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

#define	LINK_R1TO2 (ft_vecapp(&(*r2)->links, r1, sizeof(*r1)))
#define	LINK_R2TO1 (ft_vecapp(&(*r1)->links, r2, sizeof(*r2)))

static int	duplicate_link(t_room *r1, char *room2)
{
	size_t	i;
	t_room	*link;

	i = 0;
	while (i < r1->links.len)
	{
		link = ((t_room**)r1->links.arr)[i];
		if (ft_strcmp(link->name, room2) == 0)
			return (1);
		i++;
	}
	return (0);
}

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
	if (r1 && r2 && (duplicate_link(*r1, room2) || (LINK_R1TO2 && LINK_R2TO1)))
		return (OK);
	g_error = 6;
	return (ERROR);
}
/*		ft_printf("%s r1:%d r2:%d\n", room[i]->name, r1 ? 1 : 0, r2 ? 1 : 0);*/
/*		ft_printf("\n%s\n%s\nrooms->len:%zu i:%zu\n",
				(r1 ? room2 : room1), (r2 ? room1 : room2), rooms->len, i);*/

//#define R1LINKS r1[0]->links///
/*	ft_printf("\nname:%s\nposition:%d\nx:%d\ny:%d\ndist:%d\naddress:%p\n\n",
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]->name,
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]->position,
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]->coord[0],
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]->coord[1],
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]->dist,
			((t_room**)R1LINKS.arr)[R1LINKS.len - 1]);*/
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
