/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:46:51 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 14:29:25 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	decal_tab(char *str, int index, int size)
{
	int i;

	i = index;
	while (i < size)
	{
		str[i - index] = str[i];
		i++;
	}
	str[i - index] = '\0';
}

int		ft_process_strcadline(int i, char **line, char *res, char *rest)
{
	if (!(*line = ft_strsub(res, 0, i)))
		return (1);
	i = 0;
	while (rest[i] != '\n')
		i++;
	decal_tab(rest, i + 1, BUFF_SIZE);
	ft_strdel(&res);
	return (0);
}

int		ft_strcadline(char **line, char *rest, int *endline)
{
	char	*res;
	int		i;

	if (!(res = ft_strjoin(*line, rest)))
		return (1);
	ft_strdel(line);
	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
	{
		if (ft_process_strcadline(i, line, res, rest) == 1)
			return (1);
		*endline = 1;
	}
	else
	{
		if (!(*line = ft_strdup(res)))
			return (1);
		ft_strdel(&res);
		ft_bzero(rest, BUFF_SIZE);
	}
	return (0);
}

int		process_get_next_line(int fd, char **line, int endline, char *rest)
{
	int ret;

	ret = 1;
	if (!endline)
	{
		ft_bzero(rest, BUFF_SIZE);
		while (!endline && (ret = read(fd, rest, BUFF_SIZE)) > 0)
		{
			if (ft_strcadline(line, rest, &endline) == 1)
				return (-1);
		}
		if (ret == -1)
			return (ret);
	}
	if (!ft_strcmp(*line, "") && ret == 0)
		return (0);
	else
		return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char		*rest = NULL;
	int				i;
	int				endline;

	if (rest == NULL)
	{
		if (!(rest = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	if (line == NULL)
		return (-1);
	endline = 0;
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		endline = 1;
	if (!(*line = ft_strnew(i)))
		return (-1);
	ft_strncpy(*line, rest, i);
	decal_tab(rest, i + 1, BUFF_SIZE);
	return (process_get_next_line(fd, line, endline, rest));
}
