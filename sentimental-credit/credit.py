from cs50 import get_int

n = get_int("Number: ")

length = len(str(n))

sum = 0

for i in range(length):
    if i % 2 != 0:
        sum += int(n[i]) * 2


print(sum)
