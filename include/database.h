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
		int get_errno() const;
		std::string get_error() const;
		bool get_state() const;
		std::string get_name() const;
		void set_name(std::string name);
	
	public:
		virtual bool Connect_(AccessData* access_data, Address* address) = 0;
		virtual bool Disconnect_() = 0;
		virtual bool Query_(Query* query, Result* result) = 0;
		
	protected:
		void set_errno(int errno);
		void set_error(std::string error);
		void set_state(bool state);
		
	protected:
		virtual bool Init_() = 0;
			
	private:
		int errno_;
		std::string name_, error_;
		bool state_;
		
};

#endif /* DATABASE_H */ 
