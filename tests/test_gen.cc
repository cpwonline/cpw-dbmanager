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
	ASSERT_EQ(1, 1);

	std::cout << "\n-- Databases collector";
	for(auto it = TestObj_->databases_collector_->begin(); it != TestObj_->databases_collector_->end(); ++it)
		std::cout << "\n" << it->first << ", " << it->second;
		
	std::cout << "\n--\n";
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}