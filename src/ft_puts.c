#include "../inc/ft_printf.h"

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
	while (s && *s)
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

char	*ft_pf_strdup(const char *str)
{
	char	*cpy;
	int		i;
	int		size;

	i = 0;
	size = 0;
	size = ft_pf_strlen(str);
	cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (cpy == NULL)
		return ((void *)0);
	while (size--)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
