/*
 * cpw_dbmanager.h
 * 
 * Copyright 2020 Jose Felix Rivas Carrasco <josefelixrc@outlook.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <string>
#include <vector>

#include "connection.h"
#include "handle_database.h"
#include "sqlite3_handler.h"
#include "mysql_handler.h"

#ifndef CPW_DBMANAGER_H_
#define CPW_DBMANAGER_H_

class CPWDBManager
{
	public:
		CPWDBManager();
		~CPWDBManager();
		
		void NewConnection_(string type_connection, string name_database, string port_connection, string user, string password);
		void DeleteConnection_(int number_connection);
		void DeleteLastConnection_();
		Connection* ViewConnection_(int number_connection);
		bool ConnectionEmpty_();
		int TotalConnections_();
		
	protected:
		std::vector<Connection>* connections_handler_;
		std::vector<Connection>::iterator iterator_handler_;
};

#endif /* CPW_DBMANAGER_H_ */ 
