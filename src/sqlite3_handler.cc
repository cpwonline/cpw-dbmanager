/*
 * sqlite3.cc
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


#include "sqlite3_handler.h"


SQLite3Handler::SQLite3Handler()
{
	
}

SQLite3Handler::~SQLite3Handler()
{
	
}

bool SQLite3Handler::PrepareDatabase_()
{
	error_result_ = 0;

	// Open database
	//response_result_ = sqlite3_open(name_database_,& sqlite_object_);
	if (response_result_)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void SQLite3Handler::RunQuery_()
{
	//response_result_ = sqlite3_exec(sqlite_object_, query_sql_, NULL, 0,& error_result_);
	if (response_result_ != SQLITE_OK)
	{
		//fprintf(stderr, "\n   |--Error: %s", error_result_);
		//sqlite3_free(error_result_);
	}
	//else
		//fprintf(stdout, "\n   |--Result: Database and tables OK.");

}