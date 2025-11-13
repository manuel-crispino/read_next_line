#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1 
#endif

static int	ft_strlen(const char *s)
{
	int	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

static char *ft_strjoin_free(char *s1, const char *s2)
{
	size_t len1;  
	size_t len2;
	size_t i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	char *res = malloc(len1 + len2 + 1);
	if (!res)
		return NULL;
	while ( i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		res[len1 + i] = s2[i];
		i++;
	}
	res[len1 + len2] = '\0';
	free(s1);
	return res;
}

char *get_next_line(int fd)
{
	char *buffer;
	char *line;
	ssize_t bytes_read;

	line = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = ft_strjoin_free(line, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return line;
}

int main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	char *line;

	if (fd == -1)
	{
		perror("Errore nell'apertura del file");
		return (1);
	}

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	close(fd);
	return (0);
}
