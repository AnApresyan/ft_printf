/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:07:29 by aapresya          #+#    #+#             */
/*   Updated: 2021/03/12 14:08:11 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_minus(char **f)
{
	while (*(*f) == '-' || *(*f) == '0')
	{
		if (*(*f) == '-')
			t_flags.minus = 1;
		if (*(*f) == '0')
			t_flags.zero = 1;
		(*f)++;
	}
	if (t_flags.zero == 1 && t_flags.minus == 1)
		t_flags.zero = 0;
}

int		ft_atoi2(char **str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (**str == 32 || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + **str - '0';
		(*str)++;
	}
	return (sign * result);
}

void	ft_check_type(char **format)
{
	if (*(*format) == 'c')
		ft_printf_char();
	else if (*(*format) == 's')
		ft_printf_string();
	else if (*(*format) == 'p')
		ft_printf_pointer();
	else if (*(*format) == 'd' || *(*format) == 'i')
		ft_printf_int();
	else if (*(*format) == '%')
		ft_print_percent();
	else if (*(*format) == 'u')
		ft_printf_unsignedint();
	else if (*(*format) == 'x')
		ft_printf_hexa('x');
	else if (*(*format) == 'X')
		ft_printf_hexa('X');
	(*format)++;
}

void	ft_helper_printf(char **format, va_list args)
{
	if (*(*format) == '*')
	{
		t_flags.minwidth = va_arg(args, int);
		if (t_flags.minwidth < 0)
		{
			t_flags.minwidth *= -1;
			t_flags.minus = 1;
			t_flags.zero = 0;
		}
		(*format)++;
	}
	if (*(*format) == '.')
	{
		t_flags.period = 1;
		(*format)++;
		if (*(*format) >= '0' && *(*format) <= '9')
			t_flags.precision = ft_atoi2(format);
		else if (*(*format) == '*')
		{
			t_flags.precision = va_arg(args, int);
			(*format)++;
		}
	}
	t_flags.arg = va_arg(args, void *);
}

int		ft_printf(const char *f, ...)
{
	char	*format;
	va_list	args;

	format = (char *)f;
	va_start(args, f);
	while (*format)
	{
		if (*format == '%' && *(++format) != '%')
		{
			updatestruct();
			ft_check_minus(&format);
			if (*format >= '0' && *format <= '9')
				t_flags.minwidth = ft_atoi2(&format);
			ft_helper_printf(&format, args);
			ft_check_type(&format);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(args);
	return (t_flags.count);
}
