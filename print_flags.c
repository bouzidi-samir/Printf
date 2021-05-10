/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_precision(t_struct *list, char *conv)
{
	int	i;
	int	s;

	i = 0;
	s = list->precisionlen - ft_strlen(conv);
	if (s < 0)
		s = 0;
	if (list->precisionlen > 0)
		{
			while (i < s)
			{
				list->nprinted += write(1, "0", 1);
				i++;
			}	
		}
}

void	print_width(t_struct *list, char *conv, int neg)
{
	int	i;
	int	prec;
	int	s1;

	i = 0;
	prec = list->precisionlen - ft_strlen(conv);
	if (prec < 0)
		prec = 0;
	s1 = list->width - ft_strlen(conv) - prec - neg;
	while (i < s1)
	{
		if(list->zero > 0 && list->precision == 0)
			list->nprinted += write(1, "0", 1);
		else
			list->nprinted += write(1, " ", 1);
		i++;
	}
}

void	print_hexa(t_struct *list, char c)
{

	if (list->diez > 0)
	{
		if (c == 'x')
		{
			ft_print_fd("0x", 2, list);
		}
		else if (c == 'X')
		{
			ft_print_fd("0X", 2, list);
		}
	}
}






