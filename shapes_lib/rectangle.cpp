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

    void Rectangle::setPixMap()
    {
        for (int y = 0; y < attributes.size.h; y++)
            for (int x = 0; x <= attributes.size.l; x++)
                pixMap.at(x, y) = attributes.color;
    }

}
