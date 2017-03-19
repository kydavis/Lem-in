/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:28:05 by kdavis            #+#    #+#             */
/*   Updated: 2017/03/18 14:26:28 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	main(int argc, char **argv)
{
	t_li_master	master;

	ft_bzero(&master, sizeof(master));
	ft_initialize_vec(&master.map, sizeof(char), BUFF_SIZE, 0);
	if (read_file(&master) == ERROR)
		return (li_cleanup(ERROR, &master));
	ft_printf("%s\n", (char*)master.map.arr);
	return (0);
}
