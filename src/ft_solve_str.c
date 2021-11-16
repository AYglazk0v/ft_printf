/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:43:50 by gtaggana          #+#    #+#             */
/*   Updated: 2021/11/16 12:43:52 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void	ft_solve_str_continue(t_mix_tf *mix, char *str)
{
	mix->width++;
	if (mix->m_flags[1] == 1)
	{
		ft_pf_putstr(str);
		mix->width -= ft_pf_strlen(str);
		while (--mix->width > 0)
			ft_pf_putchr(' ');
	}
	else
	{
		mix->width -= ft_pf_strlen(str);
		while (--mix->width > 0)
			ft_pf_putchr(' ');
		ft_pf_putstr(str);
	}
}

void	ft_solve_str(t_mix_tf *mix)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(mix->vl, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (mix->dimension == 0 && mix->dot == 0)
	{
		str = ft_pf_create_str(ft_pf_strlen(tmp));
		str = ft_pf_strcpy(str, tmp);
	}
	else
	{
		str = ft_pf_create_str(mix->dimension);
		str = ft_pf_strncpy(str, tmp, mix->dimension);
	}
	ft_solve_str_continue(mix, str);
	free(str);
}
