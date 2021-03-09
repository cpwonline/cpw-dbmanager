#include <iostream>

#include "gtest/gtest.h"
#include "cpw_dbmanager.h"

class TestGen : public ::testing::Test
{
	protected:
		void SetUp() override;
		void TearDown() override;

		CPWDBManager *TestObj_;
};

//-----------------------------------------------------------------------------

void TestGen::SetUp()
{
	TestObj_ = new CPWDBManager();
}

void TestGen::TearDown()
{
    delete TestObj_;
}

//-----------------------------------------------------------------------------

TEST_F(TestGen, ViewData)
{
	std::cout << "\n- ViewData";
	
	TestObj_->CreateConnection_(CPWDBManager::TypeDB::MariaDB, "localhost", "3033", "test", "root", "26552160jfrc");
	
	int a = 0;
	for(auto it = TestObj_->get_connections_collector()->begin(); it != TestObj_->get_connections_collector()->end(); ++it)
	{
		std::cout << "\n-- " << ++a
			<< "\n--- Database: " << (*it)->get_connected_database()->get_name()
			<< "\n--- Access data: " << (*it)->get_current_access_data()->get_username() << ", " << (*it)->get_current_access_data()->get_password()
			<< "\n--- Address: " << (*it)->get_current_address()->get_internet_address() << ", " << (*it)->get_current_address()->get_port()
		;
	}
	std::cout << "\n-\n";
	
	ASSERT_GT(a, 0);
}

TEST_F(TestGen, InitDatabase)
{
	std::cout << "\n- InitDatabase";
	
	TestObj_->CreateConnection_(CPWDBManager::TypeDB::MariaDB, "localhost", "3033", "test", "root", "26552160jfrc");
	auto it = TestObj_->get_connections_collector()->back(); 
	if(it != nullptr)
	{
		it->Init_();
		ASSERT_TRUE(it->get_connected_database()->get_state());
		if(it->get_connected_database()->get_state())
		{
			std::cout << "\n-- Conectado";
		}
		it->get_connected_database()->Disconnect_();
	}
	
	std::cout << "\n-\n";
}

TEST_F(TestGen, TestQuery)
{
	std::cout << "\n- TestQuery";
	
	// Create the connection
	TestObj_->CreateConnection_(CPWDBManager::TypeDB::MariaDB, "localhost", "3033", "test", "root", "26552160jfrc");
	
	// See the last connection
	auto it = TestObj_->get_connections_collector()->back(); 
	if(it != nullptr)
	{
		// Init the database connection
		it->Init_();
		
		// View the database connection
		if(it->get_connected_database()->get_state())
		{
			// Insert queries
			it->NewQuery_("CREATE DATABASE test2;");
			it->NewQuery_("CREATE DATABASE test3;");
			it->NewQuery_("CREATE DATABASE test3;");
			it->NewQuery_("CREATE DATABASE test4;");
			it->NewQuery_("CREAT DATABASE test4;");
			it->NewQuery_("DROP DATABASE test2;");
			it->NewQuery_("DROP DATABASE test3;");
			it->NewQuery_("DROP DATABASE test4;");
			
			// View states and results of queries
			int a = 0;
			for(auto it2 = it->get_queries()->begin(); it2 != it->get_queries()->end(); ++it2)
			{
				std::cout << "\n-- " << ++a;
				if((*it2)->get_state())
				{
					std::cout << "\n--- Consulta: " << (*it2)->get_query();
					std::cout << "\n--- Veces usada: " << (*it2)->get_times_used();
				}
				else
					std::cout << "\n--- Error de consulta: " << (*it2)->get_error();
				a++;
			}
		}
		else
			std::cout << "\n-- Error en la base: " << it->get_connected_database()->get_error();
			
		// Disconnect from the database
		it->get_connected_database()->Disconnect_();
	}
	
	std::cout << "\n-\n";
}

TEST_F(TestGen, ViewResults)
{
	std::cout << "\n- ViewResults";
	
	// Create the connection
	TestObj_->CreateConnection_(CPWDBManager::TypeDB::MariaDB, "localhost", "3033", "test", "root", "26552160jfrc");
	
	// See the last connection
	auto it = TestObj_->get_connections_collector()->back(); 
	if(it != nullptr)
	{
		// Init the database connection
		it->Init_();
		
		// View the database connection
		if(it->get_connected_database()->get_state())
		{
			// Insert queries
			it->NewQuery_("SELECT * FROM table1;", true);
			it->NewQuery_("SELECT * FROM carros;", true);
			it->NewQuery_("SELECT * FROM carro;", true);
			
			// View states and results of queries
			int a = 0;
			for(auto it2 = it->get_queries_results()->begin(); it2 != it->get_queries_results()->end(); ++it2)
			{
				std::cout << "\n-- " << ++a;
				if(it2->first->get_state())
				{
					std::cout << "\n--- Consulta: " << it2->first->get_query();
					std::cout << "\n--- Veces usada: " << it2->first->get_times_used();
					std::cout << "\n--- Resultados: ";
					
					auto results = it2->second->get_results_table()->get_columns();
					int b = 0;
					for(auto col = results->begin(); col != results->end(); ++col)
					{
						std::cout << "\n---- " << b << ". Columna";
						for(auto value = (*col)->get_row()->get_values()->begin(); value != (*col)->get_row()->get_values()->end(); ++value)
							std::cout << "\n----- Key: " << value->first << ", value: " << value->second;
						b++;
					}
				}
				else
					std::cout << "\n --- Error de consulta: " << it2->first->get_error();
				a++;
			}
		}
		else
			std::cout << "\n -- Error en la base: " << it->get_connected_database()->get_error();
			
		// Disconnect from the database
		it->get_connected_database()->Disconnect_();
	}
	
	std::cout << "\n-\n";
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}