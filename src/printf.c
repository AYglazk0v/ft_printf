/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:44:06 by gtaggana          #+#    #+#             */
/*   Updated: 2021/11/16 12:44:07 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int	ft_chek_type(t_mix_tf *mix)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (mix->m_types[i] != 0)
			return (i);
		i++;
	}
	return (0);
}

static void	ft_porcess_mix(t_mix_tf *mix)
{
	int	type;

	type = ft_chek_type(mix);
	if (type == 0)
		ft_solve_char(mix);
	else if (type == 1)
		ft_solve_str(mix);
	else if (type == 2)
		ft_solve_point(mix);
	else if (type == 3 || type == 4)
		ft_solve_di(mix);
	else if (type == 5)
		ft_solve_u(mix);
	else if (type == 6 || type == 7)
		ft_solve_xx(mix);
	else if (type == 8)
		ft_solve_percent(mix);
}

static void	ft_get_param(t_mix_tf *mix, const char *src, size_t	start)
{
	mix->pos_end = start;
	while (ft_pf_strchr(FLAGS, src[mix->pos_end]))
		mix->m_flags[ft_pf_strchr(FLAGS, src[mix->pos_end++]) - FLAGS] = 1;
	while (ft_pf_isdigit(src[mix->pos_end]))
		mix->width = mix->width * 10 + (src[mix->pos_end++] - '0');
	if (src[mix->pos_end] == '.')
	{
		mix->dot = 1;
		mix->pos_end++;
	}
	while (ft_pf_isdigit(src[mix->pos_end]))
		mix->dimension = mix->dimension * 10 + (src[mix->pos_end++] - '0');
	if (ft_pf_strchr(TYPES, src[mix->pos_end]))
	{
		mix->status = 1;
		mix->m_types[ft_pf_strchr(TYPES, src[mix->pos_end]) - TYPES] = 1;
	}
}

static size_t	ft_iniciation(t_mix_tf **mix)
{
	*mix = (t_mix_tf *)malloc(sizeof(t_mix_tf));
	ft_cnt_print(0);
	return (0);
}

int	ft_printf(const char *src, ...)
{
	size_t		pos_start;
	t_mix_tf	*mix;

	pos_start = ft_iniciation(&mix);
	va_start(mix->vl, src);
	while (src[pos_start])
	{
		ft_clean_mix(mix);
		if (src[pos_start] == '%')
		{
			ft_get_param(mix, src, ++pos_start);
			if (mix->status == 0)
				pos_start = ft_invalid_status(mix, --pos_start, src);
			else
			{
				ft_porcess_mix(mix);
				pos_start = mix->pos_end + 1;
			}
		}
		else
			ft_pf_putchr(src[pos_start++]);
	}
	va_end(mix->vl);
	free(mix);
	return (ft_cnt_print(1) - 1);
}
