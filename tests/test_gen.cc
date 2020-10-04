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

TEST_F(TestGen, Add)
{
	std::cout << "\n---";
    ASSERT_EQ(1, 1);
    
    TestObj_->NewConnection_("sqlite3" );
    TestObj_->ServerConfigs_("127.0.0.1", "3306");
    TestObj_->DatabaseConfigs_("test1", "root", "j0f1r2c3=1999");
    TestObj_->ShowConnections_();
    
	std::cout << "\n---";
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}