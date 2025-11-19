#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);

#endif
