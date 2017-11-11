#include <iostream>
#include <cmath>

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
void merge(int left, int mid, int right, T* array)
{
  int i = left,
      j = mid + 1,
      k = 0,
      size = right - left + 1;

  T* arr = new T[size];

  while ((i < mid + 1) && (j < right + 1))
    arr[k++] = (array[i] < array[j]) ? array[i++] : array[j++];

  while (i < mid + 1)
  {
    arr[k] = array[i++];
    k++;
  }

  while (j < right + 1)
  {
    arr[k] = array[j++];
    k++;
  }

  for(int k = 0; k < size; k++)
    array[k + left] = arr[k];
}

template <typename T>
void mergeSortRecursive(int left, int right, T* array)
{
  if (left < right)
  {
    int mid = (left + right) >> 1;
    mergeSortRecursive(left, mid, array);
    mergeSortRecursive(mid+1, right, array);
    return merge(left, mid, right, array);
  }
}

template <typename T>
void mergeSort(int size, T* array)
{
  for(int i = 1; i < size; i *= 2)
    for(int j = 0; j < size - i; j += 2 * i)
     merge(j, j + i - 1, min(j + i*2, size) - 1, array);
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
  mergeSortRecursive(0, size-1, array_int);
  printArray(size, array_int);

  cout << "Sorted array of floats: ";
  mergeSortRecursive(0, size-1, array_float);
  printArray(size, array_float);

  cout << "Sorted array of doubles: ";
  mergeSortRecursive(0, size-1, array_double);
  printArray(size, array_double);

  return 0;
}
