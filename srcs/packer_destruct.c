/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packer_destruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:09:26 by marene            #+#    #+#             */
/*   Updated: 2017/01/26 16:08:17 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

void		packer_destruct(t_packer *woody)
{
	woody->magic = 0;
	if (woody->fileName != NULL)
	{
		free(woody->fileName);
		woody->fileName = NULL;
	}
	if (woody->fd != -1)
	{
		close(woody->fd);
		woody->fd = -1;
	}
	if (woody->data != MAP_FAILED)
	{
		munmap(woody->data, woody->st_size);
		woody->data = MAP_FAILED;
		woody->st_size = 0;
	}
}
