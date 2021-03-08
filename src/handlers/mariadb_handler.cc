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
	mMariadb_ = mysql_init(NULL);
	if(mMariadb_ == NULL)
	{
		set_state(false);
		set_error((std::string)mysql_error(mMariadb_));
		return false;
	}
}

bool MariaDBHandler::Connect_(AccessData* access_data, Address* address)
{
	if(mMariadb_ == NULL)
	{
		set_state(false);
		set_error((std::string)mysql_error(mMariadb_));
		return false;
	}
	if(mysql_real_connect(mMariadb_, address->get_internet_address().c_str(), access_data->get_username().c_str(), access_data->get_password().c_str(), NULL, 0 , NULL, 0) == NULL)
	{
		set_state(false);
		set_error((std::string)mysql_error(mMariadb_));
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
		mysql_close(mMariadb_);
		set_state(false);
		return true;
	}
	else
		return false;
}

bool MariaDBHandler::Query_(Query* query, Result* result)
{
	if(mMariadb == NULL)
	{
		set_error((std::string)mysql_error(mMariadb));
		Disconnect_();
		return false;
	}
	if(!query->get_state())
	{
		Disconnect_();
		return false;
	}
	if(mysql_query(mMariadb, "SHOW DATABASES;"))
	{
		query->set_state(false);
		set_error((std::string)mysql_error(mMariadb));
		Disconnect_();
		return false;
	}
	else
	{
		set_state(true);
		return true;
	}
}