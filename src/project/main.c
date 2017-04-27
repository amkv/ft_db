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

int 			ft_is_all_print(const char *str)
{
	if (!str)
		return (0);
	while(ft_isprint(*str))
		str++;
	if (*str == '\0')
		return (1);
	else
		return (0);
}

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

int	main(void)
{
	t_db 	*database;

	database = ft_init_db("My fisrt DB");
	if (!database)
		return (EXIT_FAILURE);
	ft_new_table(database, "First table");
	ft_new_table(database, "Second table");
	ft_new_table(database, "Third table");
	ft_new_table(database, NULL);
	ft_new_column(database, "First table", "Column 1", "string");
	ft_new_column(database, "First table", "Column 2", "string");
	ft_new_column(database, "First table", "last", "int");
	ft_new_column(database, "Second table", "Column 1", "string");
	ft_new_column(database, "Second table", "Column 2", "string");
	ft_new_column(database, "dfg", "Column 2", "string");
	ft_new_record(database, "First table", "Column 2", "string", "!REC!!!");
	ft_new_record(database, "First table", "Column 1", "string", "AZTEC!");
	ft_new_record(database, "First table", "Column 1", "string", "CHELOVEK");
	ft_new_record(database, "First table", "last", "string", (void*)42);
	ft_new_record(database, "Second table", "Column 1", "string", "TEST");
//	ft_add_record(database, "First table", "Column 1", "string", "id", "AZTEC!");
//	ft_delete_record(database, "First table", "Column 1", "string", "id", "AZTEC!");

//	database = NULL;
//	ft_db(&database, "CREATE_DB:test, CREATE_TABLE:table1, CREATE_COLUMN:column1");
//	ft_db(&database, "ADD_RECORD:test record");
//	ft_printf("result: %d", ft_db("CREATE DATABASE: TEST, CREATE TABLE: ANOTHER test, CREATE COLUMN: My column, TYPE COLUMN:int"));
//	ft_printf("main: %p\n", &database);
//	ft_db("CREATE DATABASE: test", &database);
//	ft_printf("main after:  %p\n", database);
//	ft_printf("main &after: %p\n", &database);

	ft_print_all_records(database);
//	free(all);
	return (EXIT_SUCCESS);
}
