from cs50 import get_string

n = get_string("Number: ")

length = len(n)

sum = 0

for i in range(length):
    if i % 2 == 0:
        print(int(n[i]))
        sum += int(n[i]) * 2


print(sum)
