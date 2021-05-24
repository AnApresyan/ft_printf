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

void ft_check_minus(char **f)
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

int	ft_atoi2(char **str)
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

/*void ft_printf_string()
{
	int spaces;

	if (t_flags.period)
	{
		if (t_flags.precision < ft_strlen((char *)t_flags.arg))
			spaces = t_flags.minWidth - t_flags.precision;
		else
			spaces = t_flags.minWidth - ft_strlen((char *)t_flags.arg);
	}
	else
		spaces = t_flags.minWidth - ft_strlen((char *)t_flags.arg);
	if (t_flags.minus)
	{
		while (t_flags.precision-- > 0 && (char *)t_flags.arg)
			ft_putchar_fd(*(char *)t_flags.arg++, 1);
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
		while (t_flags.precision-- > 0 && (char *)t_flags.arg)
			ft_putchar_fd(*(char *)t_flags.arg++, 1);
	}
}*/

void ft_check_type(char **format){
	if (*(*format) == 'c')
		ft_printf_char();
	// else if (*(*format) == 's')
	// 	ft_printf_string();
	else if (*(*format) == 'p')
		ft_printf_pointer();
	else if (*(*format) == 'd' || *(*format) == 'i')
		ft_printf_int();
	else if (*(*format) == '%')
		ft_print_percent();
	else if (*(*format) == 'u')
		ft_printf_unsignedInt();
	else if (*(*format) == 'x')
		ft_printf_hexa('x');
	else if (*(*format) == 'X')
		ft_printf_hexa('X');
	(*format)++;	
}

void updateStruct(){
	t_flags.minus = 0;
	t_flags.zero = 0;
	t_flags.minWidth = 0;
	t_flags.period = 0;
	t_flags.precision = 0; 
}

 int	ft_printf(const char *f, ...){
	char 	*format;
	va_list	args;

	format = (char *)f;
	va_start(args, f);
	while (*format)
	{
		if (*format == '%' && *(++format) != '%')
		{
			updateStruct();
			ft_check_minus(&format);
			if (*format >= '0' && *format <= '9')
				t_flags.minWidth = ft_atoi2(&format);
			if (*format == '*')
			{
				t_flags.minWidth  = va_arg(args, int);
				if (t_flags.minWidth < 0)
				{
					t_flags.minWidth *= -1;
					t_flags.minus = 1;
					t_flags.zero = 0;
				}
				format++;
			}
			if (*format == '.'){
				t_flags.period = 1;
				format++;
				if (*format >= '0' && *format <= '9')
					t_flags.precision = ft_atoi2(&format);
				else if (*format == '*')
				{
					t_flags.precision = va_arg(args, int);
					format++;
				}
			}
			t_flags.arg = va_arg(args, void *);
			ft_check_type(&format);
		}
		else{
			ft_putchar_fd(*format, 1);//write(1, &(*format), 1);
			format++;
		}	
	}
	va_end(args);
	return t_flags.count;
}


//gcc -L. -lftprintf *.c && ./a.out



// int		main()
// {
// 	// int		i;
// 	// size_t	t;

// 	// i = 0;

// 	// t = (size_t)&i;
// 	// printf("%p\n", &i);
// 	// printf("0x%zx\n", t);
// 	//printf("%5.0x|\n", 0);
// 	// printf(" *%*.*d* *%*.*d* \n", -6, 2, 102, 10, 21, 101);
// 	// ft_printf(" *%*.*d* *%*.*d* ", -6, 2, 102, 10, 21, 101);

// 	// printf(" 0*%-*.10d*0 0*%-*.0d*0 |\n", 21, 1021, 21, -1011);
// 	// ft_printf(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011);

// 	// printf("%-*.0d*0\n", 21, -1011);
// 	// // printf("-----hhhhhhhhhhhhhhhh");
// 	// ft_printf("%-*.0d*0", 21, -1011);
// 	//printf("%1.d", 0);
// 	// int j = 68;

// 	// printf("%p", &j);
// 	// //printf("--------------------");
// 	ft_printf(" %10p %10p \n", 1, -1);
// 	printf(" %10p %10p ", 1, -1);
// 	// TEST(16, print(" --0*%0*.0d*0 0*%0*.10d*0-- ", -2, 0, 21, 1));
// 	// TEST(17, print(" --0*%0*.0d*0 0*%0*.10d*0-- ", -21, INT_MAX, 21, INT_MIN));
// 	// TEST(18, print(" --0*%0*.0d*0 0*%0*.10d*0-- ", -21, LONG_MAX, 21, LONG_MIN));



// 	//ft_printf("%8.15s", "Hello");
// }