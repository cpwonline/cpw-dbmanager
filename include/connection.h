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

#include "handle_database.h"
#include "sqlite3_handler.h"
#include "mysql_handler.h"

#ifndef CONNECTION_H_
#define CONNECTION_H_

template <class DBObject>
class Connection
{
	public:
		Connection(char* type_database);
		~Connection();
		
	protected:
		bool Init_();
		bool End_();
		bool Restart_();
		char* type_, status_;
			
	private:
		DBObject generic_database_;
		HandleDatabase generic_handler_;
};

#endif /* CONNECTION_H_ */ 
