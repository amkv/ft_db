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
		ft_print_debug_info(*query->database, "DELETE RECORD");
	}
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (DELETE)"CLN);
}
