/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:30:28 by tiade-al          #+#    #+#             */
/*   Updated: 2024/05/21 16:12:28 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**@brief The strlen() function calculates the length of the string s, excluding
 * the terminating null byte ('\0').
 *@param str: The string to calculate the length of.
 *@return The number of characters in the string.
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i + (s[i] == '\n'));
}
//se a string == '\n' ele retorna 1, se não ele retorna 0

/**@brief Allocates (with malloc(3)) and returns a new string, which is the 
 * result of the concatenation of ’s1’ and ’s2’.
 * @param s1: The prefix string.
 * @param s2: The suffix string.
 * @return The new string. NULL if the allocation fails.
*/
char	*ft_strjoin(char *str, char *buffer)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = (char *)malloc(ft_strlen(str) + ft_strlen(buffer) + 1);
	if (!new_str)
		return (NULL);
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (buffer[j])
	{
		new_str[i + j] = buffer[j];
		if (buffer[j] == '\n')
			break ;
		j++;
	}
	new_str[i + j] = '\0';
	free (str);
	return (new_str);
}

int	ft_checknewline(char *buffer, int i)
{
	char	*bc;
	char	*t;

	bc = buffer;
	t = buffer;
	while (*bc)
	{
		if (*bc == '\n')
		{
			i = 1;
			*bc++ = '\0';
			break ;
		}
		*bc++ = '\0';
	}
	if (i == 1)
	{
		while (*bc)
		{
			*t++ = *bc;
			*bc++ = '\0';
		}
	}
	return (i);
}
