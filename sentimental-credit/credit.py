from cs50 import get_string

n = get_string("Number: ")

length = len(n)

sum1 = 0
sum2 = 0

for i in range(length):
    if i % 2 == 0:
        m = int(n[i]) * 2
        if  m >= 10:
            sum1 += m // 10 + m % 10
        else:
            sum1 += m

    else:
        


print(sum)
