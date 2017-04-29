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

	database = NULL;
	ft_db("CREATE DATABASE: test", &database);
	ft_db("SET DEBUG", &database);

	ft_db("CREAsTE TAdBLE: PERSON", &database);
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
	ft_db("PRINT DATABASE", &database);
	ft_db("DUMP DATABASE: test", &database);
	ft_db("FLUSH DATABASE: test", &database);
	return (EXIT_SUCCESS);
}
