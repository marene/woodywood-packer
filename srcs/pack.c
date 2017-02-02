/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:08:04 by marene            #+#    #+#             */
/*   Updated: 2017/02/02 19:23:07 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static int	get_next_load_command(t_packer *woody, struct load_command *lc)
{
	static uint32_t		i = 0;

	while (i < woody->header->ncmds)
	{
		// change this function
	}
}

int			pack(t_packer *woody)
{
	struct load_command		lc;

	while (get_next_load_command(woody, &lc) != WOODY_NOK)
	{
		
	}
	return 0;
}
