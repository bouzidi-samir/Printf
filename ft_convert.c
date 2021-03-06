/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"
void	conv_char(va_list ap, t_struct *list)
{
	char arg;

	arg = va_arg(ap, int);
	list->nprinted += write(1, &arg, 1);
}

int	conv_int(va_list ap, t_struct *list)
{
	int	arg;
	char	*conv;
	int size;
	int neg;
	
	neg = 0;
	conv = NULL;
	arg = va_arg(ap, int);
	if (arg == 0 && list->precision > 0 && list->precisionlen == 0)
		return (-1);
//	if (arg > UINT_MAX)	
//	{
		//arg *= -1;
		//neg = 1;
		//list->nprinted += write(1, "-", 1);
//	}
	if ((int)arg < 0)
	{
		neg = 1;
		arg *= -1;
//		list->nprinted += write(1, "-", 1);
	}
	conv = ft_itoa(arg);
	size = ft_strlen(conv);
	if(list->moins > 0)
	{
		if (neg == 1)
	    	list->nprinted += write(1, "-", 1);
		print_precision(list, conv);
		ft_print_fd(conv, size, list);
		print_width(list, conv, neg);
	}
	else if (list->moins == 0)
	{
	 	print_width(list, conv, neg);   
	    if (neg == 1)
	    	list->nprinted += write(1, "-", 1);
		print_precision(list, conv);
		ft_print_fd(conv, size, list);		
	}
free(conv);
		return (1);
}

void	conv_str(va_list ap, t_struct *list)
{
	char	*arg;
	int     size;
	arg = va_arg(ap, char*);
	size = ft_strlen(arg);
	ft_print_fd(arg, size, list);
}
