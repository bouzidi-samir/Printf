/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_width(char c, t_struct *list)
{
	if (c == '.' && list->precision == 0)
		list->precision++;
	else if (c == '.' && list->precision > 0)	
		return (-1);
	if (c == '0' && list->width == 0 && list->precisionlen == 0)
		list->zero++;
	else if (c >= '0' && c <= '9')
	{	
		if (list->precision == 0)
		list->width = list->width * 10 + (c - 48);
		else
		list->precisionlen = list->precisionlen * 10 + (c - 48);
	}
	return (0);
}

int	check_empty(t_struct *list)
{
	if (list->width > 0 && list->precision > 0)
		return (1);
	else
		return (0);
}

int	parse_indicateur(char c, t_struct *list)
{
	if (c == '-' && !check_empty(list))
		list->moins++;
	else if (c == '-' && check_empty(list))  
		return (0);
	if (c == '+' && !check_empty(list) && list->space == 0)
		list->plus++;
	else if (c == '+' && check_empty(list) && list->space > 0)
		return (0);
	if (c == ' ' && !check_empty(list) && list->plus == 0)
		list->space++;
	else if (c == ' ' && check_empty(list) && list->plus > 0)
		return (0);
	if (c == '#' && !check_empty(list) && list->space == 0)
	       	list->diez++;	
	else if(c == '#' && check_empty(list) && list->space > 0)
		return (0);

	return (1);
}

void	parse_convert(char c, t_struct *list, va_list ap)
{
	if (c == 'c')
		conv_char(ap, list);
	else if (c == 's')
		conv_str(ap, list);
	else if (c == 'p')
		conv_point(ap, list);
	else if (c == 'd' || c == 'i')
		conv_int(ap, list);
//	else if (c == 'u')
//		conv_unint(ap, list);
	else if (c == 'x' || c == 'X')
		conv_hexa(ap, list, &c);
//	else if (c == '%')
//		ft_putchar_fd('%', 1);
//		list->nprinted++;
}