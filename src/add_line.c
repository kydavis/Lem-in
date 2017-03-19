/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 17:47:42 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/18 17:56:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** add_line appends a new line to the map vector in master.
*/

int	add_line(t_vec *map, char *line, size_t line_len)
{
	char	*new_line;
	int		ern;

	ern = 1;
	if (!(new_line = ft_strjoin(line, "\n")))
		return (ERROR);
	if (!(ft_vecapp(map, new_line, line_len + 1)))
		ern = ERROR;
	ft_strdel(&new_line);
	return (ern);
}
