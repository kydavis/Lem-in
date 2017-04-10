/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:28:05 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/10 10:44:07 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	g_error = 0;

static int	check_start_end(t_li_master *master)
{
	if (!(master->start) && !(master->end))
		g_error = 13;
	else if (!(master->start))
		g_error = 11;
	else if (!(master->end))
		g_error = 12;
	else
		return (OK);
	return (ERROR);
}

int	main(int argc, char **argv)
{
	t_li_master	master;

	ft_bzero(&master, sizeof(master));
	ft_initialize_vec(&master.map, sizeof(char), BUFF_SIZE, 0);
	if (read_file(&master) == ERROR)
		return (li_cleanup(ERROR, &master));
	if (check_start_end(&master) == ERROR || create_heatmap(&master) == ERROR)
		return (li_cleanup(ERROR, &master));
	ft_printf("%s\n", (char*)master.map.arr);
	print_map(&master);///
/*	ft_printf("%s\n", (char*)master.map.arr);*/

	li_cleanup(0, &master);
	return (0);
	(void)argc;
	(void)argv;
}
