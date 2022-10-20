#include "InflationTracker.h"

InflationTracker::InflationTracker(PriceDatabaseAPI* api): mAPI{api}
{
  mAPI->connect();
}

InflationTracker::~InflationTracker()
{
  mAPI->disconnect();
}

double InflationTracker::GetAveragePrice(int itemId, std::vector<int> dates)
{
   double avgPrice{0};
   for(int date : dates)
   {
      avgPrice += mAPI->GetPrice(itemId, date);
   }
   avgPrice /= dates.size();

   return avgPrice;
}

double InflationTracker::GetMaximumPrice(int itemId, std::vector<int> dates)
{
   double maxPrice{0};
   double _price{0};

   for(int date : dates)
   {
      _price = mAPI->GetPrice(itemId, date);
      if (_price > maxPrice)
      {
         maxPrice = _price;
      }
   }

   return maxPrice;
}

double InflationTracker::GetMedianPrice(int itemId, std::vector<int> dates)
{
   double medianPrice{0};
   double _price{0};

   std::vector<double> prices;
   for(int date : dates)
   {
      _price = mAPI->GetPrice(itemId, date);
      prices.emplace_back(_price);
   }
   sort(prices.begin(), prices.end());

   int size = prices.size();
   if (size % 2 == 0)
   {
      medianPrice = (prices[(size/2) - 1] + prices[size/2])/2;
   }
   else
   {
      medianPrice = prices[size/2];
   }

   return medianPrice;
}
