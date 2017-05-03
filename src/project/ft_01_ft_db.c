/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_01_ft_db.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 21:09:47 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 15:56:11 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

void			ft_print_db_error(t_db *database)
{
	if (!database)
		return ;
	if (database->error)
	{
		ft_printf(RED"%s\n"CLN, database->nameError);
		ft_clean_error(database);
	}
}

int 			ft_db(const char *restrict format, ...)
{
	va_list		list;
	t_query		*query;

	if (!format)
		return (0);
	query = NULL;
	va_start(list, format);
	ft_db_parser(&query, format);
	ft_db_action(query, list);
	va_end(list);
	return (0);
}
