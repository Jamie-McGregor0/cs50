from cs50 import get_string

n = get_string("Number: ")

length = len(n)

sum = 0

for i in range(length):
    m = int(n[i])
    if i % 2 == 0:

        if  m * 2 >= 10:
            sum += m * 2 // 10 + m * 2% 10
        else:
            sum += m * 2

    else:
        sum += m

if sum % 10 == 0：
    
print(sum)
