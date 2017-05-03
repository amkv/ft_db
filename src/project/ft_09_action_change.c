/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_09_action_change.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:39:45 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:42:28 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void			ft_db_action_change_record(t_query *query, t_query *list)
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
	record = ft_return_record(column, column->typeColumn, (void*)query->nameRecordTo);
	if (!record)
		return (ft_print_debug_info(*query->database, RED"BAD RECORD"CLN));
	if (!record->empty)
	{
		free(record->value);
		record->value = NULL;
		record->value = (void*)list->tag;
	}
	ft_print_debug_info(*query->database, "CHANGE RECORD");
}

void			ft_db_action_change(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, RECORD) == 0)
		ft_db_action_change_record(query, list);
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (CHANGE)"CLN);
}
