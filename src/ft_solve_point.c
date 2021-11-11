#include "../inc/ft_printf.h"

static void	case_1(t_mix_tf *mix)
{
	if (mix->m_flags[1] == 0)
	{
		if (mix->width > 3)
			while (mix->width-- > 3)
				ft_pf_putchr(' ');
		ft_pf_putstr("0x0");
	}
	else
	{
		ft_pf_putstr("0x0");
		if (mix->width > 3)
			while (mix->width-- > 3)
				ft_pf_putchr(' ');
	}
}

static void	case_2(t_mix_tf *mix, char *str)
{
	ft_pf_putstr("0x");
	ft_pf_putstr(str);
	mix->width -= ft_pf_strlen(str) + 2;
	while (mix->width-- > 0)
		ft_pf_putchr(' ');
}

static void	case_3(t_mix_tf *mix, char *str)
{
	mix->width -= ft_pf_strlen(str) + 2;
	while (mix->width-- > 0)
		ft_pf_putchr(' ');
	ft_pf_putstr("0x");
	ft_pf_putstr(str);
}

static char	*ft_p_convert2str(unsigned long long num, char *base)
{
	int					len_s;
	unsigned long long	temp;
	char				*str;

	len_s = 0;
	temp = num;
	while (temp >= 16)
	{
		temp /= 16;
		len_s++;
	}
	temp = len_s;
	str = (char *)malloc(sizeof(char) * len_s + 2);
	while (num > 0)
	{
		str[len_s--] = base[num % 16];
		num /= 16;
	}
	str[temp + 1] = '\0';
	return (str);
}

void	ft_solve_point(t_mix_tf *mix)
{
	char				*str;
	unsigned long int	p;

	p = va_arg(mix->vl, unsigned long int);
	if (p == 0)
		case_1(mix);
	str = ft_p_convert2str(p, LBASE16);
	if (mix->width > 0 && p != 0 && mix->m_flags[1] == 1)
		case_2(mix, str);
	else if (mix->width > 0 && p != 0 && mix->m_flags[1] == 0)
		case_3(mix, str);
	else if (p != 0)
	{
		ft_pf_putstr("0x");
		ft_pf_putstr(str);
	}
	free(str);
}
