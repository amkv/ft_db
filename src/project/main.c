/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artem Kalmykov <akalmyko@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:15:23 by akalmyko          #+#    #+#             */
/*   Updated: 2017/05/03 16:16:08 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "db.h"

/* ft_db alpha version 0.0.1 */

int	main(void)
{
	t_db 	*database;

	database = NULL;
	ft_db("CREATE DATABASE: test", &database);
	ft_db("SET DEBUG", &database);
	ft_db("CREATE TABLE: PERSON", &database);
	ft_db("CREATE TABLE: AGE", &database);
	ft_db("IN TABLE: PERSON, SET TYPE: string, CREATE COLUMN: name", &database);
	ft_db("IN TABLE: PERSON, SET TYPE: string, CREATE COLUMN: family", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, CREATE RECORD: Artem", &database);
	ft_db("IN TABLE: PERSON, TO COLUMN: name, TO RECORD: Artem, IN COLUMN: family, SET TYPE: string, ADD RECORD: Kalmykov", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, CREATE RECORD: Vitaly", &database);
	ft_db("IN TABLE: PERSON, TO COLUMN: name, TO RECORD: Vitaly, IN COLUMN: family, SET TYPE: string, ADD RECORD: Tenigin", &database);
	ft_db("PRINT TABLE: PERSON", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, CREATE RECORD: Sergey", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, CREATE RECORD: Denis", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, CREATE RECORD: Michail", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, CREATE RECORD: Nikolay", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, CREATE RECORD: Evgeny", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, CREATE RECORD: Alex", &database);
	ft_db("IN TABLE: PERSON, PRINT COLUMN: name", &database);
	ft_db("IN TABLE: PERSON, TO COLUMN: name, TO RECORD: Michail, IN COLUMN: family, SET TYPE: string, ADD RECORD: Flipchuk", &database);
	ft_db("IN TABLE: PERSON, PRINT ROW: 7", &database);
	ft_db("IN TABLE: PERSON, TO COLUMN: name, TO RECORD: Evgeny, IN COLUMN: family, SET TYPE: string, ADD RECORD: Chelovek", &database);
	ft_db("IN TABLE: PERSON, PRINT ROW: 7", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: family, IN RECORD: Chelovek, CHANGE RECORD: neoworld", &database);
	ft_db("IN TABLE: PERSON, PRINT ROW: 7", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: family, DELETE RECORD: neoworld", &database);
	ft_db("IN TABLE: PERSON, PRINT ROW: 7", &database);
	ft_db("IN TABLE: AGE, SET TYPE: int, CREATE COLUMN: age", &database);
	ft_db("IN TABLE: AGE, IN COLUMN: age, SET TYPE: int, CREATE RECORD: 30", &database);
	ft_db("IN TABLE: AGE, IN COLUMN: age, SET TYPE: int, CREATE RECORD: 29", &database);
	ft_db("PRINT TABLE: AGE", &database);
	ft_db("IN TABLE: AGE, IN COLUMN: age, IN RECORD: 30, CHANGE RECORD: 99", &database);
	ft_db("PRINT DATABASE", &database);
	ft_db("DUMP DATABASE: dump_database.txt", &database);
	ft_db("FLUSH DATABASE: test", &database);
	return (EXIT_SUCCESS);
}
