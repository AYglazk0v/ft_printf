#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE10 "0123456789"
# define BASE16 "0123456789ABCDEF"
# define LBASE16 "0123456789abcdef"
# define FLAGS "+-#0 "
# define TYPES "cspiduxX%"

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_mix_tf
{
	size_t	pos_end;
	int		m_flags[5];
	int		m_types[9];
	int		dot;
	int		status;
	va_list	vl;
	int		width;
	int		dimension;
}				t_mix_tf;

int	ft_printf(const char *src, ...);
//support_func.c 
int		ft_pf_isdigit(char c);
char	*ft_pf_create_str(size_t size);
int		ft_pf_strlen(const char	*s);
char	*ft_pf_strcpy(char *dst, const char *src);
char	*ft_pf_strncpy(char *dst, const char *src, size_t len);

//supp_continue
size_t	ft_invalid_status(t_mix_tf *mix, size_t pos_start, const char *src);
void	ft_clean_mix(t_mix_tf *mix);
int		ft_len_int_base(long long num, long long s_base);

void	ft_convert2str(char *str, long long int num, int size, char *base);
char	*ft_pf_strjoin(char *s1, char *s2);

void	ft_solve_char(t_mix_tf *mix);
void	ft_solve_str(t_mix_tf *mix);
void	ft_solve_percent(t_mix_tf *mix);
void	ft_solve_point(t_mix_tf *mix);
void	ft_solve_di(t_mix_tf *mix);
void	ft_solve_u(t_mix_tf *mix);
void	ft_solve_xx(t_mix_tf *mix);

//puts.c
char	*ft_pf_strchr(char *string, char symbol);
int		ft_cnt_print(int key);
void	ft_pf_putchr(char c);
void	ft_pf_putstr(char *s);
char	*ft_pf_strdup(const char *str);
#endif
