/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 09:38:24 by aapresya          #+#    #+#             */
/*   Updated: 2021/05/23 09:38:26 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	updatestruct(void)
{
	t_flags.minus = 0;
	t_flags.zero = 0;
	t_flags.minwidth = 0;
	t_flags.period = 0;
	t_flags.precision = 0;
}

int		calculatespaces(int len)
{
	if (t_flags.precision > len)
		return (t_flags.minwidth - t_flags.precision);
	else
		return (t_flags.minwidth - len);
}

int		calculatezeroes(int len)
{
	if (t_flags.precision)
		return (t_flags.precision - len);
	else
		return (0);
}
