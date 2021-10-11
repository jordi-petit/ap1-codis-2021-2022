import turtle
import random


def quadrat(mida):
    for i in range(4):
        turtle.forward(mida)
        turtle.right(90)


def main():
    turtle.speed(0)
    turtle.hideturtle()
    for i in range(36):
        r = random.random()
        g = random.random()
        b = random.random()
        turtle.pencolor(r, g, b)
        quadrat(100)
        turtle.right(10)


main()
input()
