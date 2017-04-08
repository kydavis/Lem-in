/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:25:29 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/07 14:15:48 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	delete_grid(int ern, char **grid)
{
	size_t	i;

	i = 0;
	if (grid)
	{
		while (grid[i])
		{
			ft_memdel((void*)&grid[i]);
			i += 1;
		}
		ft_memdel((void*)&grid);
	}
	return (ern);
}

char		**parse_line(char *line, char delimiter, int size)
{
	char	**ret;
	int		i;

	if (!(ret = ft_strsplit(line, delimiter)))
		return (NULL);
	i = 0;
	while (ret[i])
		i++;
	if (i != size)
	{
		delete_grid(ERROR, ret);
		ret = NULL;
	}
	return (ret);
}

/*
** Read_commands will check the lines for comments and commands. If the line
** is a command
*/

char	read_commands(t_li_master *master, char *line, char position)
{
	if (ft_strequ(line, "##start"))
	{
		if (position != 0)
			g_error = 5;
		position = 1;
		master->start_f += 1;
	}
	else if (ft_strequ(line, "##end"))
	{
		if (position != 0)
			g_error = 5;
	 	position = -1;
		master->end_f += 1;
	}
	return (position);
}

static int	get_ants(t_li_master *master, char *line)
{
	master->ant_f = 1;
	if (!(validate_atouintmax(&master->nbr_ants, line)))
		g_error = 1;
	return (OK);
}

int			read_file(t_li_master *master)
{
	char	*line;
	int		len;
	int		ern;
	char	position;

	position = 0;
	while ((len = get_next_line(0, &line)) > 0)
	{
		if (line[0] == 'L')
			g_error = 4;
		else if (line[0] == '#')
			position = read_commands(master, line, position);
		else if (master->ant_f == 0)
			ern = get_ants(master, line);
		else if (master->room_f == 0 && !ft_strchr(line, '-'))
			ern = read_rooms(master, line, &position);
		else
			ern = read_links(master, line);
		if (add_line(&master->map, &line, len) == ERROR || g_error != 0 ||
			ern == ERROR)
			return (ERROR);
	}
	if (len < 0)
		return (ERROR);
	return (1);
}

/*	if ((get_rooms(master)) == ERROR)
		return (ERROR);
	if ((get_links(master)) == ERROR)
		return (ERROR);*/
