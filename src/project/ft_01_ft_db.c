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

void			ft_print_db_error(t_db *database)
{
	if (!database)
		return ;
	if (database->error)
	{
		ft_printf("%s\n", database->nameError);
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
//	ft_db_null_query(query);
//	free(query);
//	ft_db_free_query(query);
	return (0);
}
