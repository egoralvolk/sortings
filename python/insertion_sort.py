def insertion_sort(array):
    for i in range(1, len(array)):
        j = i
        while j > 0 and array[j] < array[j - 1]:
            array[j], array[j - 1] = array[j - 1], array[j]
            j -= 1
    return array

def main():
    array = [4, 5, 8, 2, 1, 0, 9, 6]
    print('Array :', array)
    print('Sorted array:', insertion_sort(array))

if __name__ == '__main__':
    main()
