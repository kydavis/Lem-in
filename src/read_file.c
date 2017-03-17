/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:25:29 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/15 16:42:15 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	make_room(t_li_master *master)
{
	if (!(master->room.arr))
		ft_initialize_vec(&master->room, sizeof(master->room), 10, 1);
}

static int	read_commands(t_li_master *master, char **line)
{
	int	position;

	position = 0;
	if (ft_strequ(*line, "##start"))
	 	position = 1;
	else if (ft_strequ(*line, "##end"))
	 	position = -1;
	if (position == 0)
		return (0);
	ft_strdel(line);
	if (get_next_line(0, line) < 1)
		return (ERROR);
}

static int	get_ants(t_li_master *master)
{
	char	*line;
	size_t	line_len;
	int		ern;

	ern = 1;
	if ((get_next_line(0, &line)) < 1)
		return (ERROR);
	master->nbr_ants = ft_atoull(line);
	line_len = ft_strlen(line);
	if (ft_ullsize_base(master->nbr_ants, 10) != line_len)
		ern = ERROR;
	if (!(ft_grow_vec(&master->map, master->map.len + line_len)))
		ern = ERROR;
	else
		ft_memmove((char*)master->map.arr + 
	ft_strdel(&line);
	return (ern);
}

int			read_file(t_li_master *master)
{
	char	*line;
	int		ern;
	char	position;

	if ((get_ants(master)) == -1)
		return (ERROR);
	while ((ern = get_next_line(0, &line)) > 0)
	{
		if (read_commands(master, &line) == ERROR)
			return (ERROR);
	}
	return (ern);
}
