/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaggana <gtaggana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:44:09 by gtaggana          #+#    #+#             */
/*   Updated: 2021/11/16 12:44:10 by gtaggana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_pf_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_pf_strlen(const char	*s)
{
	int	n;

	n = 0;
	while (*(s + n))
		n++;
	return (n);
}

char	*ft_pf_create_str(size_t size)
{
	char	*new;
	size_t	len;

	len = size + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	while (len > 0)
	{
		new[len] = '\0';
		len--;
	}
	return (new);
}

char	*ft_pf_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_pf_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = -1;
	while ((src[++i]) && i < len)
		dst[i] = src[i];
	while (i < len)
		dst[i++] = '\0';
	dst[i] = '\0';
	return (dst);
}
