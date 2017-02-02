/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:04:18 by marene            #+#    #+#             */
/*   Updated: 2014/10/14 12:36:14 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	ft_putstr(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
}
