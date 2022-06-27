#include "circle.hpp"

namespace shapes
{
    AbstractShapePtr Circle::create(Point position, Length r, Color color)
    {
        auto circle = new Circle(position, r, color);
        return std::unique_ptr<Circle>(circle);
    }

    Circle::Circle(Point position, Length r_, Color color) : Shape(position, Size{Length(2 * r_), Height(2 * r_)}, color), r(r_), relative_center{r_, r_}
    {
        setPixMap();
    }

    bool Circle::setSize(Height h, Length l, const std::list<AbstractShapePtr> &colliders)
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

    bool Circle::setHeight(Height h, const std::list<AbstractShapePtr> &colliders)
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

    bool Circle::setLength(Length l, const std::list<AbstractShapePtr> &colliders)
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

    void Circle::setPixMap()
    {
        for (int y = -r; y <= r; y++)
            for (int x = -r; x <= r; x++)
                if (x * x + y * y < r * r)
                    pixMap.at(relative_center.x + x, relative_center.y + y) = attributes.color;
    }

}