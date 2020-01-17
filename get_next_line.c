/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:21:02 by motoure           #+#    #+#             */
/*   Updated: 2020/01/17 01:21:10 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char *stack[4094];
	int			file;

	if (fd < 0 || line == NULL)
		return (-1);
	while (c_len(stack[fd], ENDL) == -1)
	{
		file = read(fd, buff, BUFF_SIZE);
		buff[file] = '\0';
		if (file > 0)
			str_join(&stack[fd], buff);
		if (file == 0)
			break ;
	}
	return (return_value(&stack[fd], line));
}
