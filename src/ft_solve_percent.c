#include "../inc/ft_printf.h"

void	ft_solve_percent(t_mix_tf *mix)
{
	mix->width++;
	if (mix->m_flags[1] == 1)
	{
		ft_pf_putchr('%');
		if (mix->m_flags[3] != 1)
			while (--mix->width > 1)
				ft_pf_putchr(' ');
	}
	else
	{
		if (mix->m_flags[3] == 1)
			while (--mix->width > 1)
				ft_pf_putchr('0');
		ft_pf_putchr('%');
	}
}
