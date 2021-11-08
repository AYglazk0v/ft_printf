#include "../inc/printf.h"

static char	*case_1(char *str, t_mix_tf *mix, int i)
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
	if (i >= 0 && mix->m_flags[0] == 0 && mix->m_flags[4] == 1)
		ft_pf_putchr(' ');
	return (str);
}

static void	case_2(char *str, t_mix_tf *mix, int i)
{
	if (i >= 0 && mix->m_flags[0] == 1)
		ft_pf_putchr('+');
	if (i < 0)
		ft_pf_putchr('-');
	ft_pf_putstr(str);
	mix->width -= ft_pf_strlen(str);
	while (mix->width-- > 0)
		ft_pf_putchr(' ');
}

static void	case_3(char *str, t_mix_tf *mix, int i)
{
	mix->width -= ft_pf_strlen(str);
	while ((mix->width > 0 && mix->m_flags[3] == 0)
		|| (mix->width > 0 && mix->m_flags[3] == 1 && mix->dimension > 0))
	{
		ft_pf_putchr(' ');
		mix->width--;
	}
	if (i >= 0 && mix->m_flags[0] == 1)
		ft_pf_putchr('+');
	else if (i < 0)
		ft_pf_putchr('-');
	while (mix->width-- > 0 && mix->m_flags[3] == 1)
		ft_pf_putchr('0');
	ft_pf_putstr(str);
}

static void	case_4(char *str, t_mix_tf *mix, int i)
{
	if (i >= 0 && mix->m_flags[0] == 1)
		ft_pf_putchr('+');
	else if (i < 0)
		ft_pf_putchr('-');
	ft_pf_putstr(str);
}

void	ft_solve_di(t_mix_tf *mix)
{
	int		i;
	int		len_s;
	char	*str;

	i = va_arg(mix->vl, int);
	len_s = ft_len_int_base(i, 10);
	str = (char *)malloc(sizeof(char) * len_s + 2);
	ft_convert2str(str, i, len_s, BASE10);
	str[len_s + 1] = '\0';
	if (mix->dimension == 0 && mix->dot == 1 && i == 0)
	{
		while (mix->width-- > 0)
			ft_pf_putchr(' ');
		free(str);
	}
	str = case_1(str, mix, i);
	if (mix->width > 0 && mix->m_flags[1] == 1)
		case_2(str, mix, i);
	else if (mix->width > 0 && mix->m_flags[1] == 0)
		case_3(str, mix, i);
	else
		case_4(str, mix, i);
	free(str);
}
