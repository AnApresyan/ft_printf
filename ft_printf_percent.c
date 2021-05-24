/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:46:34 by aapresya          #+#    #+#             */
/*   Updated: 2021/05/24 21:46:38 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_helper_percent(int spaces, int zeroes)
{
	if (!t_flags.minus)
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		ft_putchar_fd('%', 1);
	}
	else
	{
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		ft_putchar_fd('%', 1);
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	}
}

void	ft_print_percent(void)
{
	int spaces;
	int zeroes;

	spaces = calculatespaces(1);
	zeroes = calculatezeroes(1);
	if (t_flags.zero && t_flags.precision == 0 && !t_flags.period)
	{
		zeroes += spaces;
		spaces = 0;
	}
	ft_helper_percent(spaces, zeroes);
}
