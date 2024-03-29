/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:43:26 by gtaggana          #+#    #+#             */
/*   Updated: 2021/11/16 12:43:30 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_solve_char(t_mix_tf *mix)
{
	char	ch;

	mix->width++;
	if (mix->m_flags[1] == 1)
	{
		ch = ' ';
		ft_pf_putchr(va_arg(mix->vl, int));
		if (mix->width > 1)
			while (--mix->width > 1)
				ft_pf_putchr(ch);
	}
	else if (mix->m_flags[1] == 0)
	{
		if (mix->m_flags[3] == 1)
			ch = '0';
		else
			ch = ' ';
		if (mix->width > 1)
			while (--mix->width > 1)
				ft_pf_putchr(ch);
		ft_pf_putchr(va_arg(mix->vl, int));
	}
}
