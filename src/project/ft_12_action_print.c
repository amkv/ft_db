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

static void		ft_db_action_print_database(t_query *query, t_query *list)
{
	ft_db_print_all_db(*query->database);
	ft_print_debug_info(*query->database, "PRINT DATABASE");
}

static void		ft_db_action_print_table(t_query *query, t_query *list)
{
	ft_print_debug_info(*query->database, "PRINT TABLE");
}

static void		ft_db_action_print_column(t_query *query, t_query *list)
{
	ft_print_debug_info(*query->database, "PRINT COLUMN");
}

static void		ft_db_action_print_record(t_query *query, t_query *list)
{
	ft_print_debug_info(*query->database, "PRINT RECORD");
}

void			ft_db_action_print(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, DATABASE) == 0)
		ft_db_action_print_database(query, list);
	else if (ft_strcmp(query->object, TABLE) == 0)
		ft_db_action_print_table(query, list);
	else if (ft_strcmp(query->object, COLUMN) == 0)
		ft_db_action_print_column(query, list);
	else if (ft_strcmp(query->object, RECORD) == 0)
		ft_db_action_print_record(query, list);
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (PRINT)"CLN);
}
