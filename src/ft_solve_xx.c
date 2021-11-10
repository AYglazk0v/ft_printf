#include "../inc/ft_printf.h"

static char	*case_1(char *str, t_mix_tf *mix, unsigned int x)
{
	char	*tmp;

	if (mix->m_flags[2] == 1 && x != 0 && mix->m_types[6])
		ft_pf_putstr("0x");
	if (mix->m_flags[2] == 1 && x != 0 && mix->m_types[7])
		ft_pf_putstr("0X");
	if (mix->m_flags[2] == 1)
		mix->width -= 2;
	if (mix->dimension > 0)
	{
		while (mix->dimension > ft_pf_strlen(str))
		{
			tmp = ft_pf_strdup(str);
			free(str);
			str = ft_pf_strjoin ("0", tmp);
		}
	}
	return (str);
}

static void	case_2(char *str, t_mix_tf *mix, unsigned int x)
{
	if (mix->m_flags[2] == 1 && x !=0 && mix->m_types[6])
		ft_pf_putstr("0x");
	if (mix->m_flags[2] == 1 && x != 0 && mix->m_types[7])
		ft_pf_putstr("0X");
	if (mix->m_flags[2] == 1)
		mix->width -= 2;
	ft_pf_putstr(str);
	mix->width -= ft_pf_strlen(str);
	while (mix->width-- > 0)
		ft_pf_putchr(' ');
}

static void	case_3(char *str, t_mix_tf *mix, unsigned int x)
{
	if (mix->m_flags[2] == 1 && x != 0)
		mix->width -= 2;
	mix->width -= ft_pf_strlen(str);
	while ((mix->width > 0 && mix->m_flags[1] == 0 && mix->m_flags[3] == 0)
		|| (mix->width > 0 && mix->m_flags [1] == 1 && mix->dot == 1))
	{
		ft_pf_putchr(' ');
		mix->width--;
	}
	if (mix->m_flags[2] == 1 && x != 0 && mix->m_types[6])
		ft_pf_putstr("0x");
	if (mix->m_flags[2] == 1 && x != 0 && mix->m_types[7])
		ft_pf_putstr("0X");
	while (mix->width-- > 0 && mix->m_flags[3] == 1 && mix->dot == 0)
		ft_pf_putchr('0');

	ft_pf_putstr(str);
}

void	ft_solve_xx(t_mix_tf *mix)
{
	unsigned int	x;
	char			*str;
	int				len_s;

	x = va_arg(mix->vl, unsigned int);
	len_s = ft_len_int_base(x, 16);
	str = (char *)malloc(sizeof(char) * len_s + 2);
	if (mix->m_types[6] == 1)
		ft_convert2str(str, x, len_s, LBASE16);
	else
		ft_convert2str(str, x, len_s, BASE16);
	str[len_s + 1] = '\0';
	if (mix->dimension > 0 && mix->dot == 1 && x == 0)
		while (mix->width-- > 0)
			ft_pf_putchr(' ');
	str = case_1(str, mix, x);
	if (mix->width > 0 && mix->m_flags[1] == 1)
		case_2(str, mix, x);
	else if (mix->width > 0 && mix->m_flags[1] == 0)
		case_3(str, mix, x);
	else
		ft_pf_putstr(str);
	free(str);
}
