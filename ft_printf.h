/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:13:57 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 21:09:46 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef struct	s_flag
{
	char		option;
	int			width;
	int			precision;
	char		conversion;
}				t_flag;

int				ft_printf(char *format, ...);
int				ft_princ(char *format, va_list arg, t_flag *flags);
size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_putchar(char c);
int				ft_print_conv(char *format, va_list arg);
char			*ft_itoa(int nb);
int				int_len(long int nb);
int				print_str(char *str);
int				ft_putstr(char *str);
int				ft_putstr_len(char *str, int len);
char			*ft_itoa_unsigned(unsigned int nb);
char			*ft_convhexa(unsigned int nb, short maj);
char			*ft_simple_p(unsigned long long nb);
int				ft_first_step(char *format, va_list arg, t_flag *flags,
								int *step);
void			ft_ini_flags(t_flag *flags);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_check_flag(char *format, va_list arg, t_flag *flags);
int				ft_help4_d(t_flag *flags, int d, int l, int c);
int				ft_treat_d(va_list arg, t_flag *flags);
int				ft_treat_s(va_list arg, t_flag *flags);
int				ft_treat_p(va_list arg, t_flag *flags);
int				ft_treat_u(va_list arg, t_flag *flags);
int				ft_treat_x(va_list arg, t_flag *flags, short maj);
int				ft_treat_c(va_list arg, t_flag *flags);
int				ft_treat_per(t_flag *flags);
int				print_spaces(char c, int len, int w);
char			*ft_strdup(const char *s1);
unsigned int	uni_len(unsigned int nb);
#endif
