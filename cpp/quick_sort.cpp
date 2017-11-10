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
void printArray(int size, T* array)
{
  for(int i = 0; i < size; i++)
    cout << array[i] << ' ';
  cout << endl;
  return;
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
void quickSortRecursive(int size, T* array)
{
  T mid = array[size-1];
  int i = 0, j = size - 1;
  while (i < j)
  {
    while (array[i] < mid)
      i++;
    while (array[j] > mid)
      j--;
    if (i < j)
      swapElements(array[i], array[j]);
  }
  if (j > 1) quickSortRecursive(j, array);
  if (size - (i + 1) > 1) quickSortRecursive(size - i, array + i);
}

int main(int argc, char * argv[])
{
  int size = 10;
  int array_int[] = {4, 5, 6, 7, 1, 3, 2, 9, 8, 0};
  float array_float[] = {4., 5., 6., 7., 1., 3., 2., 9., 8., 0.};
  double array_double[] = {4., 5., 6., 7., 1., 3., 2., 9., 8., 0.};
  cout << "Array of integers: ";
  printArray(size, array_int);
  cout << "Array of floats: ";
  printArray(size, array_float);
  cout << "Array of doubles: ";
  printArray(size, array_double);

  cout << "----------" << endl;

  cout << "Sorted array of integers: ";
  quickSortRecursive(size, array_int);
  printArray(size, array_int);
  cout << "Sorted array of floats: ";
  quickSortRecursive(size, array_float);
  printArray(size, array_float);
  cout << "Sorted array of doubles: ";
  quickSortRecursive(size, array_double);
  printArray(size, array_double);
  return 0;
}
