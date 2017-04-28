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
		ft_printf("!DELETE DATABASE\n");
	}
	else if (ft_strcmp(query->object, TABLE) == 0)
	{
		ft_printf("!DELETE TABLE\n");
	}
	else if (ft_strcmp(query->object, COLUMN) == 0)
	{
		ft_printf("!DELETE COLUMN\n");
	}
	else if (ft_strcmp(query->object, RECORD) == 0)
	{
		ft_printf("!DELETE RECORD\n");
	}
	else
		ft_printf(RED"!BAD OBJECT (DELETE)\n"CLN);
}
