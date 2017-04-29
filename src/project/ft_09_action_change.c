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

void			ft_db_action_change(t_query *query, t_query *list)
{
	if (ft_strcmp(query->object, RECORD) == 0)
	{
		ft_print_debug_info(*query->database, "CHANGE RECORD");
	}
	else
		ft_print_debug_info(*query->database, RED"BAD OBJECT (CHANGE)"CLN);
}
