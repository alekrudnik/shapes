#include <common.hpp>
#include <canvas.hpp>
#include <circle.hpp>
#include <rectangle.hpp>
#include <triangle.hpp>

#include <iostream>
#include <vector>

int main(int, char **)
{
    using namespace shapes;

    std::cout << "Test start" << std::endl;

    Canvas canvas(100, 200);

    auto rect = Rectangle::create({10, 5}, {10, 20}, 5);
    auto triang = Triangle::create({30, 5}, 10, 7);
    auto circ = Circle::create({50, 50}, 10, 9);

    auto rect2 = Rectangle::create({5, 5}, {10, 20}, 2);
    auto triang2 = Triangle::create({25, 5}, 10, 7);
    auto circ2 = Circle::create({45, 45}, 10, 9);

    OptionalShapeHandle rectHandle = canvas.addShape(rect);
    // This should be added as it is overlapping
    if (!rectHandle)
    {
        std::cout << "Test Failed" << std::endl;
        return -1;
    }

    OptionalShapeHandle triangHandle = canvas.addShape(triang);
    if (!triangHandle)
    {
        std::cout << "Test Failed" << std::endl;
        return -1;
    }

    OptionalShapeHandle circHandle = canvas.addShape(circ);
    if (!circHandle)
    {
        std::cout << "Test Failed" << std::endl;
        return -1;
    }

    // This should be NOT added as it is overlapping
    if (canvas.addShape(rect2))
    {
        std::cout << "Test Failed" << std::endl;
        return -1;
    }
    if (canvas.addShape(triang2))
    {
        std::cout << "Test Failed" << std::endl;
        return -1;
    }
    if (canvas.addShape(circ2))
    {
        std::cout << "Test Failed" << std::endl;
        return -1;
    }
    canvas.update();
    canvas.getPixMap().print();

    //select, modify
    if(!rect->setSize(20,20))
    {
        std::cout << "Test Failed" << std::endl;
        return -1;
    }
    // this should fail, as it is overlapping
    if(rect->setSize(21,20))
    {
        std::cout << "Test Failed" << std::endl;
        return -1;
    }
    triang->setColor(3);

    if(!circ->move({50,5}))
    {
        std::cout << "Test Failed" << std::endl;
        return -1;
    }

    // should faile as there will be collision
    if(circ->move({10,5}))
    {
        std::cout << "Test Failed" << std::endl;
        return -1;
    }

    canvas.update();
    canvas.getPixMap().print();

    const auto& shapes = canvas.GetShapes();

    // get all handles and remove all shapes
    std::vector<ShapeHandle> handle_list;
    for (auto &shape : shapes)
    {
        if (auto handle = shape->getHandle())
        {
            handle_list.emplace_back(*handle);
        }
    }
    for (auto handle : handle_list)
    {
        if (!canvas.removeShape(handle))
        {
            std::cout << "Test Failed" << std::endl;
            return -1;
        }
    }

    canvas.update();
    canvas.getPixMap().print();
}
