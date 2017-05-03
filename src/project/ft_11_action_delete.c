/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_11_action_delete.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:50:35 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:42:42 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

static void		ft_db_action_delete_record(t_query *query, t_query *list)
{
	t_table		*table;
	t_column	*column;
	t_record	*record;

	query->lock = False;
	table = ft_return_table(*query->database, query->nameTable);
	if (!table)
		return (ft_print_debug_info(*query->database, RED"BAD TABLE"CLN));
	column = table->firstColumn;
	if (!column)
		return (ft_print_debug_info(*query->database, RED"BAD COLUMN"CLN));
	column = ft_return_column(table, query->nameColumn);
	if (!column)
		return (ft_print_debug_info(*query->database, RED"BAD COLUMN"CLN));
	record = ft_return_record(column, column->typeColumn, (void*)list->tag);
	if (!record)
		return (ft_print_debug_info(*query->database, RED"BAD RECORD"CLN));
	if (!record->empty)
	{
		free(record->value);
		record->value = NULL;
		record->empty = True;
		table->amountRecords -= 1;
	}
	ft_print_debug_info(*query->database, "CHANGE RECORD");
}

void			ft_db_action_delete(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, DATABASE) == 0)
	{
		ft_print_debug_info(*query->database, "DELETE DATABASE");
	}
	else if (ft_strcmp(query->object, TABLE) == 0)
	{
		ft_print_debug_info(*query->database, "DELETE TABLE");
	}
	else if (ft_strcmp(query->object, COLUMN) == 0)
	{
		ft_print_debug_info(*query->database, "DELETE COLUMN");
	}
	else if (ft_strcmp(query->object, RECORD) == 0)
	{
		ft_db_action_delete_record(query, list);
		ft_print_debug_info(*query->database, "DELETE RECORD");
	}
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (DELETE)"CLN);
}
