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

static void		ft_db_action_dump_database(t_query *query, t_query *list)
{
	query->nameDB = list->tag;
	ft_db_dump(*query->database, query->nameDB);
	ft_print_debug_info(*query->database, "DUMP DATABASE");
}

static void		ft_db_action_dump_table(t_query *query, t_query *list)
{
	ft_print_debug_info(*query->database, "DUMP TABLE");
}

static void		ft_db_action_dump_column(t_query *query, t_query *list)
{
	ft_print_debug_info(*query->database, "DUMP COLUMN");
}

static void		ft_db_action_dump_record(t_query *query, t_query *list)
{
	ft_print_debug_info(*query->database, "DUMP RECORD");
}

void			ft_db_action_dump(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, DATABASE) == 0)
		ft_db_action_dump_database(query, list);
	else if (ft_strcmp(query->object, TABLE) == 0)
		ft_db_action_dump_table(query, list);
	else if (ft_strcmp(query->object, COLUMN) == 0)
		ft_db_action_dump_column(query, list);
	else if (ft_strcmp(query->object, RECORD) == 0)
		ft_db_action_dump_record(query, list);
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (DUMP)"CLN);
}
