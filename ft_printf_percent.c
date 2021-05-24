#include "ft_printf.h"


void ft_helper_percent(int spaces, int zeroes)
{
	if (!t_flags.minus)
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		//if (!(num == 0 && t_flags.precision == 0 && t_flags.period))
			ft_putchar_fd('%', 1);
	}
	else
	{
		// if ((int)t_flags.arg < 0 && (int)t_flags.arg != -2147483648)
		// 	ft_putchar_fd('-', 1);
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
		//if (!(num == 0 && t_flags.precision == 0 && t_flags.period))
			ft_putchar_fd('%', 1);
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	}	
}

void ft_print_percent()
{
    int spaces;
	int zeroes;

	spaces = calculateSpaces(1);
	zeroes = calculateZeroes(1);
	if(t_flags.zero && t_flags.precision == 0 && !t_flags.period){
		zeroes += spaces;
		spaces = 0;
	}

	ft_helper_percent(spaces, zeroes);
}