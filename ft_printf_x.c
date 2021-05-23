/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 09:37:58 by aapresya          #+#    #+#             */
/*   Updated: 2021/05/23 09:37:59 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int hexalength(int decimal){
  	int length;

  	length = 0;
  	if((decimal) >= 0)
  	{
		if (decimal == 0)
		{
			if (t_flags.period && t_flags.precision == 0)
				length = 0;
			else
				length = 1;
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
    	return 8;
  	return length;
}

void hexaConversion(unsigned int decimal, char letter)
{

    if (decimal >= 16)
      hexaConversion(decimal / 16, letter);
    if ((decimal % 16) >= 10)
    {
      if (letter == 'x')
        ft_putchar_fd((decimal % 16) + 87, 1);
      else if (letter == 'X')
       ft_putchar_fd((decimal % 16) + 55, 1);
    }
    else
      ft_putchar_fd(decimal % 16 + '0', 1);

}

void checkHexaZero(unsigned int decimal, char letter)
{
	if (decimal == 0)
		ft_putchar_fd('0', 1);
	else
		hexaConversion(decimal, letter);
}

void ft_helper_x(int spaces, int zeroes, int decimal, char letter)
{
	if (!t_flags.minus)
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(decimal == 0 && t_flags.precision == 0 && t_flags.period))
			checkHexaZero(decimal, letter);
	}
	else
	{
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		if (!(decimal == 0 && t_flags.precision == 0 && t_flags.period))
			checkHexaZero(decimal, letter);
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	}			
}

void ft_printf_hexa(char letter){
	unsigned int decimal;
	int zeroes;
	int spaces;

	decimal = (unsigned int)t_flags.arg;
	spaces = calculateSpaces(hexalength(decimal));
	zeroes = calculateZeroes(hexalength(decimal));
	if (t_flags.zero && t_flags.precision == 0 && !t_flags.period)
	{
		zeroes += spaces;
		spaces = 0;
	}
	//if (decimal >= 0)
	ft_helper_x(spaces, zeroes, decimal, letter);
}


