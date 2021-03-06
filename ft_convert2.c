/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strrev(char *str)
{
	char	c;
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
}

char	*ft_hexad(unsigned long long nb)
{	
	char	*hexad;
	int	i;
	unsigned long long save_nb;
	char	*r;

	i = 0;
	hexad = ft_calloc(sizeof(char), 100);
	while (nb != 0)
	{
		save_nb = nb % 16;
		if (save_nb < 10)
			hexad[i++] = save_nb + 48;
		else
			hexad[i++] = save_nb + 55;
		nb /= 16;
	}
	ft_strrev(hexad);
	r = ft_strdup(hexad);
	free(hexad);
	return (r);
}

char	*ft_strtolower(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

void	conv_point(va_list ap, t_struct *list)
{
	unsigned long long point;
	char	*str;
	char	*stock;

	point = va_arg(ap, unsigned long long);
	str = ft_strtolower(ft_hexad(point));
	if (point == 0)
		stock = ft_strdup("0x0");
	else
		stock = ft_strjoin("0x",str);
	free(str);
	str = ft_strdup(stock);
	free(stock);
	ft_putstr_fd(str, 1);
	list->nprinted += (ft_strlen(str));
	free(str);
}
