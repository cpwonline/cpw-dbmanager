/*
 * mariadb_handler.cc
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


#include "handlers/mariadb_handler.h"


MariaDBHandler::MariaDBHandler()
{
	Init_();
}


MariaDBHandler::~MariaDBHandler()
{
	
}

bool MariaDBHandler::Init_()
{
	mariadb_object_ = mysql_init(NULL);
	if(mariadb_object_ == NULL)
	{
		set_state(false);
		set_error((std::string)mysql_error(mariadb_object_));
		return false;
	}
	return true;
}

bool MariaDBHandler::Connect_(AccessData* access_data, Address* address)
{
	if(mariadb_object_ == NULL)
	{
		set_state(false);
		set_error((std::string)mysql_error(mariadb_object_));
		return false;
	}
	if(mysql_real_connect(mariadb_object_, address->get_internet_address().c_str(), access_data->get_username().c_str(), access_data->get_password().c_str(), get_name().c_str(), 0 , NULL, 0) == NULL)
	{
		set_state(false);
		set_error((std::string)mysql_error(mariadb_object_));
		Disconnect_();
		return false;
	}
	else
	{
		set_state(true);
		return true;
	}
}

bool MariaDBHandler::Disconnect_()
{
	if(get_state())
	{
		mysql_close(mariadb_object_);
		set_state(false);
		return true;
	}
	else
		return false;
}

bool MariaDBHandler::Query_(Query* query)
{
	if(mariadb_object_ == NULL)
	{
		set_state(false);
		set_error((std::string)mysql_error(mariadb_object_));
		return false;
	}
	if(!query->get_state())
	{
		set_error("Error on query.");
		return false;
	}
	if(mysql_query(mariadb_object_, query->get_query().c_str()))
	{
		query->set_state(false);
		query->set_error((std::string)mysql_error(mariadb_object_));
		return false;
	}
	else
	{
		query->set_times_used(query->get_times_used() + 1);
		set_state(true);
		return true;
	}
}

bool MariaDBHandler::LoadData_(Result* result)
{
}