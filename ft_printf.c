/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_list(t_struct *list)
{
	list->str = NULL;
	list->nprinted = 0;
	list->moins = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->diez = 0;
	list->width = 0;
	list->precisionlen = 0;
	list->precision = 0;
}

int	check_input(const char *str, t_struct *list, va_list ap)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%' && str[i])
			list->nprinted += write(1, &str[i], 1);
		else if (str[i] == '%')
		{	
			if (!ft_strrchr(TYPESFLAGS, str[i + 1]))
				return (-1);
			while (ft_strrchr(TYPESFLAGS, str[i + 1]))
			{
				i = i + 1;
				if (ft_strrchr("cspdiuxXfyb%", str[i]))
				{
					parse_convert(str[i], list, ap);
				//	init_list(list);
					break ;
				}
				else
					parse_width(str[i], list);
			}
		}
		i++;
	}
	return (list->nprinted);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_struct	list;	
	
	init_list(&list);
	va_start(ap, str);
//	check_input(str, &list, ap);
//	printf("%d", list.nprinted);
//	printf("%d", list.precisionlen);
	return (check_input(str, &list, ap));
	return (0);	
}

