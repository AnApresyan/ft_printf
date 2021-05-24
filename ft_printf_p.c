/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:30:39 by aapresya          #+#    #+#             */
/*   Updated: 2021/05/23 14:30:42 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		addresslength(size_t decimal)
{
	int length;

	length = 2;
	if ((decimal) >= 0)
	{
		if (decimal == 0)
			length += 1;
		while (decimal != 0)
		{
			decimal /= 16;
			length++;
		}
		if (t_flags.period && t_flags.precision == 0 && !t_flags.minwidth)
			return (0);
	}
	else
		return (length += 8);
	return (length);
}

void	pointerconversion(size_t decimal)
{
	if (decimal >= 16)
		pointerconversion(decimal / 16);
	if ((decimal % 16) >= 10)
		ft_putchar_fd((decimal % 16) + 87, 1);
	else
		ft_putchar_fd(decimal % 16 + '0', 1);
}

void	checkaddresszero(size_t decimal)
{
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	if (decimal == 0)
		ft_putchar_fd('0', 1);
	else
		pointerconversion(decimal);
}

void	ft_helper_p(int spaces, int zeroes, size_t decimal)
{
	if (!t_flags.minus)
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(decimal == 0 && t_flags.precision == 0 && t_flags.period))
			checkaddresszero(decimal);
	}
	else
	{
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(decimal == 0 && t_flags.precision == 0 && t_flags.period))
			checkaddresszero(decimal);
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	}
}

void	ft_printf_pointer(void)
{
	int		zeroes;
	int		spaces;
	size_t	address;

	address = (size_t)t_flags.arg;
	spaces = calculatespaces(addresslength(address));
	zeroes = calculatezeroes(addresslength(address));
	if (t_flags.zero && t_flags.precision == 0 && !t_flags.period)
	{
		zeroes += spaces;
		spaces = 0;
	}
	ft_helper_p(spaces, zeroes, address);
}
