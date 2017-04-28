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

int	main(void)
{
	t_db 	*database;

//	database = ft_init_db("My fisrt DB");
//	if (!database)
//		return (EXIT_FAILURE);
//	ft_new_table(database, "First table");
//	ft_new_table(database, "Second table");
//	ft_new_table(database, "Third table");
//	ft_new_table(database, NULL);
//	ft_new_column(database, "First table", "Column 1", "string");
//	ft_new_column(database, "First table", "Column 2", "string");
//	ft_new_column(database, "First table", "last", "int");
//	ft_new_column(database, "Second table", "Column 1", "string");
//	ft_new_column(database, "Second table", "Column 2", "string");
//	ft_new_column(database, "dfg", "Column 2", "string");
//	ft_new_record(database, "First table", "Column 2", "string", "!REC!!!");
//	ft_new_record(database, "First table", "Column 1", "string", "AZTEC!");
//	ft_new_record(database, "First table", "Column 1", "string", "CHELOVEK");
//	ft_new_record(database, "First table", "last", "string", (void*)42);
//	ft_new_record(database, "First table", "last", "string", (void*)1);
//	ft_new_record(database, "Second table", "Column 1", "string", "TEST");
//	ft_add_record(database, "First table", "Column 1", "string", "id", "AZTEC!");
//	ft_delete_record(database, "First table", "Column 1", "string", "id", "AZTEC!");

	database = NULL;

	ft_db("CREATE DATABASE: test", &database);
	ft_db("CREATE TABLE: PERSON", &database);
	ft_db("CREATE TABLE: AGE", &database);
	ft_db("IN TABLE: PERSON, SET TYPE: string, CREATE COLUMN: name", &database);
	ft_db("IN TABLE: PERSON, SET TYPE: string, CREATE COLUMN: family", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, ADD RECORD: Artem", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, ADD RECORD: Vitaly", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: family, SET TYPE: string, ADD RECORD: Kalmykov", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: family, SET TYPE: string, ADD RECORD: Tenigin", &database);

	ft_db("IN TABLE: AGE, SET TYPE: int, CREATE COLUMN: age", &database);
	ft_db("IN TABLE: AGE, IN COLUMN: age, SET TYPE: int, ADD RECORD: 30", &database);
	ft_db("IN TABLE: AGE, IN COLUMN: age, SET TYPE: int, ADD RECORD: 30", &database);

//	ft_db("IN TABLE: new table, IN COLUMN: second table, ADD RECORD: test", &database);

//	ft_db("CREATE COLUMN: first column, TABLE: new table", &database);
// 	ft_db(&database, "CREATE_DB:test, CREATE_TABLE:table1, CREATE_COLUMN:column1");
//	ft_db(&database, "ADD_RECORD:test record");
//	ft_printf("result: %d", ft_db("CREATE DATABASE: TEST, CREATE TABLE: ANOTHER test, CREATE COLUMN: My column, TYPE COLUMN:int"));

	ft_db_print_all_db(database);
//	ft_db_dump(database, "test");
//	free(all);
	return (EXIT_SUCCESS);
}
