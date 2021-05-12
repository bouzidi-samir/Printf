/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlenp(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchrp(const char *s, char c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
		{	
			return (str + i);
		}
		i--;
	}
	if (s[i] == '\0' && c == '\0')
		return (str + i);
	return (NULL);
}

void	ft_print_fd(char *conv, int size, t_struct *list)
{
	int i;

	i = 0;

	while (conv[i] && i <= size)
	{
		list->nprinted += write(1, &conv[i], 1);
		i++;
	}
}

int	conv_x(va_list ap, t_struct *list, char *c)
{
	unsigned long long	arg;
	char	*conv;
	int	neg;
	int size;
	
	conv = NULL;
	neg = 0;
	if (list->star > 0 && list->width == 0)
		list->width = va_arg(ap, int);
	if (list->star > 0 && list->precisionlen == 0)
		list->precisionlen = va_arg(ap, int);
	arg = va_arg (ap, unsigned int);
	if (arg == 0 && list->precision > 0 && list->precisionlen == 0)
		return (-1);
	if (arg == 0)
		conv = ft_strdup("0");
	else
		conv = ft_hexad(arg);
	if (*c == 'x')
		conv = ft_strtolower(conv);
	else
		conv = ft_strtoupper(conv);
	size = ft_strlen(conv);
	print_int(list, conv, neg, size);
	free(conv);
	return (0);
}

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












