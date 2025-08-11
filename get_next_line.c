/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:14:20 by jiyawang          #+#    #+#             */
/*   Updated: 2025/08/01 20:14:24 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		b_read;
	char	*c_buffer;

	c_buffer = malloc(sizeof(char) * (3 + 1));
	if (!c_buffer)
		return (NULL);
	b_read = read(fd, c_buffer, 3);
	return (c_buffer);
}
