/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:47:42 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/19 19:20:15 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** add_line appends a new line to the map vector in master.
** also deletes the original input line.
*/

int	add_line(t_vec *map, char **line, size_t line_len)
{
	char	*new_line;
	int		ern;

	ern = 1;
	if (g_error != 0 || !(new_line = ft_strjoin(*line, "\n")))
	{
		ft_strdel(line);
		return (ERROR);
	}
	if (!(ft_vecapp(map, new_line, line_len + 1)))
		ern = ERROR;
	ft_strdel(&new_line);
	ft_strdel(line);
	return (ern);
}
