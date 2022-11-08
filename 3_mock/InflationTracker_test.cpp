#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "PriceDatabaseAPI.h"
#include "InflationTracker.h"

// Two ways to enforce ordering
using ::testing::InSequence; // for a single linear ordering

// using ::testing::Sequence; // for a more flexible ordering
                              // e.g. a group calls are expected to be
                              // after a certain call, but the calls within the
                              // group can be in an aribitrary ordering

class MockPriceDatabaseAPI : public PriceDatabaseAPI
{
public:
   MockPriceDatabaseAPI(std::string serverAddress, std::string serverPort) : PriceDatabaseAPI(serverAddress, serverPort)
   {
   }

   MOCK_METHOD(void, connect, ());
   MOCK_METHOD(void, disconnect, ());
   MOCK_METHOD(double, GetPrice, (int itemId, int date));
};

TEST(TestConnection, TestConnection)
{
   InSequence s;
   MockPriceDatabaseAPI api = MockPriceDatabaseAPI("172.0.0.1", "5000");

   EXPECT_CALL(api, connect());
   EXPECT_CALL(api, disconnect());

   InflationTracker myTracker(&api);// connect() is called in constructor
                                    // disconnect() is called in constructor
}

// NOTE: Following could be put into single test fixture

TEST(CalculatePrice, AveragePrice)
{
   int itemid = 10;
   std::vector<int> dates = {20180115, 20190305, 20200723, 20210917, 20221103};
   std::vector<double> mockPrices = {50, 200, 300, 400, 1000};
   double expectedAvgPrice = 390;

   InSequence s;
   MockPriceDatabaseAPI api = MockPriceDatabaseAPI("172.0.0.1", "5000");

   EXPECT_CALL(api, connect());
   for (int i = 0; i < dates.size(); i++)
   {
      EXPECT_CALL(api, GetPrice(itemid, dates[i])).WillOnce(testing::Return(mockPrices[i]));
   }
   EXPECT_CALL(api, disconnect());

   InflationTracker myTracker(&api);
   double avg = myTracker.GetAveragePrice(itemid, dates);

   ASSERT_FLOAT_EQ(expectedAvgPrice, avg);
}

TEST(CalculatePrice, MaximumPrice)
{
   int itemid = 10;
   std::vector<int> dates = {20180115, 20190305, 20200723, 20210917, 20221103};
   std::vector<double> mockPrices = {50, 200, 300, 400, 5000};
   double expectedMaxPrice = 5000;

   MockPriceDatabaseAPI api = MockPriceDatabaseAPI("172.0.0.1", "5000");

   InSequence s;
   EXPECT_CALL(api, connect());
   for (int i = 0; i < dates.size(); i++)
   {
      EXPECT_CALL(api, GetPrice(itemid, dates[i])).WillOnce(testing::Return(mockPrices[i]));
   }
   EXPECT_CALL(api, disconnect());

   InflationTracker myTracker(&api);
   double max = myTracker.GetMaximumPrice(itemid, dates);

   ASSERT_FLOAT_EQ(expectedMaxPrice, max);
}

TEST(CalculatePrice, MedianPrice_EvenSet)
{
   int itemid = 10;
   std::vector<int> dates = {20180115, 20190305, 20200723, 20210917, 20221103};
   std::vector<double> mockPrices = {50, 200, 300, 400, 5000};
   double expectedMaxPrice = 5000;

   InSequence s;
   MockPriceDatabaseAPI api = MockPriceDatabaseAPI("172.0.0.1", "5000");
   EXPECT_CALL(api, connect());
   for (int i = 0; i < dates.size(); i++)
   {
      EXPECT_CALL(api, GetPrice(itemid, dates[i])).WillOnce(testing::Return(mockPrices[i]));
   }
   EXPECT_CALL(api, disconnect());

   InflationTracker myTracker(&api);
   double max = myTracker.GetMaximumPrice(itemid, dates);

   ASSERT_FLOAT_EQ(expectedMaxPrice, max);
}


TEST(CalculatePrice, MedianPrice_OddSet)
{
   int itemid = 10;
   std::vector<int> dates = {20180115, 20190305, 20200723, 20210917, 20221103};
   std::vector<double> mockPrices = {50, 200, 300, 400, 5000};
   double expectedMedianPrice = 300;

   InSequence s;
   MockPriceDatabaseAPI api = MockPriceDatabaseAPI("172.0.0.1", "5000");
   EXPECT_CALL(api, connect());
   for (int i = 0; i < dates.size(); i++)
   {
      EXPECT_CALL(api, GetPrice(itemid, dates[i])).WillOnce(testing::Return(mockPrices[i]));
   }
   EXPECT_CALL(api, disconnect());

   InflationTracker myTracker(&api);
   double median = myTracker.GetMedianPrice(itemid, dates);
   ASSERT_FLOAT_EQ(expectedMedianPrice, median);
}

int main(int argc, char **argv)
{
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}
