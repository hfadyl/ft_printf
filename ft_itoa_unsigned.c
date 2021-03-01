/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:40:55 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/19 12:51:43 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		uni_len(unsigned int nb)
{
	unsigned int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char			*ft_zero(void)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char				*ft_itoa_unsigned(unsigned int nb)
{
	char			*str;
	char			*help;
	unsigned int	i;

	if (nb == 0)
		return (ft_zero());
	i = uni_len(nb) + 1;
	if (!(str = (char*)malloc(sizeof(char) * i)))
		return (0);
	i -= 1;
	str[i] = '\0';
	i -= 1;
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	help = str;
	free(str);
	return (help);
}
