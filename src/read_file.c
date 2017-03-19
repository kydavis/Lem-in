/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:25:29 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/19 14:19:39 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	get_ants(t_li_master *master)
{
	char	*line;
	size_t	line_len;
	int		ern;

	ern = 1;
	if ((line_len = get_next_line(0, &line)) < 1)
		return (ERROR);
	master->nbr_ants = ft_atoull(line);
	if (ft_ullsize_base(master->nbr_ants, 10) != line_len)
	{
		ern = ERROR;
		g_error = 1;
	}
	else
		ern = add_line(&master->map, line, line_len);
	ft_strdel(&line);
	return (ern);
}

int			read_file(t_li_master *master)
{
	if ((get_ants(master)) == ERROR)
		return (ERROR);
	if ((get_rooms(master)) == ERROR)
		return (ERROR);
/*	if ((get_links(master)) == ERROR)
		return (ERROR);*/
	return (1);
}
