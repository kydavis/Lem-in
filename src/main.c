/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:28:05 by kdavis            #+#    #+#             */
/*   Updated: 2017/05/04 21:35:26 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	g_error = 0;
int	g_flags = 0;

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

static int	set_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-s") == 0)
			g_flags |= 0x1;
		else if (ft_strcmp(argv[i], "-v") == 0)
			g_flags |= 0x2;
		else if (ft_strcmp(argv[i], "-c") == 0)
			g_flags |= 0x4;
		else
		{
			ft_printf("Usage: ./lem-in [-c -s -v] < test file\n");
			ft_printf("-c: color option (color coordinate the ants)\n");
			ft_printf("-v: verbose option (display heatmap connections)\n");
			ft_printf("-s: silent option (silence map info display)\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_li_master	master;

	if (!(set_flags(argc, argv)))
		return (-1);
	ft_bzero(&master, sizeof(master));
	ft_initialize_vec(&master.map, sizeof(char), BUFF_SIZE, 0);
	if (read_file(&master) == ERROR)
		return (li_cleanup(ERROR, &master));
	if (check_start_end(&master) == ERROR || create_heatmap(&master) == ERROR)
		return (li_cleanup(ERROR, &master));
	if (!(g_flags & 0x1))
		ft_printf("%s\n", (char*)master.map.arr);
	if ((g_flags & 0x2))
		print_map(&master);
	master.start->vacant = 0;
	send_ants(&master);
	li_cleanup(0, &master);
	return (0);
}
