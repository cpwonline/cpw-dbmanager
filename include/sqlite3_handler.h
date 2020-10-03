/*
 * sqlite3.h
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
 
 #include <sqlite3.h>
 
 #include <cstring>
 #include <cstdlib>
 
 #include "handle_database.h"


#ifndef SQLITE3_HANDLER_H_
#define SQLITE3_HANDLER_H_

class SQLite3Handler : public HandleDatabase
{
	public:
		SQLite3Handler();
		virtual ~SQLite3Handler();
		virtual bool PrepareDatabase_();
		virtual void RunQuery_();
			
	private:
		sqlite3* sqlite3_object_;
};

#endif /* SQLITE3_HANDLER_H_ */ 
