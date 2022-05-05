
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

// protos

size_t  ft_numlen_base(long n, size_t base);
void    ft_putlnbr(long n);
void    ft_putlnbr_base(unsigned int n, char *base);
size_t  ft_strlen(const char *str);
void    ft_putstr(const char *str);
void    ft_putchar(char c);

size_t  ft_numlen_base(long n, size_t base)
{
    size_t  res;
    
    res = 0;
    if (base == 10 && n < 0)
    {
        res++;
        n = n * (-1);
    }
    if (n == 0)
    {
        res = 1;
        return (res);
    }
    while (n > 0)
    {
        res++;
        n = n / base;
    }
    return (res);
}

void  ft_putlnbr(long n)
{
    if (n < 0)
    {
        ft_putchar('-');
        n = n * (-1);
    }
    if (n >= 10)
    {
        ft_putlnbr(n / 10);
        ft_putchar((n % 10) + '0');
    }
  else
        ft_putchar(n + '0');
}

static void  ft_base_converter(unsigned int n, char *base, unsigned long bs)
{
	if (n >= bs)
  	{
		ft_base_converter((n / bs), base, bs);
    	ft_putchar(base[(n % bs)]);
	}
	else
		ft_putchar(base[n]);
}

void  ft_putlnbr_base(unsigned int n, char *base)
{
    unsigned int  base_size;

    base_size = 0;
    while(base[base_size] != '\0')
        base_size++;
    ft_base_converter(n, base, base_size);
}

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str && str[i])
        i++;
    return (i);
}

void  ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(const char *s)
{
	int i;
	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

// conversion

int  handle_int(va_list args)
{
    int   res;
    int   numlen;

    res = va_arg(args, int);
    numlen = ft_numlen_base(res, 10);
    ft_putlnbr(res);
    return (numlen);
}

int handle_string(va_list args)
{
	char *str;
	int  len;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	ft_putstr(str);
	return (len);
}

int handle_hxd(va_list args)
{
	unsigned int  res;
	int           size;

	res = va_arg(args, unsigned int);
	ft_putlnbr_base(res, "0123456789abcdef");
	size = ft_numlen_base(res, 16);
	return (size);
}

// core functions

int ft_printf(const char *format, ...)
{
	int     i;
	int     rtn;
	va_list args;

	rtn = 0;
	i = 0;
	va_start(args, format);
	while (format && format[i])
	{
	if (format[i] != '%')
	{
		write(1, &format[i], 1);
		rtn++;
		}
	else
	{
		if (format[i + 1] && format[i + 1] == 'd')
			rtn = rtn + handle_int(args);
		else if (format[i + 1] && format[i + 1] == 'x')
			rtn = rtn + handle_hxd(args);
		else if (format[i + 1] && format[i + 1] == 's')
			rtn = rtn + handle_string(args);
		i++;
	}
	i++;
	}
	va_end(args);
	return (rtn);
}
