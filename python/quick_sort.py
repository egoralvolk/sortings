def insertion_sort(array):
    for i in range(1, len(array)):
        j = i
        while j > 0 and array[j] < array[j - 1]:
            array[j], array[j - 1] = array[j - 1], array[j]
            j -= 1
    return array

def partition(array, left, right):
    pivot = array[right]
    i = left - 1
    for j in range(left, right):
        if array[j] < pivot:
            i += 1
            array[i], array[j] = array[j], array[i]
    array[i + 1], array[right] = array[right], array[i + 1]
    return i + 1

def quick_sort(array, left, right):
    if left < right:
        p = partition(array, left, right)
        quick_sort(array, left, p - 1)
        quick_sort(array, p + 1, right)
    return array

def main():
    array = [4, 5, 8, 2, 1, 0, 9, 6]
    print('Array :', array)
    print('Sorted array:', quick_sort(array, 0, len(array) - 1))

if __name__ == '__main__':
    main()
