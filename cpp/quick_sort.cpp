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
  quickSortRecursive(0, size - 1, array_int);
  printArray(size, array_int);

  cout << "Sorted array of floats: ";
  quickSortRecursive(0, size - 1, array_float);
  printArray(size, array_float);

  cout << "Sorted array of doubles: ";
  quickSortRecursive(0, size - 1, array_double);
  printArray(size, array_double);

  return 0;
}
