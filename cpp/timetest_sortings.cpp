#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include "sortings.cpp"

#define NUMBER_MEASURMENTS 10
#define COEF 1000

int array_is_sorted(int size, int array[])
{
  int sorted = 1;
  for(int i=0; i<size-1; i++)
    if (array[i] > array[i+1])
    {
      sorted = 0;
      break;
    }
  return sorted;
}

void arraycopy(int size, int *from, int *to)
{
  for (int i = 0; i < size; i++)
    to[i] = from[i];
}

int getArrayOfRandomValues(int k, int *arr, int *arr_copy)
{
  int count = COEF * k;
  for (int i; i < count; i++)
  {
    arr[i] = rand() % (count * 100) - rand() % count;
    arr_copy[i] = arr[i];
  }
  return count;
}

int main(int argc, char * argv[])
{
  int arr[COEF*NUMBER_MEASURMENTS + 1],
      arr_copy[COEF*NUMBER_MEASURMENTS + 1],
      sizes_arrays[NUMBER_MEASURMENTS];
  clock_t selectionSortTimes[NUMBER_MEASURMENTS],
          bubbleSortTimes[NUMBER_MEASURMENTS],
          insertionSortTimes[NUMBER_MEASURMENTS],
          quickSortRecursiveTimes[NUMBER_MEASURMENTS],
          mergeSortRecursiveTimes[NUMBER_MEASURMENTS],
          mergeSortTimes[NUMBER_MEASURMENTS];
  cout << "Count elements: " << endl;
  int count_test = 5;
  for (int i = 0; i < NUMBER_MEASURMENTS; i++)
  {
    for (int cnt = 0; cnt < count_test; cnt++)
    {
      int size = getArrayOfRandomValues(i + 1, arr, arr_copy);
      sizes_arrays[i] = size;

      clock_t t = clock();
      selectionSort(size, arr);
      selectionSortTimes[i] += clock() - t;
      arraycopy(size, arr_copy, arr);

      t = clock();
      bubbleSort(size, arr);
      bubbleSortTimes[i] += clock() - t;
      arraycopy(size, arr_copy, arr);

      t = clock();
      insertionSort(size, arr);
      insertionSortTimes[i] += clock() - t;
      arraycopy(size, arr_copy, arr);

      t = clock();
      quickSortRecursive(0, size - 1, arr);
      quickSortRecursiveTimes[i] += clock() - t;
      arraycopy(size, arr_copy, arr);

      t = clock();
      mergeSortRecursive(0, size - 1, arr);
      mergeSortRecursiveTimes[i] += clock() - t;
      arraycopy(size, arr_copy, arr);

      t = clock();
      mergeSort(size, arr);
      mergeSortTimes[i] += clock() - t;
      arraycopy(size, arr_copy, arr);
    }
    selectionSortTimes[i] /= count_test;
    bubbleSortTimes[i] /= count_test;
    insertionSortTimes[i] /= count_test;
    quickSortRecursiveTimes[i] /= count_test;
    mergeSortRecursiveTimes[i] /= count_test;
    mergeSortTimes[i] /= count_test;
  }

  printArray(NUMBER_MEASURMENTS, sizes_arrays);

  cout << "Times of Selection Sort:" << endl;
  printArray(NUMBER_MEASURMENTS, selectionSortTimes);
  cout << "Times of Bubble Sort:" << endl;
  printArray(NUMBER_MEASURMENTS, bubbleSortTimes);
  cout << "Times of Insertion Sort:" << endl;
  printArray(NUMBER_MEASURMENTS, insertionSortTimes);
  cout << "Times of Quick Sort Recursive:" << endl;
  printArray(NUMBER_MEASURMENTS, quickSortRecursiveTimes);
  cout << "Times of Merge Sort Recursive:" << endl;
  printArray(NUMBER_MEASURMENTS, mergeSortRecursiveTimes);
  cout << "Times of Merge Sort:" << endl;
  printArray(NUMBER_MEASURMENTS, mergeSortTimes);
  return 0;
}
