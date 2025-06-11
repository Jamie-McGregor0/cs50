from cs50 import get_int

n = get_int("Number: ")

length = 0
n_test = n

while n_test > 10:
    n_test = n_test % 10
    length += 1

print(length)
