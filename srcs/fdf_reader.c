/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:32:41 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 14:05:37 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		process_check_file(int nb_lines, char *line, t_parser *res)
{
	if (nb_lines == 0)
		res->length = nb_words(line);
	if (nb_lines != 0 && nb_words(line) != res->length)
		res->length = -1;
}

int			check_file(char *filename, t_parser *res, char *line)
{
	int		fd;
	int		nb_lines;
	int		ret;

	nb_lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		process_check_file(nb_lines, line, res);
		nb_lines++;
		ft_strdel(&line);
	}
	if (ret == -1)
		return (1);
	ft_strdel(&line);
	close(fd);
	if (res->length < 0)
		return (2);
	else
	{
		res->height = nb_lines;
		return (0);
	}
}

int			process_new_parser(char *filename, t_parser *res)
{
	int		i;
	char	*line;
	int		fd;
	char	**split;
	int		ret;

	i = 0;
	fd = open(filename, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(split = ft_strsplit(line, ' ')))
			return (1);
		if (!(res->tab[i] = ft_sub_tab(res, split)))
			return (1);
		ft_free_split(split);
		ft_strdel(&line);
		i++;
	}
	if (ret == -1)
		return (1);
	ft_strdel(&line);
	close(fd);
	res->depth = res->max_value - res->min_value;
	return (0);
}

t_parser	*new_parser(char *filename, int *error)
{
	char		*line;
	t_parser	*res;

	line = NULL;
	if (!(res = (t_parser *)malloc(sizeof(t_parser))))
		return (NULL);
	res->max_value = 0;
	res->min_value = 0;
	res->length = -1;
	if ((*error = check_file(filename, res, line)) != 0)
		return (NULL);
	if (!(res->tab = (int **)malloc(sizeof(int *) * res->height)))
		return (NULL);
	if (process_new_parser(filename, res))
		return (NULL);
	return (res);
}
