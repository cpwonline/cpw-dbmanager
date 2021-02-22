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
#include <map>

#include "connection.h"
#include "database.h"

#ifndef CPW_DBMANAGER_H_
#define CPW_DBMANAGER_H_

class CPWDBManager
{
	public:
		CPWDBManager();
		~CPWDBManager();
		
		/*Connections*/
		void CreateConnection_(std::string type_database);
		void ServerConfigs_(std::string server_address, std::string port_connection);
		void DeleteConnection_(int number_connection);
		void DeleteLastConnection_();
		Connection* ViewConnection_(int number_connection);
		void ShowConnections_();
		bool ConnectionEmpty_();
		int TotalConnections_();
		
		/* Databases */
		void DatabaseConfigs_(std::string name_database, std::string user, std::string password);
		
	protected:
		std::map<int, Database*> databases_collector_;
		std::map<int, Connection*> connections_collector;
};

#endif /* CPW_DBMANAGER_H_ */ 
