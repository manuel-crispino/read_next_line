#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static void	helper(char **stash, size_t line_len)
{
	size_t	stash_len;
	char	*new_stash;

	stash_len = ft_strlen(*stash);
	if (line_len < stash_len)
	{
		new_stash = ft_strdup(*stash + line_len);
		free(*stash);
		*stash = new_stash;
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
}

static char	*extract_line(char **stash)
{
	size_t	line_len;
	size_t	i;
	char	*line;

	line_len = 0;
	i = 0;
	if (!*stash || **stash == '\0')
		return (NULL);
	while ((*stash)[line_len] && (*stash)[line_len] != '\n')
		line_len++;
	if ((*stash)[line_len] == '\n')
		line_len++;
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	while (i < line_len)
	{
		line[i] = (*stash)[i];
		i++;
	}
	line[line_len] = '\0';
	helper(stash, line_len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buffer);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (extract_line(&stash));
}
