/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packer_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:29:12 by marene            #+#    #+#             */
/*   Updated: 2017/02/02 17:55:19 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

size_t		packer_read(t_packer *woody, void *data, size_t size)
{
	if (woody->r_ptr + size <= woody->data + woody->st_size)
	{
		ft_memcpy(data, woody->r_ptr, size);
		woody->r_ptr += size;
		return (size);
	}
	else
	{
		return (0);
	}
}
