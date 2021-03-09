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


#include <string>
#include <list>

#include "connection.h"
#include "database.h"
#include "handlers/mariadb_handler.h"
#include "handlers/mysql_handler.h"
#include "handlers/sqlite3_handler.h"

#ifndef CPW_DBMANAGER_H_
#define CPW_DBMANAGER_H_

class CPWDBManager
{
	public:
		CPWDBManager();
		~CPWDBManager();
		
	public:
		std::list<Database*>* get_databases_collector() const;
		std::list<Connection*>* get_connections_collector() const;
		
	public:
		enum TypeDB
		{
			MySQL,
			MariaDB,
			SQLite3
		};
		
	public:
		void CreateConnection_(TypeDB type, std::string internet_address, std::string port, std::string database_name, std::string username, std::string password);
		Connection* LastConnection_() const;
		
	protected:
		void CompleteMainSettings_(std::string database_name);
		void CompleteAddress_(std::string internet_address, std::string port);
		void CompleteAccessData_(std::string username, std::string password);
	
	private:
		std::list<Database*>* databases_collector_;
		std::list<Connection*>* connections_collector_;
};

#endif /* CPW_DBMANAGER_H_ */ 
