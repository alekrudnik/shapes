#pragma once

#include "shape.hpp"

#include "abstract_canvas.hpp"

namespace shapes
{
    class Circle : public Shape
    {
    public:
        // named constructor
        static AbstractShapePtr create(Point position, Length r, Color color);

        ~Circle() = default;

        bool setSize(Height h, Length l) override;
        bool setHeight(Height h) override;
        bool setLength(Length l) override;

    protected:
        void setPixMap() override;

    private:
        Circle(Point position, Length r, Color color);
        Length r;
        Point relative_center;
    };
}
