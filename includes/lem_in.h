/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:27:32 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/07 18:16:41 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <limits.h>

# define ERROR -1
# define OK		1
# define MAP	master->map
# define ROOM	master->room
# define LINK	master->room.links

extern int	g_error;

/*
** connection: index of the rooms that this room is connected to.
** name: Name of the room
** dist: distance of room to end.
** position: 1:start 0:middle -1:end
** occupied: 1: occupied 0: vacant.
** coord[2]: [x, y] coordinates of the room
*/

typedef struct	s_room
{
	t_vec		links;
	char		*name;
	size_t		dist;
	int			coord[2];
	char		position;
	char		occupied;
}				t_room;

/*
** room: array of pointers to t_room structures (t_room**)
** map: Final output to be printed to the screen
** nbr_ants: The number of ants
*/

typedef struct	s_li_master
{
	t_vec		room;
	t_vec		map;
	uintmax_t	nbr_ants;
	char		ant_f;
	char		room_f;
	char		start_f;
	char		end_f;
}				t_li_master;

int				get_rooms(t_li_master *master);
int				read_rooms(t_li_master *master, char *line, char *position);
int				read_links(t_li_master *master, char *line);
int				add_line(t_vec *map, char **line, size_t line_len);

/*
** validate_numbers.c
*/
int				validate_atouintmax(uintmax_t *ret, char *str);
int				validate_atoi(int *ret, char *str);

/*
** read_file.c
*/
int				read_file(t_li_master *master);
int				delete_grid(int ern, char **grid);
char			**parse_line(char *line, char delimiter, int size);
char			read_commands(t_li_master *master, char *line, char position);

/*
** cleanup functions
*/
int				li_cleanup(int ern, t_li_master *master);
#endif
