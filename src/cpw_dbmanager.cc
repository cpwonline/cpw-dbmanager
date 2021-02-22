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
	databases_collector_ = new std::map<int, Database*>;
	connections_collector_ = new std::map<int, Connection*>;
}

CPWDBManager::~CPWDBManager()
{
	for(auto it = databases_collector_->begin(); it != databases_collector_->end(); ++it)
		delete it->second;
	databases_collector_->clear();
	
	for(auto it = connections_collector_->begin(); it != connections_collector_->end(); ++it)
		delete it->second;
	connections_collector_->clear();
}
