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
}

Connection::~Connection()
{
	delete current_access_data_;
	delete current_address_;
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

void Connection::Init_()
{
	connected_database_->Connect_(current_access_data_, current_address_);
}