/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func_continue.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:44:21 by gtaggana          #+#    #+#             */
/*   Updated: 2021/11/16 12:44:22 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_clean_mix(t_mix_tf *mix)
{
	int	l;

	l = 0;
	mix->pos_end = 0;
	mix->dot = 0;
	mix->status = 0;
	mix->width = 0;
	mix->dimension = 0;
	while (l++ < 5)
		mix->m_flags[l] = 0;
	l = 0;
	while (l++ < 8)
		mix->m_types[l] = 0;
}

size_t	ft_invalid_status(t_mix_tf *mix, size_t pos_start, const char *src)
{
	while (pos_start < mix->pos_end)
		ft_pf_putchr(src[pos_start++]);
	return (pos_start);
}

int	ft_len_int_base(long long num, long long s_base)
{
	int	l;

	l = 0;
	if (num < 0)
		num = ~num + 1;
	while (num >= s_base)
	{
		num = num / s_base;
		l++;
	}
	return (l);
}

void	ft_convert2str(char *str, long long int num, int size, char *base)
{
	int	s_base;

	s_base = ft_pf_strlen(base);
	if (num < 0)
		num = ~num + 1;
	if (num >= s_base)
		ft_convert2str(str, num / s_base, size - 1, base);
	str[size] = base[num % s_base];
}

char	*ft_pf_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!(s1 && s2))
		return (NULL);
	join = malloc(sizeof(char) * (ft_pf_strlen(s1) + ft_pf_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s2);
	return (join);
}
