from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0:
        break


for i in range(n):
    print(" " * (n - (i + 1)) + "#" * (i + 1) + "  " + "#" * (i + 1) + " " * (n - (i + 1)))
