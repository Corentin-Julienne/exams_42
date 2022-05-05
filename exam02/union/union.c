#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_printed_first_str(char *s1, int i)
{
	int		res;
	int		j;

	res = 0;
	j = 0;
	while (j < i)
	{
		if (s1[i] == s1[j])
			res = 1;
		j++;
	}
	return (res);
}

int	is_printed_all_str(char *s1, char *s2, int j)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (s1[i])
	{
		if (s2[j] == s1[i])
			res = 1;
		i++;
	}
	if (res == 1)
		return (res);
	else 
		return (is_printed_first_str(s2, j));
}

int main(int argc, char **argv)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (is_printed_first_str(argv[1], i) == 0)
				ft_putchar(argv[1][i]);
			i++;
		}
		while (argv[2][j])
		{
			if (is_printed_all_str(argv[1], argv[2], j) == 0)
				ft_putchar(argv[2][j]);
			j++;
		}
	}
	ft_putchar('\n');
	return (0);
}
