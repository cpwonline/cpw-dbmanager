/*
 * connection.cc
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


#include "connection.h"


Connection::Connection(Database* database) :
	connected_database_(database)
{
	current_access_data_ = new AccessData();
	current_address_ = new Address();
	queries_ = new std::list<Query*>;
	results_ = new std::list<Result*>;
	queries_results_ = new std::map<Query*, Result*>;
}

Connection::~Connection()
{
	delete current_access_data_;
	delete current_address_;
	
	for(auto it = queries_results_->begin(); it != queries_results_->end(); ++it) 
	{
		delete (*it).first;
		delete (*it).second;
	}
	delete queries_results_;
	delete queries_;
	delete results_;
}

Database* Connection::get_connected_database() const
{
	return connected_database_;
}

AccessData* Connection::get_current_access_data() const
{
	return current_access_data_;
}

Address* Connection::get_current_address() const
{
	return current_address_;
}

std::list<Query*>* Connection::get_queries() const
{
	return queries_;
}

std::list<Result*>* Connection::get_results() const
{
	return results_;
}

std::map<Query*, Result*>* Connection::get_queries_results() const
{
	return queries_results_;
}

void Connection::Init_()
{
	connected_database_->Connect_(current_access_data_, current_address_);
}

void Connection::NewQuery_(std::string query, bool load_data)
{
	queries_->push_back(new Query());
	results_->push_back(new Result());
	queries_results_->emplace(queries_->back(), results_->back());
	queries_->back()->set_query(query);
	connected_database_->Query_(queries_->back());
	if(load_data)
		connected_database_->LoadData_(results_->back());
}