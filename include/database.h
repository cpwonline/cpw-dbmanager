/*
 * database.h
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

#include "query.h"
#include "result.h"
#include "table.h"
#include "access_data.h"
#include "address.h"

#ifndef DATABASE_H
#define DATABASE_H

class Database
{
	public:
		Database();
		virtual ~Database();
		
	public:
		std::string get_name() const;
		void set_name(std::string name);
	
	public:
		virtual void Connect_(AccessData* access_data, Address* address) = 0;
			
	private:
		std::string name_;
		
};

#endif /* DATABASE_H */ 
