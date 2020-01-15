#include "get_next_line.h"

int	c_len(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	if (c == '\0')
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *str, int len)
{
	char *ret;
	int i;

	i = 0;
	if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (str[i] && i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	str_join(char **dst, char *src)
{
	int i;
	char *tmp;
	char *tmp2;

	i = 0;
	if (!*dst)
	{
		*dst = ft_strndup(src, c_len(src, '\0'));
		return ;
	}
	if (!(tmp = malloc(sizeof(char) * c_len(*dst, '\0') + c_len(src, '\0') + 1)))
			return ;
	tmp2 = *dst;
	while (tmp2[i])
	{
		tmp[i] = tmp2[i];
		i++;
	}
	while (*src)
	{
		tmp[i] = *src;
		src++ && i++;
	}
	tmp[i] = '\0';
	*dst = tmp;
}

int		return_value(char **stack, char **line)
{
	*line = c_len(*stack, ENDL) > -1 ? ft_strndup(*stack, c_len(*stack, ENDL)) : 0;
	if (c_len(*stack, ENDL) > -1)
	{
		*stack += c_len(*stack, ENDL) + 1;
		return (1);
	}
	else if (c_len(*stack, '\0') > 0)
	{
		*line = ft_strndup(*stack, c_len(*stack, '\0'));
		free(*stack);
		*stack = NULL;
		return (1);
	}
	return (0);
}
