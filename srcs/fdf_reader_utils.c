/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:32:41 by ldedier           #+#    #+#             */
/*   Updated: 2017/11/26 02:03:21 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			nb_words(char *line)
{
	int i;
	int parseword;
	int nb_words;

	i = 0;
	parseword = 0;
	nb_words = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !parseword)
		{
			parseword = 1;
			nb_words++;
		}
		if (line[i] == ' ' && parseword)
			parseword = 0;
		i++;
	}
	return (nb_words);
}

int			*ft_sub_tab(t_parser *parser, char **split)
{
	int *res;
	int i;
	int val;

	i = 0;
	if (!(res = (int *)malloc(sizeof(int) * parser->length)))
		return (NULL);
	while (split[i])
	{
		val = ft_atoi(split[i]);
		if (val > parser->max_value)
			parser->max_value = val;
		if (val < parser->min_value)
			parser->min_value = val;
		res[i] = val;
		i++;
	}
	return (res);
}
