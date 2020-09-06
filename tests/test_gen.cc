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
    ASSERT_EQ(1, 1);
    TestObj_->PrepareConnection_("name_database");
    if(!TestObj_->get_status_connection())
    {
		std::cout << "error";
	}
	TestObj_->set_query_sql("SELECT * FROM coursos");
	TestObj_->RunQuery_();
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}