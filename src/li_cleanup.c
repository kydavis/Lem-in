/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:27:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/18 17:03:50 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	remove_rooms(t_li_master *master)
{
	t_room	*del;
	int		i;

	i = 0;
	while (i < master->nbr_rooms)
	{
		del = (t_room *)(master->room.arr + i);
		ft_strdel(&del->name);
		ft_memdel(&del->connection.arr);
		ft_memdel((void*)&del);
		i++;
	}
	ft_memdel(&master->room.arr);
}

int		li_cleanup(int ern, t_li_master *master)
{
	remove_rooms(master);
	ft_memdel(&master->map.arr);
	if (ern < 0)
		ft_putendl_fd("ERROR", 2);
	return (ern);
}
