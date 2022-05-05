#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 32
#endif

char	*ft_strdup(const char *s1);
size_t  ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char    *ft_strjoin(const char *s1, const char *s2);
char  	*obtain_line(char *relic);
char  	*obtain_relic(char *relic);
char 	*get_next_line(int fd);

#endif
