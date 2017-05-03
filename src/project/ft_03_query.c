/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_03_query.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 12:47:33 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:56:22 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void			ft_set_false_by_default_for_memory_allocation(t_query *query)
{
	query->memNameDB = False;
	query->memNameTable = False;
	query->memNameColumn = False;
	query->memTypeColumn = False;
	query->memNameDBTo = False;
	query->memNameTableTo = False;
	query->memNameColumnTo = False;
	query->memTypeColumnTo = False;
	query->memNameRecordTo = False;
}

void			ft_free_query_memory_allocation(t_query *query)
{
	(query->memNameDB) ? free(query->nameDB) : query->nameDB;
	query->nameDB = NULL;
	(query->memNameTable) ? free(query->nameTable) : query->nameTable;
	query->nameTable = NULL;
	(query->memNameColumn) ? free(query->nameColumn) : query->nameColumn;
	query->nameColumn = NULL;
	(query->memTypeColumn) ? free(query->typeColumn) : query->typeColumn;
	query->typeColumn = NULL;
	(query->memNameDBTo) ? free(query->nameDBTo) : query->nameDBTo;
	query->nameDBTo = NULL;
	(query->memNameTableTo) ? free(query->nameTableTo) : query->nameTableTo;
	query->nameTableTo = NULL;
	(query->memNameColumnTo) ? free(query->nameColumnTo) : query->nameColumnTo;
	query->nameColumnTo = NULL;
	(query->memTypeColumnTo) ? free(query->typeColumnTo) : query->typeColumnTo;
	query->typeColumnTo = NULL;
	(query->memNameRecordTo) ? free(query->nameRecordTo) : query->nameRecordTo;
	query->nameRecordTo = NULL;
	ft_set_false_by_default_for_memory_allocation(query);
}

void			ft_db_null_query(t_query *query)
{
	if (!query)
		return ;
	query->action = NULL;
	query->object = NULL;
	query->tag = NULL;
	query->lock = False;
	query->database = NULL;
	query->table = NULL;
	query->column = NULL;
	query->row = NULL;
	query->record = NULL;
	ft_free_query_memory_allocation(query);
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
	ft_set_false_by_default_for_memory_allocation(query);
	ft_db_null_query(query);
	return (query);
}

t_query			*ft_db_add_query(t_query *query, char *action, char *object, char *tag)
{
	t_query		*new;

	new = new_query();
	if (!new)
		return (NULL);
	new->action = action;
	new->object = object;
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
