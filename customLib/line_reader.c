#include "line_reader.h"

char	*ft_line_extra(char *stash, int fd, char *buf)
{
	int		byte_read;
	char	*tmp;

	byte_read = 1;
	while (byte_read != 0)
	{
		byte_read = read (fd, buf, BUFFER_SIZE);
		if (byte_read == 0)
			break ;
		if (byte_read == -1)
			return (NULL);
		buf[byte_read] = '\0';
		if (stash == NULL)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

char	*ft_line_cut(char	*line)
{
	char	*stash;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	stash = ft_substr(line, i + 1, (ft_strlen(line) - 1) - i);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

char	*line_reader(int fd)
{
	char		*line;
	static char	*stash;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	line = ft_line_extra(stash, fd, buf);
	if (line != NULL)
		stash = ft_line_cut(line);
	free(buf);
	buf = NULL;
	return (line);
}