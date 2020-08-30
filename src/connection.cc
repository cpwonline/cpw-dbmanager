/*
 * connection.cc
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


#include "connection.h"


Connection::Connection(char* type_database)
{
	if(std::strcmp(type_database, "sqlite3"))
		generic_database_ = new SQLite3();
	else if(std::strcmp(type_database, "mysql"))
		generic_database_ = new MySQL();
		
	* generic_handler_ = & generic_database_;
}

Connection::~Connection()
{
	delete generic_database_;
}


