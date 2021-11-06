#include "printf.h"

static	int	ft_chek_type(t_mix_tf *mix)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (mix->m_types[i] != 0)
			retrun (0);
		i++;
	}
	return (0);
}

void	ft_porcess_mix(t_mix_tf *mix)
{
	int	type;

	type = ft_chek_type(mix);
	if (type == 0)
		ft_solv_char(mix);
	else if (type == 1)
		ft_solve_str(mix);
	else if (type == 2)
		ft_solve_point(mix);
	else if (type == 3 || type == 4 || type == 5)
		ft_solve_diu(mix);
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

int	ft_printf(const char *src, ...)
{
	size_t		pos_start;
	t_mix_tf	*mix;

	mix = (t_mix_tf *)malloc(sizeof(t_mix_tf));
	va_start(mix->vl, src);
	ft_cnt_print(0);
	pos_start = 0;
	while (src[pos_start])
	{
		ft_clean_mix(mix);
		if (src[pos_start] == '%')
		{
			ft_get_param(mix, src, ++pos_start);
			if (mix->status == 0)
				pos_start = ft_invalid_status(mix, --pos_start, src);
			else
				ft_porcess_mix(mix);
		}
		else
			ft_pf_putchr(src[pos_start++]);
	}
	va_end(mix->vl);
	free(mix);
	return (ft_cnt_print(1) - 1);
}
