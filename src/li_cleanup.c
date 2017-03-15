/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:27:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/23 23:44:56 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	remove_rooms(t_li_master *master)
{
	int	i;

	i = 0;
	while (i < master->nbr_rooms)
	{
		ft_strdel(&master->room[i].name);
		ft_memdel(&master->room[i].connection.arr);
		ft_memdel((void*)(master->room + i));
		i++;
	}
}

int		li_cleanup(int ern, t_li_master *master)
{
	remove_rooms(master);
	if (ern < 0)
		ft_putendl_fd("ERROR", 2);
	return (ern);
}
