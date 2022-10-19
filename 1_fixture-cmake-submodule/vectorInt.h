#pragma once
#include <iostream>
#include <string>

class vectorInt
{
   public:
      vectorInt();
      ~vectorInt();

      void PushBack(int data);
      void SetValue(int data, int index);
      int GetValueAt(int index);
      int GetSize();
      int GetCapacity();
      void Clear();
      std::string GetSequenceAsString();

   private:
      int* arr;
      int capacity;
      int size;
};