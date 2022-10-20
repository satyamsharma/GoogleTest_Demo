#include "InflationTracker.h"
#include "PriceDatabaseAPI.h"

int main()
{
   PriceDatabaseAPI* api = new PriceDatabaseAPI("172.0.0.1", "5000");
   InflationTracker myTracker(api);

   int itemid = 10;
   std::vector<int> dates = {20180115, 20190305, 20200723, 20210917, 20221103};

   double avg = myTracker.GetAveragePrice(5, dates);
   double max = myTracker.GetMaximumPrice(5, dates);
   double median = myTracker.GetMedianPrice(5, dates);

   return 0;
}
