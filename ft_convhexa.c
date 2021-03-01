/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convhexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 13:40:13 by hfadyl            #+#    #+#             */
/*   Updated: 2019/12/25 15:54:29 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned int nb)
{
	int		len;

	len = (nb == 0) ? 1 : 0;
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

char		*ft_convhexa(unsigned int nb, short maj)
{
	unsigned int	i;
	int				l;
	char			*str;
	char			*help;

	i = 0;
	l = len(nb);
	if (!(str = (char*)malloc(sizeof(char) * l + 1)))
		return (0);
	str[l] = '\0';
	while (--l >= 0)
	{
		i = nb % 16;
		if (i > 9)
			str[l] = (char)((maj == 1) ? (i + 55) : (i + 87));
		else
			str[l] = (char)(i + 48);
		nb = nb / 16;
	}
	help = str;
	free(str);
	return (help);
}
