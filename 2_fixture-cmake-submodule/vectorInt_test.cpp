#include "vectorInt.h"
#include <gtest/gtest.h>

// Test Fixture
class VectorIntTestFixture: public testing::Test
{
   public:
      void SetUp() override
      {
         // Called before each test
         ASSERT_EQ(0, myVec->GetSize());
      }

      void TearDown() override
      {
         // Called after each test
         myVec->Clear();
      }

      static void SetUpTestCase()
      {
         // Called once before all VectorIntTestFixture tests
         myVec = new vectorInt();
      }

      static void TearDownTestCase()
      {
         // Called once after all VectorIntTestFixture tests
         delete myVec;
      }

      static vectorInt* myVec;
};
vectorInt* VectorIntTestFixture::myVec = nullptr;

// EXPECT vs ASSERT
TEST_F(VectorIntTestFixture, AddPositiveItems)
{
   myVec->PushBack(100);
   myVec->PushBack(200);
   myVec->PushBack(300);
   EXPECT_EQ(100, myVec->GetValueAt(0));
   EXPECT_EQ(200, myVec->GetValueAt(1));
   EXPECT_EQ(300, myVec->GetValueAt(2));
   ASSERT_EQ(  3, myVec->GetSize());
}

TEST_F(VectorIntTestFixture, AddNegativeItems)
{
   myVec->PushBack(-100);
   myVec->PushBack(-200);
   myVec->PushBack(-300);
   EXPECT_EQ(-100, myVec->GetValueAt(0));
   EXPECT_EQ(-200, myVec->GetValueAt(1));
   EXPECT_EQ(-300, myVec->GetValueAt(2));
   ASSERT_EQ(   3, myVec->GetSize());
}

// ASSERT on String
TEST(StringTest, SequenceAsString)
{
   vectorInt numVec;
   numVec.PushBack(-100);
   numVec.PushBack(-200);
   numVec.PushBack(-300);
   ASSERT_STREQ("-100,-200,-300", numVec.GetSequenceAsString().c_str());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
