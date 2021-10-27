import turtle
import easyinput


def circle(center_x, center_y, radius):
    """draws a circle centered at center_x, center_y with radius radius"""
    turtle.up()
    turtle.goto(center_x, center_y - radius)
    turtle.down()
    turtle.circle(radius)


def koch(center_x, center_y, size, levels):
    """draws the koch fractal with 4 circles centered at center_x, center_y with size size and levels levels"""
    circle(center_x, center_y, size)
    if levels > 1:
        offset = size * 3 / 2
        koch(center_x, center_y + offset, size / 2, levels - 1)
        koch(center_x, center_y - offset, size / 2, levels - 1)
        koch(center_x + offset, center_y, size / 2, levels - 1)
        koch(center_x - offset, center_y, size / 2, levels - 1)


def main():
    n, d = easyinput.read(int, float)
    koch(0, 0, d, n)


main()
