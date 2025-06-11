from cs50 import get_string

n = get_string("Height: ")

for i in range(n):
    print(" " * (n - i) + "  " + " " * (n - i))
