#include "triangle.hpp"

#include "abstract_canvas.hpp"

namespace shapes
{
    AbstractShapePtr Triangle::create(Point position, Height height, Color color)
    {
        auto triangle = new Triangle(position, height, color);
        return std::unique_ptr<Triangle>(triangle);
    }

    Triangle::Triangle(Point position, Height height, Color color) : Shape(position, Size{height, height}, color)
    {
        setPixMap();
    }

    bool Triangle::setSizePolicy(Height h, Length l)
    {
        return (h == l);
    }

    void Triangle::setPixMap()
    {
        for (auto y = 0; y < attributes.size.h; y++)
        {
            for (auto x = 0; x <= y; x++)
            {
                pixMap.at(x, y) = attributes.color;
            }
        }
    }

}
