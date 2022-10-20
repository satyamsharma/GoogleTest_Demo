#include <gtest/gtest.h>
#include "calculator.h"

TEST(Addition, positive_numbers)
{
    calculator myCalc;
    EXPECT_EQ(myCalc.Add(6, 5), 11);
}

TEST(Subtraction, positive_numbers)
{
    calculator myCalc;
    EXPECT_EQ(myCalc.Subtract(6, 5), 1);
}

TEST(Multiplication, positive_numbers)
{
    calculator myCalc;
    EXPECT_EQ(myCalc.Multiply(5, 6), 30);
}

TEST(Multiplication, negative_numbers)
{
    calculator myCalc;
    EXPECT_EQ(myCalc.Multiply(-5, -6), 30);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
