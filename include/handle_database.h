/*
 * database.h
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
 
 
#ifndef HANDLE_DATABASE_H_
#define HANDLE_DATABASE_H_

class HandleDatabase
{
	public:
		virtual bool PrepareDatabase_() = 0;
		virtual void PrepareQuery_() = 0;
		virtual void RunQuery_() = 0;
			
	protected:
		char* query_sql_, name_database_;
		char* error_result_;
		short int response_result_;
};

#endif /* HANDLE_DATABASE_H_ */ 
