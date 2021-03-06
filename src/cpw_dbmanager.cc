/*
 * cpw_dbmanager.cc
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


#include "cpw_dbmanager.h"


CPWDBManager::CPWDBManager()
{
	databases_collector_ = new std::list<Database*>;
	connections_collector_ = new std::list<Connection*>;
}

CPWDBManager::~CPWDBManager()
{
	for(auto it = databases_collector_->begin(); it != databases_collector_->end(); ++it) delete *it;
	delete databases_collector_;
	
	for(auto it = connections_collector_->begin(); it != connections_collector_->end(); ++it) delete *it;
	delete connections_collector_;
}

std::list<Database*>* CPWDBManager::get_databases_collector() const
{
	return databases_collector_;
}

std::list<Connection*>* CPWDBManager::get_connections_collector() const
{
	return connections_collector_;
}

void CPWDBManager::CreateConnection_(TypeDB type, std::string internet_address, std::string port, std::string database_name, std::string username, std::string password)
{
	switch(type)
	{
		case TypeDB::MariaDB:
		{
			databases_collector_->push_back(new MariaDBHandler());
			break;
		}
		case TypeDB::MySQL:
		{
			databases_collector_->push_back(new MySQLHandler());
			break;
		}
		case TypeDB::SQLite3:
		{
			databases_collector_->push_back(new SQLite3Handler());
			break;
		}
	}
	CompleteMainSettings_(database_name);
	CompleteAddress_(internet_address, port);
	CompleteAccessData_(username, password);
}

void CPWDBManager::CompleteMainSettings_(std::string database_name)
{
	connections_collector_->push_back(new Connection(databases_collector_->back()));
	connections_collector_->back()->get_connected_database()->set_name(database_name);
}

void CPWDBManager::CompleteAddress_(std::string internet_address, std::string port)
{
	connections_collector_->back()->get_current_address()->set_internet_address(internet_address);
	connections_collector_->back()->get_current_address()->set_port(port);
}

void CPWDBManager::CompleteAccessData_(std::string username, std::string password)
{
	connections_collector_->back()->get_current_access_data()->set_username(username);
	connections_collector_->back()->get_current_access_data()->set_password(password);
}