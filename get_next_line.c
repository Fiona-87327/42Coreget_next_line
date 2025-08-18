/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:14:20 by jiyawang          #+#    #+#             */
/*   Updated: 2025/08/18 13:43:46 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	b_read;
	char	*c_buffer;

	c_buffer = malloc(sizeof(char) * (3 + 1));
	if (!c_buffer)
		return (NULL);
	b_read = read(fd, c_buffer, 3);
	c_buffer[b_read] = '\0';
	if (b_read <= 0)
		return (0);
	return (c_buffer);
}

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int	fd;
	int	count;
	char *nextline;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}
	while (1)
	{
	nextline = get_next_line(fd);
	if (nextline == NULL)
		break;
	count++;
	printf("%d,%s\n", count, nextline);
	free(nextline);
	nextline = NULL;
	}
	close(fd);
	return 0;
}
