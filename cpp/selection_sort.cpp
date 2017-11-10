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
  printArray(size, selectionSort(size, array_int));
  cout << "Sorted array of floats: ";
  printArray(size, selectionSort(size, array_float));
  cout << "Sorted array of doubles: ";
  printArray(size, selectionSort(size, array_double));
  return 0;
}
