#include <iostream>
#include "gtest/gtest.h"
#include "Biblioteca.h"

class TestGen : public ::testing::Test
{
	protected:
		void SetUp() override;
		void TearDown() override;

		Biblioteca *TestObj_;
};

//-----------------------------------------------------------------------------

void TestGen::SetUp()
{
    TestObj_ = new Biblioteca();
}

void TestGen::TearDown()
{
    delete TestObj_;
}

//-----------------------------------------------------------------------------

TEST_F(TestGen, Add)
{
    ASSERT_EQ(5, TestObj_->add(3, 2));
    ASSERT_EQ(8, TestObj_->add(4, 4));
    ASSERT_EQ(12, TestObj_->add(9, 3));
}

TEST_F(TestGen, Sub)
{
    ASSERT_EQ(4, TestObj_->sub(6, 2));
    ASSERT_EQ(10, TestObj_->sub(15, 5));
}

TEST_F(TestGen, Mul)
{
    ASSERT_EQ(6, TestObj_->mul(3, 2));
    ASSERT_EQ(27, TestObj_->mul(3, 9));
    ASSERT_EQ(12, TestObj_->mul(2, 6));
}

//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}