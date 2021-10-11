import turtle
import random


def triangle_koch(n, l):
    if n == 1:
        r = random.random()
        g = random.random()
        b = random.random()
        turtle.pencolor(r, g, b)
        turtle.forward(l)
    else:
        triangle_koch(n - 1, l / 3)
        turtle.left(60)
        triangle_koch(n - 1, l / 3)
        turtle.right(120)
        triangle_koch(n - 1, l / 3)
        turtle.left(60)
        triangle_koch(n - 1, l / 3)


def main():
    turtle.speed(0)
    turtle.hideturtle()
    for i in range(3):
        triangle_koch(5, 200)
        turtle.right(120)


main()
input()
