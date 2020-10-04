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
	connections_handler_ = new std::vector<Connection*>;
}

CPWDBManager::~CPWDBManager()
{
	for(int a = 0; a < connections_handler_->size(); a++) delete (*connections_handler_)[a];
	delete connections_handler_;
}

void CPWDBManager::NewConnection_(std::string type_database)
{
	connections_handler_->push_back(new Connection());
	auto last_connection = connections_handler_->back();
	last_connection->set_type_database(type_database);
}

void CPWDBManager::ServerConfigs_(std::string server_address, std::string port_connection)
{
	auto last_connection = connections_handler_->back();
	last_connection->set_server_address(server_address);
	last_connection->set_port_connection(port_connection);
}
void CPWDBManager::DatabaseConfigs_(std::string name_database, std::string user, std::string password)
{
	auto last_connection = connections_handler_->back();
	last_connection->set_name_database(name_database);
	last_connection->set_user(user);
	last_connection->set_password(password);
}

void CPWDBManager::DeleteConnection_(int number_connection)
{
	//connections_handler_->erase(number_connection);
}

void CPWDBManager::DeleteLastConnection_()
{
	//connections_handler_->erase(connections_handler_->end());
}

Connection* CPWDBManager::ViewConnection_(int number_connection)
{
	Connection* connection_requested = connections_handler_->at(number_connection);
	return connection_requested;
}

void CPWDBManager::ShowConnections_()
{
	int c = 0;
	for(int a = 0; a <  (int)connections_handler_->size(); a++)
	{
		auto h = connections_handler_->at(a);
		std::cout << "\n" << c++ << ". " << h->get_name_database() << ", " << h->get_status();
		std::cout << "(" << h->get_server_address() << ":" << h->get_port_connection() << ")";
	}
}

bool CPWDBManager::ConnectionEmpty_()
{
	if(connections_handler_->empty())
		return true;
	else
		return false;
}

int CPWDBManager::TotalConnections_()
{
	return connections_handler_->size();
}