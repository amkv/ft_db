/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   *.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <kalmykov.artem@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/00/00 00:00:00 by akalmyko          #+#    #+#             */
/*   Updated: 2017/00/00 00:00:00 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

int 			ft_is_all_print(const char *str)
{
	if (!str)
		return (0);
	while(ft_isprint(*str))
		str++;
	if (*str == '\0')
		return (1);
	else
		return (0);
}

static void 	ft_db_set_command_and_tag(char *pair, char **command, char **tag)
{
	char 		*pointer;
	char 		*start;
	char 		*null_termination;

	pointer = pair;
	start = pointer;
	while(*start == ' ')
	{
		pointer++;
		start++;
	}
	while(*pointer != PAIRSEPARATOR)
		pointer++;
	null_termination = pointer;
	*pointer = '\0';
	*command = ft_strdup(start);
	++pointer;
	while(*pointer == ' ')
		pointer++;
	*tag = ft_strdup(pointer);
	*null_termination = PAIRSEPARATOR;
}

void 			ft_db_parser(t_query **query, const char *format)
{
	char 		**pairs;
	int 		index;
	char 		*command;
	char 		*tag;

	index = 0;
	pairs = ft_strsplit(format, SEPARATOR);
	while(pairs[index])
	{
		ft_db_set_command_and_tag(pairs[index], &command, &tag);
		*query = ft_db_add_query(*query, command, tag);
		free(pairs[index]);
		pairs[index] = NULL;
		index++;
	}
	free(pairs);
	*query = (*query)->firstQuery;
}
