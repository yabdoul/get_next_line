#include  "get_next_line_utils.h"
char	*read_line_from_file(int fd, char *left_words)
{
	char	*buffer;
	int		read_bytes;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(left_words, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		left_words = ft_strjoin(left_words, buffer);
	}
	free(buffer);
	return (left_words);
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_words;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_words = read_line_from_file(fd, left_words);
	if (!left_words)
		return (NULL);
	line = my_get_line(left_words);
	left_words = ft_new_left_str(left_words);
	return (line);
}