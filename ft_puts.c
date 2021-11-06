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
