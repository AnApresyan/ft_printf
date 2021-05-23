/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 09:38:24 by aapresya          #+#    #+#             */
/*   Updated: 2021/05/23 09:38:26 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int calculateSpaces(int len)
{
	if (t_flags.precision > len)
		return t_flags.minWidth - t_flags.precision;
	else 
		return t_flags.minWidth - len;	
}

int calculateZeroes(int len)
{
	if (t_flags.precision)
		return t_flags.precision - len;
	else
		return 0;
}
