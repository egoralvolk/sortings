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

// Сортировка выбором
template <typename T>
void selectionSort(int size, T* array)
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
}

// Сортировка "пузырьком"
template <typename T>
void bubbleSort(int size, T* array)
{
    for(int i = 0; i < size - 1; i++)
      for(int j = 1; j < size - i; j++)
        if (array[j] < array[j - 1])
          swapElements(array[j], array[j - 1]);
}

// Сортировка вставками
template <typename T>
void insertionSort(int size, T* array)
{
    for(int i = 1; i < size; i++)
      for(int j = i; j > 0 && array[j] < array[j-1]; j--)
          swapElements(array[j], array[j - 1]);
}

// Разделение по порогу для быстрой сортировки
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

// Быстрая сортировка
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

// Слияние для сортировки слиянием
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

// Рекурсивная сортировка слиянием
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

// Сортировка слиянием
template <typename T>
void mergeSort(int size, T* array)
{
  for(int i = 1; i < size; i *= 2)
    for(int j = 0; j < size - i; j += 2 * i)
     merge(j, j + i - 1, min(j + i*2, size) - 1, array);
}
