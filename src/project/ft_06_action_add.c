/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_06_action_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:01:06 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:39:20 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void			ft_db_action_add_record(t_query *query, t_query *list)
{
	t_table		*table;
	t_column	*column;
	t_record	*record;
	t_record	*firstRecord;

	query->lock = False;
	table = ft_return_table(*query->database, query->nameTable);
	if (!table)
		return (ft_print_debug_info(*query->database, RED"BAD TABLE"CLN));
	column = table->firstColumn;
	if (!column)
		return (ft_print_debug_info(*query->database, RED"BAD COLUMN"CLN));
	column = ft_return_column(table, query->nameColumnTo);
	if (!column)
		return (ft_print_debug_info(*query->database, RED"BAD COLUMN"CLN));
	record = ft_return_record(column, column->typeColumn, (void*)query->nameRecordTo);
	if (!record)
		return (ft_print_debug_info(*query->database, RED"BAD RECORD"CLN));
	firstRecord = record->firstID;
	while(firstRecord)
	{
		if (ft_strcmp(firstRecord->column->nameColumn, query->nameColumn) == 0)
		{
			if (!firstRecord->empty)
				return (ft_print_debug_info(*query->database, RED"NOT EMPTY RECORD"CLN));
			firstRecord->value = (void*)list->tag;
			firstRecord->empty = False;
			table->amountRecords += 1;
			return ;
		}
		firstRecord = firstRecord->right;
	}
	ft_print_debug_info(*query->database, "ADD RECORD");
}

void			ft_db_action_add(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, RECORD) == 0)
		ft_db_action_add_record(query, list);
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (ADD)"CLN);
}
