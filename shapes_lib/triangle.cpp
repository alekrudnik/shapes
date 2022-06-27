#include "triangle.hpp"

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

    bool Triangle::setSize(Height h, Length l, const std::list<AbstractShapePtr> &colliders)
    {
        if (h != l)
        {
            return false;
        }

        if (!checkCollision(colliders))
        {
            return false;
        }
        attributes.size.h = h;
        attributes.size.l = l;

        return true;
    }

    bool Triangle::setHeight(Height h, const std::list<AbstractShapePtr> &colliders)
    {
        // TODO: validate h
        if (!checkCollision(colliders))
        {
            return false;
        }
        attributes.size.h = h;
        attributes.size.l = h;
        return true;
    }

    bool Triangle::setLength(Length l, const std::list<AbstractShapePtr> &colliders)
    {
        // TODO: validate l
        if (!checkCollision(colliders))
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
