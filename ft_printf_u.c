/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 09:37:43 by aapresya          #+#    #+#             */
/*   Updated: 2021/05/23 09:37:45 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrUnsigned_fd(unsigned int n, int fd)
{
	char a;
	if (n > 9)
	{
		ft_putnbrUnsigned_fd(n / 10, fd);
		ft_putnbrUnsigned_fd(n % 10, fd);
	}
	else
	{
		a = n + '0';
		ft_putchar_fd(a, 1); //write(fd, &a, 1); 
	}
}

int ft_unsignedLength(unsigned int num)
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

void ft_helper_unsigned(int spaces, int zeroes, unsigned int num)
{
	if (!t_flags.minus)
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(num == 0 && t_flags.precision == 0 && t_flags.period))
			ft_putnbrUnsigned_fd(num, 1);
	}
	else
	{
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(num == 0 && t_flags.precision == 0 && t_flags.period))
			ft_putnbrUnsigned_fd(num, 1);
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	}	
}

void ft_printf_unsignedInt(){
	int spaces;
	int zeroes;
	unsigned int num;
	
	spaces = calculateSpaces(ft_unsignedLength((unsigned int)t_flags.arg));
	zeroes = calculateZeroes(ft_unsignedLength((unsigned int)t_flags.arg));
	if(t_flags.zero && t_flags.precision == 0 && !t_flags.period)
	{
		zeroes += spaces;
		spaces = 0;
	}
	num = (unsigned int)t_flags.arg;
	if ((unsigned int)t_flags.arg < 0)
	{
		num *= -1;
		spaces--;
		if (spaces <= 0 && zeroes > 0 && t_flags.precision == 0)
			zeroes--;
	}
	ft_helper_unsigned(spaces, zeroes, num);
}
