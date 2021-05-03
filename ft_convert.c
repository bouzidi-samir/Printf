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

void	parse_convert(char c, t_struct *list, va_list ap)
{
	if (c == 'c')
		conv_char(ap, list);
	else if (c == 's')
		conv_str(ap, list);
	else if (c == 'p')
		conv_point(ap, list);
	else if (c == 'd')
		conv_int(ap, list);

}

void	conv_char(va_list ap, t_struct *list)
{
	char arg;

	arg = va_arg(ap, int);
	write(1, &arg, 1);
	list->nprinted++;
}

void	conv_int(va_list ap, t_struct *list)
{
	int	arg;
	char *conv;

	conv = NULL;
	arg = va_arg(ap, int);
	conv = ft_itoa(arg);
	list->nprinted += ft_strlen(conv);
	ft_putstr_fd(conv, 1);
}

void	conv_str(va_list ap, t_struct *list)
{
	char	*arg;
	
	arg = va_arg(ap, char*);
	list->nprinted += ft_strlen(arg);
	ft_putstr_fd(arg, 1);
}
