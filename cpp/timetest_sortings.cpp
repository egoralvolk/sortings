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
    arr[i] = rand() % count - rand() % count;
    arr_copy[i] = arr[i];
  }
  return count;
}

int main(int argc, char * argv[])
{
  int arr[COEF*NUMBER_MEASURMENTS + 1],
      arr_copy[COEF*NUMBER_MEASURMENTS + 1];
  clock_t selectionSortTimes[NUMBER_MEASURMENTS],
          bubbleSortTimes[NUMBER_MEASURMENTS],
          insertionSortTimes[NUMBER_MEASURMENTS],
          quickSortRecursiveTimes[NUMBER_MEASURMENTS];
  cout << "Count elements: " << endl;
  for (int i=0; i < NUMBER_MEASURMENTS; i++)
  {
    int size = getArrayOfRandomValues(i + 1, arr, arr_copy);
    cout << size << " ";

    clock_t t=clock();
    selectionSort(size, arr);
    selectionSortTimes[i] = clock()-t;
    arraycopy(size, arr_copy, arr);

    t=clock();
    bubbleSort(size, arr);
    bubbleSortTimes[i] = clock()-t;
    arraycopy(size, arr_copy, arr);

    t=clock();
    insertionSort(size, arr);
    insertionSortTimes[i] = clock()-t;
    arraycopy(size, arr_copy, arr);

    t=clock();
    quickSortRecursive(0, size - 1, arr);
    quickSortRecursiveTimes[i] = clock()-t;
    arraycopy(size, arr_copy, arr);
  }
  cout << "\nTimes of Selection Sort:" << endl;
  printArray(NUMBER_MEASURMENTS, selectionSortTimes);
  cout << "Times of Bubble Sort:" << endl;
  printArray(NUMBER_MEASURMENTS, bubbleSortTimes);
  cout << "Times of Insertion Sort:" << endl;
  printArray(NUMBER_MEASURMENTS, insertionSortTimes);
  cout << "Times of Quick Sort Recursive:" << endl;
  printArray(NUMBER_MEASURMENTS, quickSortRecursiveTimes);
  return 0;
}
