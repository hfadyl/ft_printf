/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:40:55 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/21 14:34:09 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			int_len(long int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_zero(void)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*limit(char *src)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	i += 1;
	if (!(p = malloc(i * sizeof(char))))
		return (0);
	if (p == 0)
		return (0);
	while (src[j] != '\0')
	{
		p[j] = src[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

static void	ft_itoa1(int *nb, char *str, int *i)
{
	if (*nb < 0)
	{
		str[0] = '-';
		*nb = *nb * -1;
	}
	while (*nb > 0)
	{
		str[*i] = 48 + (*nb % 10);
		*nb = *nb / 10;
		(*i)--;
	}
}

char		*ft_itoa(int nb)
{
	char	*str;
	char	*help;
	int		i;

	if (nb == -2147483648)
		return (limit("-2147483648"));
	if (nb == 0)
		return (ft_zero());
	i = int_len(nb) + 1;
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (0);
	i -= 1;
	str[i] = '\0';
	i -= 1;
	ft_itoa1(&nb, str, &i);
	help = str;
	free(str);
	return (help);
}
