#include <iostream>

using namespace std;

template <typename T>
T swapElements(T &a, T &b)
{
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
void printArray(int size, T array[])
{
  for(int i = 0; i < size; i++)
    cout << array[i] << ' ';
  cout << endl;
  return;
}

template <typename T>
T* selectionSort(int size, T array[])
{
    int position;
    for(int i = 0; i < size - 1; i++)
    {
      position = i;
      for(int j = i + 1; j < size; j++)
      {
        if (array[j] < array[position])
        {
          position = j;
        }
      }
      swapElements(array[i], array[position]);
    }
    return array;
}

template <typename T>
T* bubbleSort(int size, T array[])
{
    for(int i = 0; i < size - 1; i++)
    {
      for(int j = 1; j < size - i; j++)
      {
        if (array[j] < array[j - 1])
          swapElements(array[j], array[j - 1]);
      }
    }
    return array;
}

template <typename T>
T* insertionSort(int size, T array[])
{
    for(int i = 1; i < size; i++)
    {
      for(int j = i; j > 0 && array[j] < array[j-1]; j--)
      {
          swapElements(array[j], array[j - 1]);
      }
    }
    return array;
}


template <typename T>
int partition(int left, int right, T* array)
{
  T pivot = array[right];
  int i = left - 1;
  for (int j = left; j < right; j++)
  {
    if (array[j] < pivot)
    {
      i++;
      swapElements(array[i], array[j]);
    }
  }
  swapElements(array[i + 1], array[right]);
  return i + 1;
}

template <typename T>
void quickSortRecursive(int left, int right, T* array)
{
  if (left < right)
  {
    int p = partition(left, right, array);
    quickSortRecursive(left, p - 1, array);
    quickSortRecursive(p + 1, right, array);
  }
}
