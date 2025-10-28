def main():
    print("Элементы множества A")
    A = set(map(int, input().split()))

    print("Элементы множества B")
    B = set(map(int, input().split()))

    in_only_A = A - B

    return f"Элементы которые есть только в A: {in_only_A}"
print(main())

