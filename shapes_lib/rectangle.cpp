#include "rectangle.hpp"

#include "abstract_canvas.hpp"

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

    bool Rectangle::setSize(Length l, Height h)
    {
        if (parent && !checkCollision(parent->GetShapes(), parent->getSize()))
        {
            return false;
        }
        attributes.size.h = h;
        attributes.size.l = l;
        pixMap = PixMap(attributes.size);
        setPixMap();

        return true;
    }

    bool Rectangle::setHeight(Height h)
    {
        if (parent && !checkCollision(parent->GetShapes(), parent->getSize()))
        {
            return false;
        }
        attributes.size.h = h;
        pixMap = PixMap(attributes.size);
        setPixMap();
        return true;
    }

    bool Rectangle::setLength(Length l)
    {
        if (parent && !checkCollision(parent->GetShapes(), parent->getSize()))
        {
            return false;
        }
        attributes.size.l = l;
        pixMap = PixMap(attributes.size);
        setPixMap();

        return true;
    }

    void Rectangle::setPixMap()
    {
        for (int y = 0; y < attributes.size.h; y++)
            for (int x = 0; x <= attributes.size.l; x++)
                pixMap.at(x, y) = attributes.color;
    }

}
