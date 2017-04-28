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

static bool 	ft_initialize_query(t_query *query,t_query *list, t_db **database)
{
	query->database = database;
	query->action = list->action;
	query->object = list->object;
	query->tag = list->tag;
	if (query->action == NULL || query->object == NULL || query->tag == NULL)
		return (False);
	return (True);
}

int	 			ft_db_action(t_query *list, va_list ap)
{
	t_query		query;
	t_db		**database;

	if (!list)
		return (-1);
	database = (t_db**)va_arg(ap, t_db*);
	while(list)
	{
		if (!ft_initialize_query(&query, list, database))
			ft_printf(RED"!BAD ACTION or BAD OBJECT or TAG\n"CLN);
		else if (ft_strcmp(query.action, CREATE) == 0)
			ft_db_action_create(&query, list);
		else if (ft_strcmp(query.action, ADD) == 0)
			ft_db_action_add(&query, list);
		else if (ft_strcmp(query.action, SET) == 0)
			ft_db_action_set(&query, list);
		else if (ft_strcmp(query.action, IN) == 0)
			ft_db_action_in(&query, list);
		else if (ft_strcmp(query.action, CHANGE) == 0)
			ft_db_action_change(&query, list);
		else if (ft_strcmp(query.action, SELECT) == 0)
			ft_db_action_select(&query, list);
		else if (ft_strcmp(query.action, DELETE) == 0)
			ft_db_action_delete(&query, list);
		else
			ft_printf(RED"!BAD ACTION\n"CLN);
		if (!query.lock)
			ft_db_null_query(&query);
		if (list)
			list = list->next;
	}
	return (0);
}

//		if (ft_strcmp(list->command, CREATE_DATABASE) == 0)
//		{

//		}
//		else if (ft_strcmp(list->command, CREATE_TABLE) == 0)
//		{
//			query.nameTable = list->tag;
//			ft_new_table(*query.database, query.nameTable);
//		}
//		else if (ft_strcmp(list->command, CREATE_COLUMN) == 0)
//		{
//			list->nameTable = list->tag;
//			list->nameColumn = list->next->tag;
//			list->typeColumn = list->next->next->tag;
//			ft_new_column(*query.database, list->nameTable, list->nameColumn, list->typeColumn);
//			list = list->next->next;
//		}
//		else if (ft_strcmp(list->command, ADD_RECORD) == 0)
//			;