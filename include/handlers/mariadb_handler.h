/*
 * mariadb_handler.h
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


#include <mysql.h>

#include "database.h"

#ifndef MARIADB_HANDLER_H
#define MARIADB_HANDLER_H

class MariaDBHandler : public Database
{
	public:
		MariaDBHandler();
		virtual ~MariaDBHandler();
		
		bool Connect_(AccessData* access_data, Address* address);
		bool Disconnect_();
		bool Query_(Query* query);
		bool LoadData_(Result* result);
		
	protected:
		bool Init_();
	
	private:
		MYSQL* mariadb_object_;
		MYSQL_RES* mariadb_results_;
		MYSQL_ROW mariadb_row_;
		MYSQL_FIELD* mariadb_field_;
		int num_fields_;
};

#endif /* MARIADB_HANDLER_H */ 
