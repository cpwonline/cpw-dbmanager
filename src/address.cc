/*
 * address.cc
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


#include "address.h"


Address::Address()
{
	
}

Address::~Address()
{
	
}

std::string Address::get_internet_address() const
{
	return internet_address_;
}

std::string Address::get_port() const
{
	return port_;
}

void Address::set_internet_address(std::string internet_address)
{
	internet_address_ = internet_address;
}

void Address::set_port(std::string port)
{
	port_ = port;
}