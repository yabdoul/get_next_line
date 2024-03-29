#include  "get_next_line.h"
char	*read_line_from_file(int fd, char *left_words)
{
	char	*buffer;
	int		read_bytes;
	buffer = malloc((size_t)(BUFFER_SIZE + 1) * sizeof(char));
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
		return (free(line),NULL);
	line = my_get_line(left_words);
	
	left_words = left_words_from_str(left_words);
	return (line);
}
int main()
{
	char *test;
	int fd = open("example.txt",O_RDWR) ;
	while(1)
	{
		test = get_next_line(fd) ;
		if(!test)
		break;
			printf("%s",test); 
	
	free(test); 
	} 
	return 0 ; 
} 
