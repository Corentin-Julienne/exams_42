
#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char				*copy;
	int					i;
	size_t				sizer;

	if (!s1)
		return (NULL);
	sizer = ft_strlen(s1) + 1;
	copy = malloc(sizer * (sizeof(char)));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char  *ft_strchr(const char *s, int c)
{
    char    *new_ptr;
    char    d;
    size_t  i;

    i = 0;
	if (!s)
		return (NULL);
    d = (char)c;
    new_ptr = (char *)s;
    while (s[i])
    {
        if (s[i] != d)
            new_ptr++;
        else
            return (new_ptr);
        i++;
    }
    if (s[i] == d)
        return (new_ptr);
    else
        return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*copy;
	size_t			i;
	size_t			j;

	if (!s1)
		return (NULL);
	copy = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!(copy))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		copy[i++] = s2[j++];
	copy[i] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (copy);
}

char  *obtain_line(char *relic)
{
	int		i;
	int		j;
	char	*line;

	if (!ft_strchr(relic, '\n'))
		return (ft_strdup(relic));
	i = 0;
	while (relic[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = relic[j];
		j++;
	}
	line[j] = '\n';
	line[j + 1] = '\0';
	return (line);
}

char  *obtain_relic(char *relic)
{
	char		*new_relic;
	char		*cutted_relic;

	new_relic = ft_strdup(ft_strchr(relic, '\n'));
	free(relic);
	if (!new_relic)
		return (NULL);
	if (ft_strlen(new_relic) > 1)
	{
		cutted_relic = ft_strdup(new_relic + 1);
		free(new_relic);
		return (cutted_relic);
	}
	free(new_relic);
	return (NULL);
}

char *get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*relic = NULL;
	char			*line;
	ssize_t			reader;

	reader = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (ft_strchr(relic, '\n') == NULL && reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		buffer[reader] = '\0';
		if (!relic)
			relic = ft_strdup("");
		relic = ft_strjoin(relic, buffer);
	}
	line = obtain_line(relic);
	relic = obtain_relic(relic);
	if (reader == 0 && !relic && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
