from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for i in range(n + 1):
    if i > 0:
        print(" " * (n - i) + "#" * i + "  " + "#" * i)
