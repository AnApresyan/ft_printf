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

#ifndef FTPRINTF_H
# define FTPRINTF_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

struct s_flags
{
	int minus;
	int zero;
	int minWidth;
	int period;
	int precision;
	int count;
	void *arg;
} t_flags;

void	ft_printf_char();
int 	ft_numlength(int num);
void 	ft_check_minus(char **f);
int		ft_atoi2(char **str);
int 	calculateSpaces(int len);
int 	calculateZeroes(int len);
int 	hexalength(int decimal);
void 	hexaConversion(unsigned int decimal, char letter);
void 	checkHexaZero(unsigned int decimal, char letter);
void 	ft_printf_hexa(char letter);
void 	ft_printf_int();
void 	ft_putnbrUnsigned_fd(unsigned int n, int fd);
int 	ft_unsignedLength(unsigned int num);
void 	ft_printf_unsignedInt();
void 	ft_check_type(char **format);
void 	updateStruct();
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int s, int fd);
int		ft_printf(const char *f, ...);


#endif
