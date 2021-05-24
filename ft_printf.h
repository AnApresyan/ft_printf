/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:43:52 by aapresya          #+#    #+#             */
/*   Updated: 2021/03/06 19:20:17 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

struct	s_flags
{
	int		minus;
	int		zero;
	int		minwidth;
	int		period;
	int		precision;
	int		count;
	void	*arg;
}		t_flags;

void	ft_printf_char();
int		ft_numlength(int num);
void	ft_check_minus(char **f);
int		ft_atoi2(char **str);
int		calculatespaces(int len);
int		calculatezeroes(int len);
int		hexalength(int decimal);
void	hexaconversion(unsigned int decimal, char letter);
void	checkhexazero(unsigned int decimal, char letter);
void	ft_printf_hexa(char letter);
void	ft_printf_int();
void	ft_putnbrunsigned_fd(unsigned int n, int fd);
int		ft_unsignedlength(unsigned int num);
void	ft_printf_unsignedint();
void	ft_printf_pointer();
int		addresslength(size_t decimal);
void	pointerconversion(size_t decimal);
void	checkaddresszero(size_t decimal);
void	ft_helper_p(int spaces, int zeroes, size_t decimal);
void	ft_printf_pointer();
void	ft_print_percent();
void	ft_helper_percent(int spaces, int zeroes);
void	ft_printf_string();
int		ft_caclulatestringspaces(int len);
void	ft_helper_string(int len);
void	ft_spaces(int spaces);
void	ft_helper_printf(char **format, va_list args);
void	ft_check_type(char **format);
void	updatestruct();
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int s, int fd);
int		ft_printf(const char *f, ...);

#endif
