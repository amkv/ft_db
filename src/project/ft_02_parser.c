/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_02_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:00:57 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:56:14 by akalmyko         ###   ########.fr       */
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

static void		ft_set_action_and_object(char *command, char **action, char **object)
{
	char 		*pointer;
	char 		*null_termination_pointer;

	pointer = command;
	while(*pointer && *pointer != ACTION_OBJECT_SEPARATOR)
		pointer++;
	if (*pointer == '\0')
	{
		*action = NULL;
		*object = NULL;
		return ;
	}
	null_termination_pointer = pointer;
	*null_termination_pointer = '\0';
	*action = ft_strdup(command);
	++pointer;
	*object = ft_strdup(pointer);
	*null_termination_pointer = ACTION_OBJECT_SEPARATOR;
}

static void 	ft_db_set_action_target_tag(char *pair, char **action, char **object, char **tag)
{
	char 		*pointer;
	char 		*start;
	char 		*null_termination_pointer;
	char 		*command;

	pointer = pair;
	start = pointer;
	while(*start == ' ')
	{
		pointer++;
		start++;
	}
	while(*pointer && *pointer != PAIRSEPARATOR)
		pointer++;
	null_termination_pointer = pointer;
	if (*pointer == '\0')
	{
		*tag = NULL;
		command = ft_strdup(start);
	}
	else
	{
		*pointer = '\0';
		command = ft_strdup(start);
		++pointer;
		while(*pointer == ' ')
			pointer++;
		*tag = ft_strdup(pointer);
		*null_termination_pointer = PAIRSEPARATOR;
	}
	ft_set_action_and_object(command, action, object);
	free(command);
}

void 			ft_db_parser(t_query **query, const char *format)
{
	char 		**pairs;
	char 		*action;
	char 		*object;
	char 		*tag;
	int 		index;

	pairs = ft_strsplit(format, SEPARATOR);
	if (!pairs)
		return ;
	index = 0;
	while(pairs[index])
	{
		ft_db_set_action_target_tag(pairs[index], &action, &object, &tag);
		*query = ft_db_add_query(*query, action, object, tag);
		free(pairs[index]);
		pairs[index] = NULL;
		index++;
	}
	free(pairs);
	*query = (*query)->firstQuery;
}
