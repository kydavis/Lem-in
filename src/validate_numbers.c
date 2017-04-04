/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:26:58 by kdavis            #+#    #+#             */
/*   Updated: 2017/04/03 22:07:26 by kdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Will return an error if anything but the proper number is given.
*/

int	validate_atouintmax(uintmax_t *ret, char *str)
{
	uintmax_t	temp;

	*ret = 0;
	temp = 0;
	while (ft_isdigit(*str))
	{
		temp = *ret;
		*ret = 10 * *ret + ((*str++ - '0') % 10);
		if (*ret / 10 != temp)
			return (0);
	}
	if (*str)
		return (0);
	return (1);
}

/*
** Limited atoi that will return error on any improperly formatted number string
*/

int	validate_atoi(int *ret, char *str)
{
	uintmax_t	temp;
	int			sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!(validate_atouintmax(&temp, str)) || (sign == 1 && temp > INT_MAX)
			|| (sign == -1 && temp > (INT_MAX + 1UL)))
		return (0);
	*ret = sign * temp;
	return (1);
}
