# programa que llegeix una seqüència no buida de reals
# i escriu la seva mitjana

# quan read() no pot llegir més, retorna None

from easyinput import read

n = 0
s = 0.0
x = read(float)
while x is not None:
    s = s + x
    n = n + 1
    x = read(float)
print(s / n)
