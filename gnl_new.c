#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define $ENDL '\n'
#define $ZERO '\0'

/*
c_index:
	int	get_c_index(char *str, char c);
	search in [str] for the first occurence of [c]
	or execute a regular strlen if (c == $ZERO)
	return values:
		index of [c] ([i]) or -1 if [c] do not exist.
		len of [str] if (c == $ZERO).
		-1 if (str == NULL).
*/

int		get_c_index(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	if (c == $ZERO)
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

/*ft_strndup:
	dup up to { len }
	return values:
		return NULL if something went wrong.
		return str - len
*/

char	*ft_strndup(char *str, int len)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (str[i] && i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = $ZERO;
	return (ret);
}

char	*join(char *left, char *right)
{
	int		i;
	int		y;
	int		total_len;
	char	*ret_val;

	if (!left || !right)
		return (NULL);
	total_len = get_c_index(left, $ZERO) + get_c_index(right, $ZERO);
	ret_val = malloc(sizeof(char) * total_len + 1);
	if (!ret_val)
		return (NULL);
	i = -1;
	while (left[++i])
		ret_val[i] = left[i];
	y = i;
	i = -1;
	while (right[++i])
	{
		ret_val[y] = right[i];
		y++;
	}
	ret_val[y] = $ZERO;
	free(left);
	return (ret_val);
}

char	*juno_to_line(char **juno)
{
	char	*line;
	char	*tmp;

	//--- case if it is not the last line ---
	line = NULL; // don't forget to set line to { NULL } for later on comparison
	if (get_c_index(*juno, $ENDL) > -1) // if { $ENDL } is present in { *juno }
	{
		line = ft_strndup(*juno, get_c_index(*juno, $ENDL) + 1); // we an { strdup() } { *juno } for a range of the index of $ENDL + 1 "ccccccN"
		tmp = ft_strndup(&(*juno)[get_c_index(*juno, $ENDL) + 1], // !important we use tmp to { strdup() } on { *juno } from the index of $ENDL + 1 to the end of { *juno }
		get_c_index(*juno, $ZERO));
		free(*juno); // then we can free { *juno } to avoid any leaks, note that tmp contain the new juno already
		*juno = tmp; // then we assign { *juno } to tmp
		return (line); // ...
	}
	// --- case if it is the last line ---
	else if (*juno && *juno[0] != $ZERO) // if { *juno } exist and { *juno } of [0] is not a $ZERO
		line = ft_strndup(*juno, get_c_index(*juno, $ZERO)); //it means it is the last line and we can just { strdup() } the entire { *juno } to line
	if (*juno) //get_next_line finished reading the file so we can just free { *juno } and set it to NULL
	{
		free(*juno);
		*juno = NULL;
	}
	if (line) // we return the line { strdup'ed } earlier
		return (line);
	else
		return (NULL); // or return { NULL } if something went wrong =P
		
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*juno[4094];
	int			ret_of_read;

	if (fd < 0) //check if { fd } is invalid (abort if so)
		return (NULL);
	while (get_c_index(juno[fd], $ENDL) == -1) //read as long as no { $ENDL } is present in juno[fd]
	{
		ret_of_read = read(fd, buff, BUFFER_SIZE);
		buff[ret_of_read] = $ZERO;
		if (ret_of_read > 0) //if read worked
		{
			if (!juno[fd]) // { juno[fd] } = { strdup() } of { buff } if { juno[fd] } is empty
				juno[fd] = ft_strndup(buff,
				get_c_index(buff, $ZERO));
			else
				juno[fd] = join(juno[fd], buff); // otherwise we can join { buff } to { juno[fd] }
		}
		else //if read did not work we skip to { juno_to_line() }
			break ;
	}
	return (juno_to_line(&juno[fd])); //default funtction if { juno[fd] } is not empty and contain a { $ENDL }
}
