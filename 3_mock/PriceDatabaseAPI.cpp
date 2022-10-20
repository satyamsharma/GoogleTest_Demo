#include "PriceDatabaseAPI.h"

PriceDatabaseAPI::PriceDatabaseAPI(
   std::string serverAddress, std::string serverPort) :
   mServerAddress{serverAddress}, mServerPort{serverPort}
{
}

// NOTE: `sleep` here indicates slow/unreliable connection to the database for the purposes of this demo

void PriceDatabaseAPI::connect()
{
   std::cout << "Connecting to database [" << mServerAddress << "] port[" << mServerPort << "]..." << std::endl;
   //initialize real database connection
   sleep(100);
}

void PriceDatabaseAPI::disconnect()
{
   std::cout << "Disconnecting from the database\n";
   //close real database connection
   sleep(100);
}

double PriceDatabaseAPI::GetPrice(int itemId, int date)
{
   double price{0};

   sleep(100);
   //price = query from the database for the itemId on the given date

   return price;
}