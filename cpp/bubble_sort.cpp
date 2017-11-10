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

int main(int argc, char * argv[])
{
  int size = 6;
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
  printArray(size, bubbleSort(size, array_int));
  cout << "Sorted array of floats: ";
  printArray(size, bubbleSort(size, array_float));
  cout << "Sorted array of doubles: ";
  printArray(size, bubbleSort(size, array_double));
  return 0;
}
