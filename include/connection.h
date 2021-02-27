/*
 * connection.h
 * 
 * Copyright 2021 Jose Felix Rivas Carrasco <josefelixrc@outlook.com>
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

 #include "access_data.h"
 #include "address.h"
 #include "database.h"

#ifndef CONNECTION_H
#define CONNECTION_H

class Connection
{
	public:
		Connection(Database* database);
		virtual ~Connection();
		
	public:
		Database* get_connected_database() const;
		AccessData* get_current_access_data() const;
		Address* get_current_address() const;
		
	public:
		void Init_();
	
	private:
		Database* connected_database_;
		AccessData* current_access_data_;
		Address* current_address_;
};

#endif /* CONNECTION_H */ 
