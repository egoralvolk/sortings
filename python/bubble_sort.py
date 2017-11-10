def bubble_sort(array):
    for i in range(len(array) - 1):
        for j in range(1, len(array) - i):
            if (array[j] < array[j - 1]):
                array[j], array[j - 1] = array[j - 1], array[j]
    return array

def main():
    array = [4, 5, 8, 2, 1, 0, 9, 6]
    print('Array :', array)
    print('Sorted array:', bubble_sort(array))

if __name__ == '__main__':
    main()
