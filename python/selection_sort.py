def selection_sort(array):
    for i in range(len(array) - 1):
        position = i
        for j in range(i + 1, len(array)):
            if (array[j] < array[position]):
                position = j
        array[i], array[position] = array[position], array[i]
    return array

def main():
    array = [4, 5, 8, 2, 1, 0, 9, 6]
    print('Array :', array)
    print('Sorted array:', selection_sort(array))

if __name__ == '__main__':
    main()
