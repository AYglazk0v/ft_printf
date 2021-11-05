#ifndef PRINTF_H
# define PRINTF_H
# define BASE10 "0123456789"
# define BASE16 "0123456789ABCDEF"
# define LBASE16 "0123456780abcdef"
# define FLAGS "+-#0 "
# define TYPES "cspiduxX%"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_mix_tf
{
	size_t	pos_end;
	int		m_flags[5];
	int		m_types[8];
	int		dot;
	int		status;
	va_list	vl;
	int		width;
	int		dimension;
}				t_mix_tf;

int		ft_pf_isdigit(char c);
int		ft_chek_type(t_mix_tf *mix);
int		ft_cnt_print(int key);
char	*ft_pf_strchr(char *string, char symbol);

//support_func.c 
char	*ft_create_str(size_t size);
int		ft_pf_strlen(const char	*s);
char	*ft_pf_strcpy(char *dst, const char *src);
char	*ft_pf_strncpy(char *dst, const char *src, size_t len);

void	ft_get_param(t_mix_tf *mix, const char *src, size_t	start);
void	ft_solve_char(t_mix_tf *mix);
void	ft_solve_str(t_mix_tf *mix);
void	ft_solve_str_continue(t_mix_tf *mix, char *str);
void	ft_solve_percent(t_mix_tf *mix);

void	ft_porcess_mix(t_mix_tf *mix);
void	ft_pf_putchr(char c);
void	ft_pf_putnbr(void *src, char *base, long long int s_base, int len);
void	ft_pf_putstr(char *s);
#endif
