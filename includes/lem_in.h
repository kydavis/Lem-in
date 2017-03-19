/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:27:32 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/18 14:30:12 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <stdio.h>
# include <libft.h>

# define ERROR -1

/*
** connection: index of the rooms that this room is connected to.
** name: Name of the room
** dist: distance of room to end.
** position: 1:start 0:middle -1:end
** occupied: 1: occupied 0: vacant.
*/

typedef struct	s_room
{
	t_vec		connection;
	char		*name;
	size_t		dist;
	int			x;
	int			y;
	char		position;
	char		occupied;
}				t_room;

/*
** room: array of t_room structures
** nbr_ants: The number of ants
** nbr_rooms: The number of rooms
*/

typedef struct	s_li_master
{
	t_vec		room;
	t_vec		map;
	uintmax_t	nbr_ants;
	size_t		nbr_rooms;
}				t_li_master;

int	read_file(t_li_master *master);
int	get_rooms(t_li_master *master);

/*
** cleanup functions
*/
int		li_cleanup(int ern, t_li_master *master);
#endif
