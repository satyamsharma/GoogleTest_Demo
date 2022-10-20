#pragma once
#include "PriceDatabaseAPI.h"
#include <vector>

class InflationTracker
{
   public:
      InflationTracker(PriceDatabaseAPI* api);
      ~InflationTracker();

      double GetAveragePrice(int itemId, std::vector<int> dates);
      double GetMaximumPrice(int itemId, std::vector<int> dates);
      double GetMedianPrice(int itemId, std::vector<int> dates);

   private:
      PriceDatabaseAPI* mAPI;
};
