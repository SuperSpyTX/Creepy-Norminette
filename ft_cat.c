/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 22:22:22 by jkrause           #+#    #+#             */
/*   Updated: 2017/04/20 23:01:27 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

/*
**           _,'|             _.-''``-...___..--';)
**         /_ \'.      __..-' ,      ,--...--'''
**        <\    .`--'''       `     /'
**         `-';'               ;   ; ;
**   __...--''     ___...--_..'  .;.'
**  (,__....----'''       (,..--''   ft_cat - By Felix Lee
*/

int				ft_strlen(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

void			print_error(char *progname, char *file)
{
	char *error;

	error = ": ";
	write(2, progname, ft_strlen(progname));
	write(2, error, ft_strlen(error));
	write(2, file, ft_strlen(file));
	error = ": No such file or directory\n";
	write(2, error, ft_strlen(error));
}

int				main(int argc, char **argv)
{
	int				fd;
	int				wrote;
	char			out[29999];

	if (argc < 2 || argv[1][0] == '-')
	{
		while ((wrote = read(0, &out, 29999)) > 0)
		{
			write(1, &out, wrote);
		}
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			print_error(argv[0], argv[1]);
		}
		while ((wrote = read(fd, &out, 29999)) > 0)
		{
			write(1, &out, wrote);
		}
		close(fd);
	}
}
