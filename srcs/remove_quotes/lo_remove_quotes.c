/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <locharve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:09:30 by locharve          #+#    #+#             */
/*   Updated: 2024/05/14 15:21:03 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mish.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	if (str[i])
		return (&str[i]);
	else
		return (NULL);
}

static char    *quotes_strchr(char *str)
{
    char    *chr_simple;
    char    *chr_double;

    chr_simple = ft_strchr(str, '\'');
	printf("simple = #%s#\n", chr_simple); ///
    chr_double = ft_strchr(str, '\"');
	printf("double = #%s#\n", chr_double); ///
    if ((!chr_double && chr_simple) || chr_simple < chr_double)
        return (chr_simple);
    else if ((chr_double && !chr_simple) || chr_double < chr_simple)
        return (chr_double);
	else
		return (NULL);
}

static char	*copy_removing(char *dst, char *src, char *start, char *end)
{
	int	i;

	i = 0;
	while (src && src[i] && &src[i] != start)
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
	if (!dst)
		printf("NULL\n"); /////
	else
		printf("dst = #%s#\n", dst); ////////
	return (dst);
}

static int	init_start_end(char *str, char **start, char **end)
{
	*start = quotes_strchr(str);
	if (*start)
		*end = ft_strchr(&(*start)[1], *start[0]);
	if (*start && *end)
		return (1);
	else
		return (0);
}
/*
t_err_type    mish_remove_quotes(t_mish *mish, char **p_lines)
{
	char	*result;
    char    *start;
	char	*end;
    int     i;

    i = 0;
    while (p_lines && p_lines[i])
    {
        while (init_start_end(p_lines[i], start, end))
        {
            end = ft_strchr(&start[1], start[0]);
			printf("end = #%s#\n", end); ////////
			result = ft_calloc(ft_strlen(p_lines[i]) - 2, sizeof(char));
			if (result)
				result = copy_removing(result, p_lines[i], start, end);
			else
				mish_error_add(mish, err_malloc, errno, "mish_remove_quotes"); //
			free(p_lines[i]);
			p_lines[i] = result;
			//start = quotes_strchr(p_lines[i]);
        }
        i++;
    }
	return (t_error_exist(mish->error));
}
*/
int	main(int argc, char **argv)
{
	char	*dup;
	char	*str;
	char	*start;
	char	*end;
	
	if (argc == 2)
	{
		dup = strdup(argv[1]);
		if (dup)
		{
			while (init_start_end(dup, &start, &end))
			{
				str = calloc(strlen(dup) - 2 + 1, sizeof(char));
				if (str)
					str = copy_removing(str, dup, start, end);
				// else error
				free(dup);
				dup = str;
			}
		}
		printf("%s\n", dup); ///
		free(dup);
	}
	return (0);
}
