# programa que llegeix tres enters i n'escriu el seu màxim

from easyinput import read


def max3(x, y, z):
    return max2(x, max2(y, z))


def max2(x, y):
    if x >= y:
        return x
    else:
        return y


# a = read(int)
# b = read(int)
# c = read(int)
a, b, c = read(int, int, int)
print(max3(a, b, c))
