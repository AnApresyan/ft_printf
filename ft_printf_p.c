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

int addressLength(size_t decimal){
  	int length;

  	length = 2;
  	if((decimal) >= 0)
  	{
		if (decimal == 0)
		{
			// if (t_flags.period && t_flags.precision == 0)
			// 	length = 0;
			// else
				length += 1;
		}
    	while(decimal != 0)
		{
			decimal /= 16;
			length++;
 		}
		if (t_flags.period && t_flags.precision == 0 && !t_flags.minWidth)
			return 0;
  	}
  	else
    	return length += 8;
  	return length;
}

void pointerConversion(size_t decimal)
{

    if (decimal >= 16)
      pointerConversion(decimal / 16);
    if ((decimal % 16) >= 10)
        ft_putchar_fd((decimal % 16) + 87, 1);
    else
      ft_putchar_fd(decimal % 16 + '0', 1);

}

void checkAddressZero(size_t decimal)
{
    ft_putchar_fd('0', 1);
    ft_putchar_fd('x', 1);
	if (decimal == 0)
        ft_putchar_fd('0', 1);
	else
		pointerConversion(decimal);
}

void ft_helper_p(int spaces, int zeroes, size_t decimal)
{
	if (!t_flags.minus)
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(decimal == 0 && t_flags.precision == 0 && t_flags.period))
			checkAddressZero(decimal);
	}
	else
	{
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(decimal == 0 && t_flags.precision == 0 && t_flags.period))
			checkAddressZero(decimal);
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	}			
}

void ft_printf_pointer(){
	int zeroes;
	int spaces;
    size_t address;

    address = (size_t)t_flags.arg;

	spaces = calculateSpaces(addressLength(address));
	zeroes = calculateZeroes(addressLength(address));
	if (t_flags.zero && t_flags.precision == 0 && !t_flags.period)
	{
		zeroes += spaces;
		spaces = 0;
	}
	ft_helper_p(spaces, zeroes, address);
}
