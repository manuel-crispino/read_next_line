#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char *extract_line(char **stash)
{
    size_t	line_len;
    size_t	stash_len;
	size_t	i;
    char	*line;
    char	*new_stash;
    char	*newline_pos;

	i = 0;
    if (!*stash || (*stash)[0] == '\0')
        return (NULL);

    newline_pos = ft_strchr(*stash, '\n');
    if (newline_pos)
        line_len = newline_pos - *stash + 1; 
    else
        line_len = ft_strlen(*stash);
    line = malloc(line_len + 1);
	if (!line) return (NULL);
	while (i < line_len)
	{
		line[i] = (*stash)[i];
		i++;
	}
    line[line_len] = '\0';
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
    return (line);
}
