/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:55:19 by aapresya          #+#    #+#             */
/*   Updated: 2021/05/23 09:38:09 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_printf_char(){
	if (t_flags.minus)
	{
		ft_putchar_fd((char)t_flags.arg, 1);
		while (t_flags.minWidth-- > 1)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (t_flags.minWidth-- > 1)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd((char)t_flags.arg, 1);
	}
}
