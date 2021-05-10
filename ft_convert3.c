/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtoupper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

/*void	conv_unint(va_list ap, t_struct *list)
{
	unsigned long long	arg;
	char	*conv;

	conv = NULL;
	arg = va_arg(ap, unsigned int);
	conv = ft_u_itoa(arg);
	list->nprinted += ft_strlen(conv);
	ft_putstr_fd(conv, 1);
}*/

void	conv_hexa(va_list ap, t_struct *list, char *c)
{
	unsigned long long	arg;
	char	*conv;
	int	neg;
	int size;
	
	neg = 0;
	arg = va_arg (ap, unsigned int);
	if (arg == 0)
		conv = ft_strdup("0");
	else
		conv = ft_hexad(arg);
	if (*c == 'x')
		conv = ft_strtolower(conv);
	else
		conv = ft_strtoupper(conv);
	size = ft_strlen(conv);
	print_hexa(list, *c);
	ft_print_fd(conv, size, list);
	free(conv);
}






