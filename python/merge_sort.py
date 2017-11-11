def merge(array, left, mid, right):
    i = left
    j = mid + 1
    k = 0
    arr = []
    while i < mid + 1 and j < right + 1:
        if array[i] < array[j]:
            arr.append(array[i])
            i += 1
        else:
            arr.append(array[j])
            j += 1
    while i < mid + 1:
        arr.append(array[i])
        i += 1
    while j < right + 1:
        arr.append(array[j])
        j += 1
    for z in range(0, right - left + 1):
        array[z + left] = arr[z]

def merge_sort_recursive(array, left, right):
    if left < right:
        mid = (left + right) >> 1
        merge_sort_recursive(array, left, mid)
        merge_sort_recursive(array, mid + 1, right)
        merge(array, left, mid, right)

def merge_sort(array, size):
    i = 1
    while i < size:
        for j in range(0, size - i, 2*i):
            merge(array, j, j + i - 1, min(j + i*2, size) - 1)
        i *= 2

def main():
    array = [4, 5, 8, 2, 1, 0, 9, 6]
    print('Array :', array)
    merge_sort(array, len(array))
    print('Sorted array:', array)

if __name__ == '__main__':
    main()
