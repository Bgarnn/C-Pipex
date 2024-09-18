#ifndef LINE_READER_H
# define LINE_READER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int val);
char	*ft_substr(char const *str, unsigned int start, size_t num);
char	*line_reader(int fd);

#endif
