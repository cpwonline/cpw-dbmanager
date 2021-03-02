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
	std::cout << "\n-- ViewData";
	
	TestObj_->CreateConnection_(CPWDBManager::TypeDB::MariaDB, "localhost", "3033", "test", "root", "26552160jfrc");
	
	int a = 0;
	for(auto it = TestObj_->get_connections_collector()->begin(); it != TestObj_->get_connections_collector()->end(); ++it)
	{
		std::cout << "\n" << ++a
			<< "\n- Database: " << (*it)->get_connected_database()->get_name()
			<< "\n- Access data: " << (*it)->get_current_access_data()->get_username() << ", " << (*it)->get_current_access_data()->get_password()
			<< "\n- Address: " << (*it)->get_current_address()->get_internet_address() << ", " << (*it)->get_current_address()->get_port()
		;
	}
	std::cout << "\n--\n";
	
	ASSERT_GT(a, 0);
}

TEST_F(TestGen, InitDatabase)
{
	std::cout << "\n-- InitDatabase";
	
	TestObj_->CreateConnection_(CPWDBManager::TypeDB::MariaDB, "localhost", "3033", "test", "root", "26552160jfrc");
	auto it = TestObj_->get_connections_collector()->back(); 
	if(it != nullptr)
	{
		it->Init_();
		ASSERT_TRUE(it->get_connected_database()->get_state());
		if(it->get_connected_database()->get_state())
		{
			std::cout << "\nConectado";
		}
		it->get_connected_database()->Disconnect_();
	}
	
	std::cout << "\n--\n";
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}