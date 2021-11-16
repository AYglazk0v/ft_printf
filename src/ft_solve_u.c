/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:43:54 by gtaggana          #+#    #+#             */
/*   Updated: 2021/11/16 13:34:10 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*case_1(char *str, t_mix_tf *mix)
{
	char	*tmp;

	if (mix->dimension > 0)
	{
		while (mix->dimension > ft_pf_strlen(str))
		{
			tmp = ft_pf_strdup(str);
			free(str);
			str = ft_pf_strjoin("0", tmp);
		}
	}
	mix->width -= ft_pf_strlen(str);
	while (mix->width > 0 && mix->m_flags[1] == 0)
	{
		ft_pf_putchr(' ');
		mix->width--;
	}
	ft_pf_putstr(str);
	while (mix->width-- > 0 && mix->m_flags[1] == 1)
		ft_pf_putchr(' ');
	return (str);
}

static void	case_2(char	*str, t_mix_tf *mix)
{
	ft_pf_putstr(str);
	mix->width -= ft_pf_strlen(str);
	while (mix->width-- > 0)
		ft_pf_putchr(' ');
}

static void	case_3(char	*str, t_mix_tf *mix)
{
	mix->width -= ft_pf_strlen(str);
	while ((mix->width > 0 && mix->m_flags[3] == 0)
		|| (mix->width > 0 && mix->dot == 1 && mix->m_flags[3] == 1))
	{
		ft_pf_putchr(' ');
		mix->width--;
	}
	while (mix->width > 0 && mix->m_flags[3] == 1
		&& mix->dot == 0)
	{
		ft_pf_putchr('0');
		mix->width--;
	}
	ft_pf_putstr(str);
}

void	ft_solve_u(t_mix_tf *mix)
{
	unsigned int	u_i;
	int				len_s;
	char			*str;

	u_i = va_arg(mix->vl, unsigned int);
	len_s = ft_len_int_base(u_i, 10);
	str = (char *)malloc(sizeof(char) * len_s + 2);
	ft_convert2str(str, u_i, len_s, BASE10);
	str[len_s + 1] = '\0';
	if (mix->dimension == 0 && mix->dot == 1 && u_i == 0)
		while (mix->width-- > 0)
			ft_pf_putchr(' ');
	else
	{
		if (mix->dimension > 0)
			str = case_1(str, mix);
		else if (mix->width > 0 && mix->m_flags[1] == 1)
			case_2(str, mix);
		else if (mix->width > 0 && mix->m_flags[1] == 0)
			case_3(str, mix);
		else
			ft_pf_putstr(str);
	}
	free(str);
}
