from cs50 import get_int

n = get_int("Height: ")

if n <= 0:
    return

for i in range(n):
    print(" " * (n - (i + 1)) + "#" * (i + 1) + "  " + "#" * (i + 1) + " " * (n - (i + 1)))
