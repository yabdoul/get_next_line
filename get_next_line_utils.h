#ifndef GET_NEXT_LINE_UTILS_H
#define GET_NEXT_LINE_UTILS_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 3
#endif
# include <fcntl.h>
#include <stdlib.h> 
#include <stdio.h>
char	*ft_strchr( char *s, int c); 
char    *ft_strjoin(char *left_str, char *buff);
char	*my_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
#endif