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
	set_state(true);
	mMariadb = mysql_init(NULL);
	if(mMariadb == NULL)
	{
		set_error((std::string)mysql_error(mMariadb));
		set_state(false);
		Disconnect_();
	}
}


MariaDBHandler::~MariaDBHandler()
{
	
}

void MariaDBHandler::Connect_(AccessData* access_data, Address* address)
{
	if(mysql_real_connect(mMariadb, address->get_internet_address().c_str(), access_data->get_username().c_str(), access_data->get_password().c_str(), NULL, 0 , NULL, 0) == NULL)
	{
		set_error((std::string)mysql_error(mMariadb));
		set_state(false);
		Disconnect_();
	}
	else
		set_state(true);
}

void MariaDBHandler::Disconnect_()
{
	mysql_close(mMariadb);
}