#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_in_other_str(char *s1, char *s2, int i)
{
	int		res;
	int		j;

	res = 0;
	j = 0;
	while (s2[j])
	{
		if (s1[i] == s2[j])
			res = 1;
		j++;
	}
	return (res);
}

int	is_already_printed(char *s1, int i)
{
	int		j;
	int 	res;

	res = 0;
	j = 0;
	while (j < i)
	{
		if (s1[j] == s1[i] && i != j)
			res = 1;
		j++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (is_in_other_str(argv[1], argv[2], i))
			{
				if (is_already_printed(argv[1], i) == 0)
					ft_putchar(argv[1][i]);
			}	
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
