/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packer_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:38:58 by marene            #+#    #+#             */
/*   Updated: 2017/02/02 18:41:48 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static void		packer_init_values(t_packer *woody)
{
	woody->fileName = NULL;
	woody->fd = -1;
	woody->magic = 0;
	woody->st_size = 0;
	woody->data = MAP_FAILED;
}

static void		packer_reinit(t_packer *woody, unsigned int flags)
{
	if ((flags & P_OPENED))
	{
		free(woody->fileName);
		woody->fileName = NULL;
		close(woody->fd);
		woody->fd = -1;
	}
	if ((flags & P_MAPPED))
	{
		munmap(woody->data, woody->st_size);
		woody->data = MAP_FAILED;
		woody->st_size = 0;
	}
}

int				packer_init(t_packer *woody, char *binFile)
{
	struct stat		buf;
	unsigned int	flags;

	flags = 0;
	packer_init_values(woody);
	if ((woody->fd = open(binFile, O_RDWR)) != -1)
	{
		flags |= P_OPENED;
		woody->fileName = ft_strdup(binFile);
		if (fstat(woody->fd, &buf) == 0)
		{
			woody->st_size = buf.st_size;
			if ((woody->data = mmap(NULL, buf.st_size, PROT_READ, MAP_PRIVATE, woody->fd, 0)) != MAP_FAILED)
			{
				flags |= P_MAPPED;
				woody->r_ptr = woody->data + sizeof(woody->header);
				woody->header = (struct mach_header_64*)woody->data;
				if (woody->header->magic == MH_MAGIC_64)
					return (WOODY_OK);
			}
		}
	}
	packer_reinit(woody, flags);
	return (WOODY_NOK);
}
