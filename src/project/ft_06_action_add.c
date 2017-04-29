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

void			ft_db_action_add(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, RECORD) == 0)
	{
		query->record = (void*)list->tag;
		ft_new_record(*query->database, query->nameTable, query->nameColumn, query->typeColumn, query->record);
		query->lock = False;
		free(query->nameTable);
		free(query->nameColumn);
		free(query->typeColumn);
		ft_print_debug_info(*query->database, "ADD RECORD");
	}
	else
		ft_printf(RED"BAD OBJECT (ADD)"CLN);
}
