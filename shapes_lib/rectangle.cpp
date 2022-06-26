#include "rectangle.hpp"

namespace shapes
{
    AbstractShapePtr Rectangle::create(Point position, Size size, Color color)
    {
        auto rect = new Rectangle(position, size, color);
        return std::unique_ptr<Rectangle>(rect);
    }

    Rectangle::Rectangle(Point position, Size size, Color color) : Shape(position, size, color)
    {
        setPixMap();
    }

    bool Rectangle::setSize(Height h, Length l, const std::list<AbstractShapePtr> &colliders)
    {
        // TODO: validate h and l ?
        if (!checkCollision(colliders))
        {
            return false;
        }
        attributes.size.h = h;
        attributes.size.l = l;

        return true;
    }

    bool Rectangle::setHeight(Height h, const std::list<AbstractShapePtr> &colliders)
    {
        // TODO: validate h
        if (!checkCollision(colliders))
        {
            return false;
        }
        attributes.size.h = h;
        return true;
    }

    bool Rectangle::setLength(Length l, const std::list<AbstractShapePtr> &colliders)
    {
        // TODO: validate l
        if (!checkCollision(colliders))
        {
            return false;
        }
        attributes.size.l = l;

        return true;
    }

    void Rectangle::setPixMap()
    {
        for (int y = 0; y < attributes.size.h; y++)
            for (int x = 0; x <= attributes.size.l; x++)
                pixMap.at(x, y) = attributes.color;
    }

}
