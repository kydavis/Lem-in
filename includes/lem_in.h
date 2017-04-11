/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:27:32 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/11 14:29:06 by kdavis           ###   ########.fr       */
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
# define ANT_MAX master->nbr_ants

extern int	g_error;
extern int	g_flags;

/*
** connection: index of the rooms that this room is connected to.
** name: Name of the room
** dist: distance of room to end.
** position: 1:start 0:middle -1:end
** vacant: 0: occupied 1: vacant.
** coord[2]: [x, y] coordinates of the room
*/

typedef struct		s_room
{
	t_vec			links;
	char			*name;
	size_t			dist;
	int				coord[2];
	char			vacant;
}					t_room;

/*
** struct s_ant contains information on a particular ant
** nbr: Ant's id number
** location: room the ant is currently occupying
** next: next ant in the line.
*/

typedef struct		s_ant
{
	uintmax_t		nbr;
	t_room			*location;
	int				color;
	struct s_ant	*next;
}					t_ant;

/*
** struct s_marching is a queue of the ants currently active on the map
*/

typedef struct		s_marching
{
	t_ant			*first;
	t_ant			*last;
}					t_marching;

/*
** room: array of pointers to t_room structures (t_room**)
** map: Final output to be printed to the screen
** nbr_ants: The number of ants
*/

typedef struct		s_li_master
{
	t_vec			room;
	t_vec			map;
	uintmax_t		nbr_ants;
	char			ant_f;
	char			room_f;
	t_room			*start;
	t_room			*end;
}					t_li_master;

int					read_rooms(t_li_master *master, char *line, char *position);
int					read_links(t_li_master *master, char *line);
int					add_line(t_vec *map, char **line, size_t line_len);

/*
** heatmap.c
*/

int					create_heatmap(t_li_master *master);

/*
** add_ants.c
*/

uintmax_t			add_ants(t_marching *order, t_room *start, uintmax_t max,
						uintmax_t current);

/*
** send_ants.c
*/

int					send_ants(t_li_master *master);

/*
** Map printing: (print_map.c)
*/
void				print_map(t_li_master *master);

/*
** validate_numbers.c
*/
int					validate_atouintmax(uintmax_t *ret, char *str);
int					validate_atoi(int *ret, char *str);

/*
** read_file.c
*/
int					read_file(t_li_master *master);
int					delete_grid(int ern, char **grid);
char				**parse_line(char *line, char delimiter, int size);
char				read_commands(t_li_master *master, char *line,
						char position);

/*
** cleanup functions
*/
int					li_cleanup(int ern, t_li_master *master);
#endif
