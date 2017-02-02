/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:35:10 by marene            #+#    #+#             */
/*   Updated: 2017/02/02 16:41:33 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

int		main(int argc, char **argv)
{
	t_packer		woody;

	if (argc == 2)
	{
		if (packer_init(&woody, argv[1]) == WOODY_OK)
		{
			ft_putendl("packer initialized successfuly");
			pack(&woody);
		}
		else
		{
			packer_destruct(&woody);
			ft_putendl_fd("an error occured while initializing packer", 2);
		}
	}
	return (0);
}
