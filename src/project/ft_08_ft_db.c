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

static void		ft_db_null_query(t_query *query)
{
	if (!query)
		return ;
	query->database = NULL;
	query->table = NULL;
	query->column = NULL;
	query->row = NULL;
	query->nameDB = NULL;
	query->nameTable = NULL;
	query->nameColumn = NULL;
	query->typeColumn = NULL;
	query->record = NULL;
	query->error = False;
	query->error_name = NULL;
	query->firstQuery = NULL;
	query->next = NULL;
}

static t_query 	*new_query(void)
{
	t_query *query;

	query = (t_query*)malloc(sizeof(t_query) * 1);
	if (!query)
		return (NULL);
	ft_db_null_query(query);
	return (query);
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

static t_query	*ft_db_add_query(t_query *query, char *command, char *tag)
{
	t_query		*new;

	new = new_query();
	if (!new)
		return (NULL);
	new->command = command;
	new->tag = tag;
	if (!query)
	{
		query = new;
		query->firstQuery = new;
	}
	else
	{
		query->next = new;
		new->firstQuery = query->firstQuery;
		query = new;
	}
	return (query);
}

static void 	ft_db_parser(t_query **query, const char *format)
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

static int	 	ft_db_action(t_query *query, va_list list)
{
//	void		*pointer;
//	t_db		*database;

	if (!query)
		return (-1);
	while(query)
	{
		if (ft_strcmp(query->command, "CREATE DATABASE") == 0)
		{
//			pointer = va_arg(list, t_db*);
//			ft_printf("acti: %p\n", pointer);
//			database = ft_init_db("My fisrt DB");
//			ft_printf("acti data: %p\n", database);
//			ft_printf("acti point before: %p\n", pointer);
////			pointer = (void*)ft_init_db("My fisrt DB");
//			pointer = (void*)database;
//			ft_printf("acti poin: %p\n", pointer);
			;
		}
		else if (ft_strcmp(query->command, "CREATE TABLE") == 0)
			;
		else if (ft_strcmp(query->command, "CREATE COLUMN") == 0)
			;
		else if (ft_strcmp(query->command, "NEW RECORD") == 0)
			;
		query = query->next;
	}
	return (0);
}

int 			ft_db(const char *restrict format, ...)
{
	va_list		list;
	t_query		*query;

	if (!format)
		return (0);
	query = NULL;
	va_start(list, format);
	ft_db_parser(&query, format);
	ft_db_action(query, list);
	va_end(list);
//	ft_db_null_query(query);
//	free(query);
//	ft_db_free_query(query);
	return (0);
}
