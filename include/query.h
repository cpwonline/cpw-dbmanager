/*
 * query.h
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

#ifndef QUERY_H
#define QUERY_H

class Query
{
	public:
		Query();
		virtual ~Query();
		
	public:
		std::string get_query() const;
		bool get_state() const;
		int get_times_used() const;
		std::string get_error() const;
		
	public:
		void set_query(std::string query);
		void set_state(bool state);
		void set_times_used(int times_used);
		void set_error(std::string);
			
	private:
		std::string query_, error_;
		bool state_;
		int times_used_;
};

#endif /* QUERY_H */ 
