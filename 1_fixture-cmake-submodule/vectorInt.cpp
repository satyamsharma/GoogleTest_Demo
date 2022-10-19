#include "vectorInt.h"

vectorInt::vectorInt()
{
   arr = new int[1];
   capacity = 1;
   size = 0;
}

vectorInt::~vectorInt()
{
   delete[] arr;
}

void vectorInt::PushBack(int data)
{
   if (size == capacity)
   {
      int* temp = new int[2 * capacity];
      for (int i = 0; i < capacity; i++)
      {
         temp[i] = arr[i];
      }
      delete[] arr;
      capacity *= 2;
      arr = temp;
   }
   arr[size] = data;
   size++;
}

void vectorInt::SetValue(int data, int index)
{
   if (index == capacity)
   {
      PushBack(data);
   }
   else
   {
      arr[index] = data;
   }
}

int vectorInt::GetValueAt(int index)
{
   if (index < size)
   {
      return arr[index];
   }
}

int vectorInt::GetSize()
{
   return size;
}

void vectorInt::Clear()
{
   size = 0;
}

std::string vectorInt::GetSequenceAsString()
{
   std::string sequence;
   for (int i = 0; i < size; i++)
   {
      sequence.append(std::to_string(arr[i]));
      if(i < size - 1)
         sequence.append(",");
   }
   return sequence;
}