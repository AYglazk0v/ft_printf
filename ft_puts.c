#include "printf.h"

int	ft_cnt_print(int key)
{
	static int	counts;

	if (key == 0)
		counts = 0;
	else
		counts++;
	return (counts);
}

void	ft_pf_putchr(char c)
{
	write(1, &c, 1);
	ft_cnt_print(1);
}

void	ft_pf_putnbr(void *src, char *base, long long int s_base, int len)
{	
	long long int	num;

	num = 0;
	num = (long long int)src;
	if (num < 0)
	{
		if (s_base == 10)
			ft_pf_putchr('-');
		num = ~num + 1;
	}
	len--;
	if (num > 10 && len >= 0)
		ft_pf_putnbr((void *)(num / s_base), base, s_base, len);
	ft_pf_putchr(base[num % s_base]);
}

void	ft_pf_putstr(char *s)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_pf_putchr(*s);
		s++;
	}
}

char	*ft_pf_strchr(char *string, char symbol)
{
	while (*string)
	{
		if (*string == symbol)
			return (string);
		string++;
	}
	if (*string == symbol)
		return (string);
	return (NULL);
}
