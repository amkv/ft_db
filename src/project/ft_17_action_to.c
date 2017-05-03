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

static void		ft_db_action_to_table(t_query *query, t_query *list)
{
	query->nameDBTo = ft_strdup(list->tag);
	query->memNameDBTo = True;
	query->lock = True;
	ft_print_debug_info(*query->database, "TO TABLE");
}

static void		ft_db_action_to_column(t_query *query, t_query *list)
{
	query->nameColumnTo = ft_strdup(list->tag);
	query->memNameColumnTo = True;
	query->lock = True;
	ft_print_debug_info(*query->database, "TO COLUMN");
}

static void		ft_db_action_to_row(t_query *query, t_query *list)
{
	long long 	num;

	num = ft_atoi(list->tag);
	if (num <= 0)
	{
		query->lock = False;
		return(ft_print_debug_info(*query->database, "BAD ID"));
	}
	query->numRowTo = (size_t)num;
	query->lock = True;
	ft_print_debug_info(*query->database, "TO ROW");
}

static void		ft_db_action_to_record(t_query *query, t_query *list)
{
	query->nameRecordTo = ft_strdup(list->tag);
	query->memNameRecordTo = True;
	query->lock = True;
	ft_print_debug_info(*query->database, "TO RECORD");
}

void			ft_db_action_to(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, TABLE) == 0)
		ft_db_action_to_table(query, list);
	else if (ft_strcmp(query->object, COLUMN) == 0)
		ft_db_action_to_column(query, list);
	else if (ft_strcmp(query->object, ROW) == 0)
		ft_db_action_to_row(query, list);
	else if (ft_strcmp(query->object, RECORD) == 0)
		ft_db_action_to_record(query, list);
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (TO)"CLN);
}
