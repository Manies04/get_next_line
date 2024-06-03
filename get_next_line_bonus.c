/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:52:50 by tiade-al          #+#    #+#             */
/*   Updated: 2024/06/03 14:20:38 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;

	str = 0;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	while (*buffer[fd] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer[fd]);
		if (ft_checknewline(buffer[fd], 0))
			break ;
	}
	return (str);
}
/* int main()
{
	int fd = open("batata.txt", O_RDONLY);
	int fd2 = open("cenoura.txt", O_RDONLY);
	char *str = get_next_line(fd);
	char *str1 = get_next_line(fd2);
	printf("%s\n", str);
	printf("%s\n", str1);
	return (0);
} */