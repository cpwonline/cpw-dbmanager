/*
 * database.cc
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


#include "database.h"


Database::Database()
{
	
}

Database::~Database()
{
	
}

std::string Database::get_name() const
{
	return name_;
}


int Database::get_errno() const
{
	return errno_;
}

std::string Database::get_error() const
{
	return error_;
}

bool Database::get_state() const
{
	return state_;
}

void Database::set_name(std::string name)
{
	name_ = name;
}

void Database::set_error(std::string error)
{
	error_ = error;
}

void Database::set_errno(int errno)
{
	errno_ = errno;
}

void Database::set_state(bool state)
{
	state_ = state;
}