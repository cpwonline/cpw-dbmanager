/*
 * connection.h
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


#ifndef CONNECTION_H_
#define CONNECTION_H_

class Connection
{
	public:
		Connection();
		~Connection();
		
		string get_type() const;
		string get_status() const;
		string get_name_database() const;
		string get_port_connection() const;
		string get_user() const;
		string get_password() const;
		void set_type(string type);
		void set_status(string status);
		void set_name_database(string name_database);
		void set_port_connection(string port_connection);
		void set_user(string user);
		void set_password(string password);
		
		void ReceiveData_();
		bool Init_();
		bool End_();
		bool Restart_();
		
		bool connected_to_database_;
		
	private:
		HandleDatabase* generic_database_;
		string type_, status_, name_database_, port_connection_, user_, password_;
};

#endif /* CONNECTION_H_ */ 
