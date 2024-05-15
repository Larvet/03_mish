/*
static char    *quotes_strchr(char *str)
{
    char    *chr_simple;
    char    *chr_double;

    chr_simple = ft_strchr(str, '\'');
    chr_double = ft_strchr(str, '\"');
    if ((!chr_double && chr_simple) || (chr_simple && chr_double
			&& chr_simple < chr_double))
        return (chr_simple);
    else if ((chr_double && !chr_simple) || (chr_simple && chr_double
			&&chr_double < chr_simple))
        return (chr_double);
	else
		return (NULL);
}

static char	*copy_removing(char *dst, char *src, char *start, char *end)
{
	int	i;

	i = 0;
	while (src && &src[i] != start)
	{
		dst[i] = src[i];
		i++;
	}
	while (src && &src[i + 1] != end)
	{
		dst[i] = src[i + 1];
		i++;
	}
	while (src && src[i + 2])
	{
		dst[i] = src[i + 2];
		i++;
	}
	return (dst);
}

static int	init_start_end(char *str, char **start, char **end)
{
	*start = quotes_strchr(str);
	if (*start)
		*end = ft_strchr(&(*start)[1], (*start)[0]);
	if (*start && *end)
		return (1);
	else
		return (0);
}

t_err_type    mish_remove_quotes(t_mish *mish, char **p_lines)
{
	char	*result;
    char    *start;
	char	*end;
	int		tmp;
    int     i;

    i = 0;
    while (p_lines && p_lines[i])
    {
		printf("p_lines %d = %s\n", i, p_lines[i]); ///

        tmp = init_start_end(p_lines[i], &start, &end);
		while (tmp)
        {
			result = ft_calloc(ft_strlen(p_lines[i]) - 2 + 1, sizeof(char));
			if (result)
				result = copy_removing(result, p_lines[i], start, end);
			else
				mish_error_add(mish, err_malloc, errno, "mish_remove_quotes"); //
			free(p_lines[i]);
			p_lines[i] = result;
			//printf("p_lines %d = %s\n", i, p_lines[i]); ///
			tmp = init_start_end(p_lines[i], &start, &end);
        }
        i++;
    }
	return (t_error_exist(mish->error));
}
*/