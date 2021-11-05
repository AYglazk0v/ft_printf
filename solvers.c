#include "printf.h"

void	ft_solve_char(t_mix_tf *mix)
{
	char	ch;

    mix->width++;
	if (mix->m_flags[1] == 1)
	{
		ch = ' ';
		ft_pf_putchr(va_arg(mix->vl, char));
		if (mix->width > 1)
			while(--mix->width > 1)
				ft_pf_putchr(ch);
	}
	else if (mix->m_flags[1] == 0)
	{
		if (mix->m_flags[3] == 1)
			ch = '0';
		else
			ch = ' ';
		if (mix->width > 1);
			while(--mix->width > 1)
				ft_pf_putchr(ch);
		ft_pf_putchr(va_arg(mix->vl, char));
	}
}

void	ft_solve_str_continue(t_mix_tf *mix, char *str)
{
    mix->width++;
	if (mix->m_flags[1] == 1)
	{
		ft_pf_putstr(str);
		if (mix->width > ft_pf_strlen(str))
			while(--mix->width > ft_pf_strlen(str))
				ft_pf_putchr(' ');
	}
	else
	{
		if (mix->width > ft_pf_strlen(str))
			while(--mix->width > ft_pf_strlen(str))
				ft_pf_putchr(' ');
		ft_pf_putstr(str);
	}
	free(str);
}

void	ft_solve_str(t_mix_tf *mix)
{
	char	*str;
	char	*tmp;

	tmp = va_arg(mix->vl, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (mix->dimension == 0)
	{
		str = ft_create_str(ft_pf_strlen(tmp));
		str = ft_pf_strcpy(str, tmp);
	}
	else 
	{
		str = ft_pf_create_str(mix->dimension);
		str = ft_pf_strncpy(str, tmp, mix->dimension);
	}
	ft_solve_str_continue(mix, str);
}

void    ft_solve_point(t_mix_tf mix)
{

}

void    ft_solve_percent(t_mix_tf *mix)
{
    mix->width++;
    if (mix->m_flags[1] == 1)
    {
        ft_pf_putchr('%');
        if (mix->m_flags[3] != 1)
            while (--mix->width > 1)
                ft_pf_putchr(' ');
    }
    else
    {
        if (mix->m_flags[3] == 1)
           while (--mix->width > 1)
                ft_pf_putchr('0');
        ft_pf_putchr('%');
    }
}