def kolvo_kratnih(arr):
    count = 0
    for num in arr:
        if num % 3 == 0:
            count += 1
    return count

def find_array_with_max_kratnih(arrA, arrB):
    countA = kolvo_kratnih(arrA)
    countB = kolvo_kratnih(arrB)

    if countA > countB:
        print(f"Массив A имеет больше элементов кратных 3: {countA}")
        print("Элементы массива A:", *arrA)
        print("Элементы массива B:", *arrB)
    elif countB > countA:
        print(f"Массив B имеет больше элементов кратных 3: {countB}")
        print("Элементы массива B:", *arrB)
        print("Элементы массива A:", *arrA)
    else:
        print(f"Массивы имеют одинаковое количество элементов кратных 3: {countA}")
        print("Элементы массива A:", *arrA)
        print("Элементы массива B:", *arrB)

def main():

    A = [int(s) for s in input("Введите кол-во элементов массива A: ").split()]
    B = [int(s) for s in input("Введите кол-во элементов массива B: ").split()]

    find_array_with_max_kratnih(A, B)

print(main())
