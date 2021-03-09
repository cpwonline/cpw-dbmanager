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
#include <list>
#include <map>

 #include "access_data.h"
 #include "address.h"
 #include "database.h"
 #include "result.h"
 #include "query.h"

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
		std::list<Query*>* get_queries() const;
		std::list<Result*>* get_results() const;
		std::map<Query*, Result*>* get_queries_results() const;
		
	public:
		void Init_();
		void NewQuery_(std::string query, bool load_data = false);
	
	private:
		Database* connected_database_;
		AccessData* current_access_data_;
		Address* current_address_;
		std::list<Query*>* queries_;
		std::list<Result*>* results_;
		std::map<Query*, Result*>* queries_results_;
};

#endif /* CONNECTION_H */ 
