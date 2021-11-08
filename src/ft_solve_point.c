#include "../inc/printf.h"

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

void	ft_solve_point(t_mix_tf *mix)
{
	int				len_s;
	char			*str;
	unsigned long	p;

	p = va_arg(mix->vl, unsigned long);
	if (p == 0)
		case_1(mix);
	len_s = ft_len_int_base(p, 16);
	str = (char *)malloc(sizeof(char) * len_s + 2);
	ft_convert2str(str, p, len_s, LBASE16);
	str[len_s + 1] = '\0';
	if (mix->width > 0 && mix->m_flags[1] == 1)
		case_2(mix, str);
	else if (mix->width > 0 && mix->m_flags[1] == 0)
		case_3(mix, str);
	else
	{
		ft_pf_putstr("0x");
		ft_pf_putstr(str);
	}
	free(str);
}
