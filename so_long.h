#ifndef SO_LONG_H
# define SO_LONG_H

#include "libraries/minilibx-linux/mlx.h"
#include "libraries/ft_printf/ft_printf.h"
#include "libraries/libft/libft.h"

int		ft_printf(const char *format, ...);

int		ft_handle_format(char c, va_list args);

int		ft_handle_char(va_list args);
int		ft_handle_str(va_list args);
int		ft_handle_digit(va_list args);
int		ft_handle_unsigned(va_list args);
int		ft_handle_hex(va_list args, const char *base);
int		ft_handle_ptr(va_list args);

int		ft_print_char(char c);
int		ft_print_str(const char *str);
int		ft_print_digit(const char *str);

char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_uitoa_base(unsigned int n, const char *base_str);
char	*ft_ulltoa_base(unsigned long long n, const char *base_str);

#endif
