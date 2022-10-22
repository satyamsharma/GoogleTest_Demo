#include <gtest/gtest.h>
#include "calculator.h"

TEST(Addition, positive_numbers)
{
    calculator myCalc;
    EXPECT_EQ(11, myCalc.Add(6, 5));
}

TEST(Subtraction, positive_numbers)
{
    calculator myCalc;
    EXPECT_EQ(1, myCalc.Subtract(6, 5));
}

TEST(Multiplication, positive_numbers)
{
    calculator myCalc;
    EXPECT_EQ(30, myCalc.Multiply(5, 6));
}

TEST(Multiplication, negative_numbers)
{
    calculator myCalc;
    EXPECT_EQ(30, myCalc.Multiply(-5, -6));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
