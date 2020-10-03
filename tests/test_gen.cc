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
    TestObj_ = new CPWDBManager("sqlite3");
}

void TestGen::TearDown()
{
    delete TestObj_;
}

//-----------------------------------------------------------------------------

TEST_F(TestGen, Add)
{
	std::cout << "\n---";
    ASSERT_EQ(1, 1);
    TestObj_->PrepareConnection_("name_database");
    if(TestObj_->connection_general_->connected_to_database_)
    {
		TestObj_->generic_handler_->PrepareDatabase_();
		TestObj_->RunQuery_();
	}
	else
		std::cout << "\nError";
	std::cout << "\n---";
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}