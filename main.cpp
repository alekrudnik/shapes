#include <canvas.hpp>
#include <circle.hpp>
#include <rectangle.hpp>
#include <triangle.hpp>

#include <iostream>

int main(int, char **)
{
    using namespace shapes;

    std::cout << "Test start" << std::endl;

    Canvas canvas(100, 100);

    auto rect = Rectangle::create({10, 5}, {10, 20}, 5);
    auto triang = Triangle::create({30, 5}, 10, 7);
    auto circ = Circle::create({50, 50}, 10, 9);

    auto rect2 = Rectangle::create({5, 5}, {10, 20}, 2);
    auto triang2 = Triangle::create({25, 5}, 10, 7);
    auto circ2 = Circle::create({45, 45}, 10, 9);

    // This should be added as it is overlapping
    if (!canvas.addShape(std::move(rect)))
    {
        std::cout << "Test Failed" << std::endl;
    }
    if (!canvas.addShape(std::move(triang)))
    {
        std::cout << "Test Failed" << std::endl;
    }
    if (!canvas.addShape(std::move(circ)))
    {
        std::cout << "Test Failed" << std::endl;
    }

    // This should be NOT added as it is overlapping
    if (canvas.addShape(std::move(rect2)))
    {
        std::cout << "Test Failed" << std::endl;
    }
    if (canvas.addShape(std::move(triang2)))
    {
        std::cout << "Test Failed" << std::endl;
    }
    if (canvas.addShape(std::move(circ2)))
    {
        std::cout << "Test Failed" << std::endl;
    }
}
