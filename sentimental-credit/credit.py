from cs50 import get_string

def main():
    n = get_string("Number: ")

    if length == 15 and n[0] + n[1] in [34, 37]:
        print("AMEX")
    elif length == 16 and n[0] + n[1] in [51, 52, 53, 54, 55]:
        print("MASTERCARD")
    elif length == 13 or length == 16 and n[0] == 4:
        print("VISA")

else:
    print("INVALID")


def isvalid(n):
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

    if sum % 10 == 0:
        return True
    else
        return False



main()
