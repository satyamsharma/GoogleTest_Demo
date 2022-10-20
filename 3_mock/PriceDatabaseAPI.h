#pragma once

#include <string>
#include <iostream>
#include <unistd.h>

class PriceDatabaseAPI
{
   public:
      PriceDatabaseAPI(std::string serverAddress,
                        std::string serverPort);

      virtual void connect();
      virtual void disconnect();

      virtual double GetPrice(int itemId, int date);

   private:
      std::string mServerAddress;
      std::string mServerPort;
      std::string mUsername;
      std::string mPassword;
};
