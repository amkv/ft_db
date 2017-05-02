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
//	t_db 	*database2;

/* first database */
	database = NULL;
	ft_db("CREATE DATABASE: test", &database);
	ft_db("SET DEBUG", &database);
//	ft_db("CREATE TABLEs: PERSON", &database);
	ft_db("CREATE TABLE: PERSON", &database);
	ft_db("CREATE TABLE: AGE", &database);

	ft_db("IN TABLE: PERSON, SET TYPE: string, CREATE COLUMN: name", &database);
	ft_db("IN TABLE: PERSON, SET TYPE: string, CREATE COLUMN: family", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, ADD RECORD: Artem", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, ADD RECORD: Vitaly", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, ADD RECORD: Michail", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, ADD RECORD: Sergey", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, ADD RECORD: Denis", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, ADD RECORD: Nikolay", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: name, SET TYPE: string, ADD RECORD: Evgeny", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: family, SET TYPE: string, ADD RECORD: Kalmykov", &database);
	ft_db("IN TABLE: PERSON, IN COLUMN: family, SET TYPE: string, ADD RECORD: Tenigin", &database);

	ft_db("IN TABLE: AGE, SET TYPE: int, CREATE COLUMN: age", &database);
	ft_db("IN TABLE: AGE, IN COLUMN: age, SET TYPE: int, ADD RECORD: 30", &database);
	ft_db("IN TABLE: AGE, IN COLUMN: age, SET TYPE: int, ADD RECORD: 29", &database);

	ft_db("PRINT TABLE: AGE", &database);
	ft_db("PRINT TABLE: PERSON", &database);

	ft_db("IN TABLE: PERSON, PRINT COLUMN: name", &database);
	ft_db("IN TABLE: PERSON, PRINT COLUMN: family", &database);
	ft_db("IN TABLE: PERSON, PRINT ROW: 1", &database);

	ft_db("PRINT DATABASE", &database);
	ft_db("DUMP DATABASE: dump_database.txt", &database);
	ft_db("FLUSH DATABASE: test", &database);

/* second database */
//	ft_db("CREATE DATABASE: second db", &database2);
//	ft_db("CREATE TABLE: PHONES", &database2);
//	ft_db("IN TABLE: PHONES, SET TYPE: int, CREATE COLUMN: number", &database2);
//	ft_db("IN TABLE: PHONES, IN COLUMN: number, SET TYPE: int, ADD RECORD: 1234", &database2);
//	ft_db("PRINT DATABASE", &database2);
//	ft_db("DUMP DATABASE: dump_database2.txt", &database2);
//	ft_db("FLUSH DATABASE: test", &database2);
	return (EXIT_SUCCESS);
}
