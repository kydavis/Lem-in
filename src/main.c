/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:28:05 by kdavis            #+#    #+#             */
/*   Updated: 2017/02/23 23:14:05 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int	main(int argc, char **argv)
{
	t_li_master	master;

	ft_bzero(&master, sizeof(master));
	if (read_file(&master) == -1)
		return (li_cleanup(-1, &master));
	ft_printf("No error, number of ants:%ju\n", master.nbr_ants);
	return (0);
}
