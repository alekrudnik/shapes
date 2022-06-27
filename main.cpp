#include <canvas.hpp>
#include <circle.hpp>
#include <rectangle.hpp>
#include <triangle.hpp>

#include <iostream> 

int main(int, char**) {
    using namespace shapes;

    std::cout << "Hello, world!\n";

    Canvas canvas(100,100);

    auto rect = Rectangle::create({10,5}, {10, 20}, 5);
    auto triang = Triangle::create({30,5}, 10, 7);
    auto circ = Circle::create({50,50}, 10, 9);


    canvas.addShape(std::move(rect)); 
    canvas.addShape(std::move(triang));
    canvas.addShape(std::move(circ));
}
