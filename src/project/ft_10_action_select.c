/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10_action_select.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:08:07 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:56:09 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void			ft_db_action_select(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, DATABASE) == 0)
	{
		list->unused = False;
		ft_print_debug_info(*query->database, "SELECT DATABASE");
	}
	else if (ft_strcmp(query->object, TABLE) == 0)
	{
		list->unused = False;
		ft_print_debug_info(*query->database, "SELECT TABLE");
	}
	else if (ft_strcmp(query->object, COLUMN) == 0)
	{
		list->unused = False;
		ft_print_debug_info(*query->database, "SELECT COLUMN");
	}
	else if (ft_strcmp(query->object, RECORD) == 0)
	{
		list->unused = False;
		ft_print_debug_info(*query->database, "SELECT RECORD");
	}
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (SELECT)"CLN);
}
