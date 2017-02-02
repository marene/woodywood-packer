#ifndef WOODY_H
# define WOODY_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>
# include "libft.h"

# define WOODY_OK		0
# define WOODY_NOK		1

# define P_OPENED		0x01
# define P_MAPPED		0x10


typedef struct			s_packer
{
	char					*fileName;
	int						fd;
	unsigned int			magic;
	size_t					st_size;
	void					*data;
	void					*r_ptr;
	struct mach_header_64	*header;
}						t_packer;

int						packer_init(t_packer *woody, char *binFile);
void					packer_destruct(t_packer *woody);
int						pack(t_packer *woody);
size_t					packer_read(t_packer *woody, void *data, size_t size);

#endif
