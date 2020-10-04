/*
 * connection.h
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

#include "handle_database.h"
#include "sqlite3_handler.h"
#include "mysql_handler.h"

#ifndef CONNECTION_H_
#define CONNECTION_H_

class Connection
{
	public:
		Connection();
		~Connection();
		
		std::string get_type_database() const;
		std::string get_server_address() const;
		std::string get_status() const;
		std::string get_name_database() const;
		std::string get_port_connection() const;
		std::string get_user() const;
		std::string get_password() const;
		void set_type_database(std::string type_database);
		void set_server_address(std::string server_address);
		void set_status(std::string status);
		void set_name_database(std::string name_database);
		void set_port_connection(std::string port_connection);
		void set_user(std::string user);
		void set_password(std::string password);
		
		bool Init_();
		bool End_();
		bool Restart_();
		bool ConnectedToDatabase_();
		
	protected:
		HandleDatabase* generic_database_;
		std::string type_database_, server_address_, status_, name_database_, port_connection_, user_, password_;
};

#endif /* CONNECTION_H_ */ 
