/*
 * connection.cc
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


#include "connection.h"

Connection::Connection() :
	generic_database_(nullptr),
	type_database_("Unknown"),
	server_address_("127.0.0.1"),
	status_("Not connected."),
	name_database_("Unknown"),
	user_("Unknown"),
	password_("")
{
}

Connection::~Connection()
{
	
}
std::string Connection::get_type_database() const
{
	return type_database_;
}
std::string Connection::get_server_address() const
{
	return server_address_;
}

std::string Connection::get_status() const
{
	return status_;
}

std::string Connection::get_name_database() const
{
	return name_database_;
}

std::string Connection::get_port_connection() const
{
	return port_connection_;
}

std::string Connection::get_user() const
{
	return user_;
}

std::string Connection::get_password() const
{
	return password_;
}

void Connection::set_type_database(std::string type_database)
{
	type_database_ = type_database;
}

void Connection::set_server_address(std::string server_address)
{
	server_address_ = server_address;
}

void Connection::set_status(std::string status)
{
	status_ = status;
}

void Connection::set_name_database(std::string name_database)
{
	name_database_ = name_database;
}

void Connection::set_port_connection(std::string port_connection)
{
	port_connection_ = port_connection;
}

void Connection::set_user(std::string user)
{
	user_ = user;
}

void Connection::set_password(std::string password)
{
	password_ = password;
}
		
bool Connection::Init_()
{
	if(type_database_ == "sqlite3")
	{
		generic_database_ = new SQLite3Handler;
		status_ = "Connection init.";
		return true;
	}
	else if(type_database_ == "mysql")
	{
		generic_database_ = new MySQLHandler;
		status_ = "Connection init.";
		return true;
	}
	else
	{
		status_ = "Connection failed.";
		return false;
	}
}

bool Connection::Restart_()
{
	if(generic_database_ == nullptr)
	{
		status_ = "Not connection found.";
		return false;
	}
	else
	{
		delete generic_database_;
		return Init_();
	}
}

bool Connection::End_()
{
	if(generic_database_ == nullptr)
	{
		status_ = "Not connection found.";
		return false;
	}
	else
	{
		status_ = "Connection closed.";
		delete generic_database_;
		return true;
	}
}