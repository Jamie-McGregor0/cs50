from cs50 import get_int

n = get_int("Height: ")



for i in range(n):
    print(" " * (n - (i + 1)) + "#" * (i + 1) + "  " + "#" * (i + 1) + " " * (n - (i + 1)))
