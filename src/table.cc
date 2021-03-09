/*
 * table.cc
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


#include "table.h"


Table::Table()
{
	columns_ = new std::list<Column*>;
}


Table::~Table()
{
	for(auto it = columns_->begin(); it != columns_->end(); ++it)
		delete (*it);
	delete columns_;
}

std::string Table::get_name() const
{
	return name_;
}

std::list<Column*>* Table::get_columns() const
{
	return columns_;
}

void Table::set_name(std::string name)
{
	name_ = name;
}