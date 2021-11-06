#include "printf.h"

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
