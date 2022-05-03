/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:57:34 by mcordoba          #+#    #+#             */
/*   Updated: 2022/03/07 21:25:35 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strchr(const char *s, int c)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0' && s[cnt] != (unsigned char)c)
		cnt++;
	if (s[cnt] == (unsigned char)c)
		return ((char *)&s[cnt]);
	return (NULL);
}

static char	*line_split(char **s_line)
{
	char	*dst;
	char	*aux;

	dst = NULL;
	aux = NULL;
	if (!**s_line || !*s_line)
	{
		free(*s_line);
		*s_line = NULL;
		return (NULL);
	}
	aux = *s_line;
	dst = ft_substr(aux, 0, size_ln(aux) + 1);
	*s_line = ft_substr(aux, (size_ln(aux) + 1), ft_strlen(aux));
	free(aux);
	return (dst);
}

char	*get_next_line_check(int fd)
{
	ssize_t		val_read;
	static char	*s_line;
	char		*aux;
	char		*file;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	file = malloc(BUFFER_SIZE * (sizeof(char) + 1));
	if (!file)
		return (NULL);
	while (!s_line || ft_strchr(s_line, '\n') == NULL)
	{
		if (!s_line)
			s_line = ft_strdup("");
		val_read = read(fd, file, BUFFER_SIZE);
		file[val_read] = '\0';
		if (val_read <= 0)
			break ;
		aux = s_line;
		s_line = ft_strjoin(aux, file);
		free (aux);
	}
	free (file);
	return (line_split(&s_line));
}
