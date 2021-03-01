/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:22:09 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/19 13:43:32 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_long(unsigned long long nb)
{
	unsigned long long		len;

	len = (nb == 0) ? 1 : 0;
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

char		*ft_simple_p(unsigned long long nb)
{
	unsigned long long	i;
	long				l;
	char				*str;
	char				*help;

	i = 0;
	l = len_long(nb);
	if (!(str = (char*)malloc(sizeof(char) * l + 3)))
		return (0);
	l += 2;
	str[l] = '\0';
	str[0] = '0';
	str[1] = 'x';
	while (--l >= 2)
	{
		i = nb % 16;
		if (i > 9)
			str[l] = (char)(i + 87);
		else
			str[l] = (char)(i + 48);
		nb = nb / 16;
	}
	help = str;
	free(str);
	return (help);
}
