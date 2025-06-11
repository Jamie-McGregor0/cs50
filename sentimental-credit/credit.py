from cs50 import get_string

n = get_string("Number: ")

length = len(n)

sum = 0

for i in range(length):
    if i % 2 == 0:
        m = int(n[i]) * 2
        if  m >= 10
            sum += m


print(sum)
