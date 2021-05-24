/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:47:04 by aapresya          #+#    #+#             */
/*   Updated: 2021/05/24 22:06:51 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_caclulatestringspaces(int len)
{
	int spaces;

	if (t_flags.period)
	{
		if (t_flags.precision < len)
			spaces = t_flags.minwidth - t_flags.precision;
		else
			spaces = t_flags.minwidth - len;
	}
	else
		spaces = t_flags.minwidth - len;
	return (spaces);
}

void	ft_helper_string(int len)
{
	if (t_flags.period)
	{
		while (t_flags.precision-- > 0 && len-- > 0)
			ft_putchar_fd(*(char *)t_flags.arg++, 1);
	}
	else
	{
		while (len-- > 0)
			ft_putchar_fd(*(char *)t_flags.arg++, 1);
	}
}

void	ft_spaces(int spaces)
{
	while (spaces-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_printf_string(void)
{
	int	spaces;
	int	len;

	if (t_flags.precision < 0)
	{
		t_flags.precision = 0;
		t_flags.period = 0;
	}
	if (!t_flags.arg)
		t_flags.arg = "(null)";
	len = ft_strlen((char *)t_flags.arg);
	spaces = ft_caclulatestringspaces(len);
	if (t_flags.minus)
	{
		ft_helper_string(len);
		ft_spaces(spaces);
	}
	else
	{
		ft_spaces(spaces);
		ft_helper_string(len);
	}
}
