from cs50 import get_string

n = get_string("Number: ")

length = len(n)

sum = 0

for i in range(length):
    m = int(n[i])
    if i % 2 == 0:
        m* 2
        if  m >= 10:
            sum += m // 10 + m % 10
        else:
            sum += m

    else:
        print(m)
        sum += m

print(sum)
