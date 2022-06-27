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

    bool Triangle::setSize(Height h, Length l)
    {
        if (h != l)
        {
            return false;
        }

        if (parent && !checkCollision(parent->GetShapes()))
        {
            return false;
        }
        attributes.size.h = h;
        attributes.size.l = l;

        return true;
    }

    bool Triangle::setHeight(Height h)
    {
        // TODO: validate h
        if (parent && !checkCollision(parent->GetShapes()))
        {
            return false;
        }
        attributes.size.h = h;
        attributes.size.l = h;
        return true;
    }

    bool Triangle::setLength(Length l)
    {
        // TODO: validate l
        if (parent && !checkCollision(parent->GetShapes()))
        {
            return false;
        }
        attributes.size.h = l;
        attributes.size.l = l;

        return true;
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
