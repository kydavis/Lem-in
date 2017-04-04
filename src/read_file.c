/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:25:29 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/03 21:54:13 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static int	get_ants(t_li_master *master)
{
	char	*line;
	size_t	line_len;
	int		ern;

	ern = ERROR;
	if ((line_len = get_next_line(0, &line)) < 1)
		return (ERROR);
	if (!(validate_atouintmax(&master->nbr_ants, line)))
		g_error = 1;
	ern = add_line(&MAP, &line, line_len);
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
