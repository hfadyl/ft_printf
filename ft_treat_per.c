/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfadyl <hfadyl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:14:10 by hfadyl            #+#    #+#             */
/*   Updated: 2020/01/20 17:32:18 by hfadyl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_per(t_flag *flags)
{
	int		total;
	char	c;

	c = (flags->option == '0' ? '0' : ' ');
	total = 0;
	if (flags->width >= 0)
	{
		if (flags->option == '-')
		{
			total += ft_putchar('%');
			total += print_spaces(c, 1, flags->width);
		}
		if (flags->option != '-')
		{
			total += print_spaces(c, 1, flags->width);
			total += ft_putchar('%');
		}
	}
	else
		total += ft_putchar('%');
	return (total);
}
