/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 23:26:59 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 20:27:15 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_len(char *str, int len)
{
	int i;

	i = 0;
	while (len)
	{
		ft_putchar(*str);
		str++;
		i++;
		len--;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*r;
	int		i;
	int		j;
	char	*h;

	i = 0;
	h = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	if (!(r = (char *)malloc(sizeof(char) * (j + 1))))
		return (0);
	while (i < j)
	{
		r[i] = s1[i];
		i++;
	}
	r[j] = '\0';
	h = r;
	free(r);
	return (h);
}

void	ft_ini_flags(t_flag *flags)
{
	flags->option = 'x';
	flags->width = 0;
	flags->precision = -1;
	flags->conversion = '0';
}

int		ft_help4_d(t_flag *flags, int d, int l, int c)
{
	int total;

	total = 0;
	if (d < 0)
	{
		d *= -1;
		flags->precision += 1;
		total += ft_putchar('-');
	}
	total += print_spaces('0', l, flags->precision);
	total += ft_putstr(ft_itoa(d));
	total += print_spaces(c, flags->precision, flags->width);
	return (total);
}
