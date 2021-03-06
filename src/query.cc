/*
 * query.cc
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


#include "query.h"


Query::Query()
{
	
}

Query::~Query()
{
	
}

std::string Query::get_query() const
{
	return query_;
}

bool Query::get_state() const
{
	return state_;
}

int Query::get_times_used() const
{
	return times_used_;
}

void Query::set_query(std::string query)
{
	query_ = query;
}

void Query::set_state(bool state)
{
	state_ = state;
}

void Query::set_times_used(int times_used)
{
	times_used_ = times_used;
}