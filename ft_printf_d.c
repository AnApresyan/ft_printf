/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:55:35 by aapresya          #+#    #+#             */
/*   Updated: 2021/05/23 09:37:51 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_numlength(int num)
{
	int i;

	i = 0;
	if (num == 0)
	{
		if (t_flags.period && t_flags.precision == 0)
			i = 0;
		else
			i = 1;
	}
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	if (t_flags.period && t_flags.precision == 0 && !t_flags.minWidth)
		i = 0;
	return (i);
}

void ft_helper_digit(int spaces, int zeroes, int num)
{
	if (!t_flags.minus)
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
		if ((int)t_flags.arg < 0 && (int)t_flags.arg != -2147483648)
			ft_putchar_fd('-', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(num == 0 && t_flags.precision == 0 && t_flags.period))
			ft_putnbr_fd(num, 1);
	}
	else
	{
		if ((int)t_flags.arg < 0 && (int)t_flags.arg != -2147483648)
			ft_putchar_fd('-', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(num == 0 && t_flags.precision == 0 && t_flags.period))
			ft_putnbr_fd(num, 1);
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	}	
}

void ft_printf_int()
{
	int spaces;
	int zeroes;
	int num;

	spaces = calculateSpaces(ft_numlength((int)t_flags.arg));
	zeroes = calculateZeroes(ft_numlength((int)t_flags.arg));
	if(t_flags.zero && t_flags.precision == 0 && !t_flags.period){
		zeroes += spaces;
		spaces = 0;
	}
	num = (int)t_flags.arg;
	if ((int)t_flags.arg < 0)
	{
		num *= -1;
		spaces--;
		if (spaces <= 0 && zeroes > 0 && t_flags.precision == 0)
			zeroes--;
	}
	ft_helper_digit(spaces, zeroes, num);
}


