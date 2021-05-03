/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/17 11:47:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TYPESFLAGS "cspdiuxX%#-+.*0123456789"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_struct
{
	char		*str;
	int		nprinted;
	int		zero;
	int		moins;
	int		plus;
	int		space;
	int		diez;
	int		width;
	int		precisionlen;
	int		precision;
	int		star;
}			t_struct;

int	ft_printf(const char *str, ...);
int	check_input(const char *str, t_struct *list, va_list ap);
void	init_list(t_struct *list);
int	parse_indicateur(char c, t_struct *list);
int	check_empty(t_struct *list);
int	parse_width(char c, t_struct *list);
void	parse_convert(char c, t_struct *list, va_list ap);
void	conv_char(va_list ap, t_struct *list);
void	conv_point(va_list ap, t_struct *list);
void	conv_int(va_list ap, t_struct *list);
void	conv_str(va_list ap, t_struct *list);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strrchrp(const char *s, char c);
char	*ft_itoa(int n);
int	ft_strlenp(const char *s); 

#endif
