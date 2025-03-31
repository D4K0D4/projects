/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamiti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:54:23 by ehamiti           #+#    #+#             */
/*   Updated: 2025/01/18 11:43:11 by ehamiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
static char	*read_and_fill(int fd, char *remainder, int *bytes_read)
{
	char	*buffer;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (remainder && !ft_strchr(remainder, '\n'))
	{
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read <= 0)
			break ;
		buffer[*bytes_read] = '\0';
		temp = remainder;
		remainder = ft_strjoin(remainder, buffer);
		free (temp);
	}
	free (buffer);
	return (remainder);
}
static char	*buffer_check(char *buffer, char *remainder)
{
	if (!buffer)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	return (remainder);
}
static char	*extract_line(char **remainder)
{
	char	*line;
	char	*new_remainder;
	int		len;

	len = 0;
	if (!*remainder || !**remainder)
		return (NULL);
	while ((*remainder)[len] && (*remainder)[len] != '\n')
		len++;
	if ((*remainder)[len] == '\n')
		len++;
	line = ft_substr(*remainder, 0, len);
	new_remainder = ft_strdup(*remainder + len);
	free(*remainder);
	*remainder = new_remainder;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char	*line;
	int	bytes_read;
	char	*buffer;

	bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	remainder = buffer_check(buffer, remainder);
	if (!remainder)
	{
		free(buffer);
		return (NULL);
	}
	remainder = read_and_fill(fd, remainder, &bytes_read);
	if (!remainder || (bytes_read == 0 && *remainder == '\0'))
	{
		free(remainder);
		remainder = NULL;
		free(buffer);
		return (NULL);
	}
	line = extract_line(&remainder);
	free(buffer);
	return (line);
}
*/
static char *read_and_fill(int fd, char *remainder, int *bytes_read)
{
    char *buffer;
    char *temp;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (remainder && !ft_strchr(remainder, '\n')) // Boucle seulement si pas de '\n'
    {
        *bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (*bytes_read <= 0)
            break;
        buffer[*bytes_read] = '\0';
        temp = remainder;
        remainder = ft_strjoin(remainder, buffer);
        free(temp);
        if (!remainder) // Vérifiez si ft_strjoin a échoué
        {
            free(buffer);
            return (NULL);
        }
    }
    free(buffer);
    return (remainder);
}

static char *extract_line(char **remainder)
{
    char *line;
    char *new_remainder;
    int len;

    len = 0;
    if (!*remainder || !**remainder) // Si remainder est vide, retournez NULL
        return (NULL);
    while ((*remainder)[len] && (*remainder)[len] != '\n')
        len++;
    if ((*remainder)[len] == '\n')
        len++;
    line = ft_substr(*remainder, 0, len);
    if (!line)
        return (NULL);
    new_remainder = ft_strdup(*remainder + len);
    free(*remainder);
    *remainder = new_remainder;
    return (line);
}

char *get_next_line(int fd)
{
    static char *remainder;
    char *line;
    int bytes_read;

    bytes_read = 0;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    remainder = read_and_fill(fd, remainder, &bytes_read);
    if (!remainder || (bytes_read == 0 && *remainder == '\0'))
    {
        if (remainder)
            free(remainder);
        remainder = NULL;
        return (NULL);
    }
    line = extract_line(&remainder);
    return (line);
}
