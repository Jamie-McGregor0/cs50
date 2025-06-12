from cs50 import get_string

n = get_string("Number: ")

length = len(n)

sum = 0

for i in range(length, 0, -1):
    m = int(n[i - 1])
    if (length - i) % 2 == 0:
        sum += m

    else:
        sum += m * 2 // 10 + m * 2 % 10

if sum % 10 == 0:
    if length == 15 and n[0] + n[1] in ["34", "37"]:
        print("AMEX")
    elif length == 16 and n[0] + n[1] in ["51", "52", "53", "54", "55"]:
        print("MASTERCARD")
    elif length == 13 or length == 16 and n[0] == "4":
        print("VISA")
    else:
        print("INVALID")

else:
    print("INVALID")

