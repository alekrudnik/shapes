#include <canvas.hpp>
#include <rectangle.hpp>

#include <iostream>

int main(int, char**) {
    using namespace shapes;

    std::cout << "Hello, world!\n";

    Canvas canvas(100,100);

    auto rect = Rectangle::create({10,5}, {10, 20}, 5);

    canvas.addShape(std::move(rect)); 
}
