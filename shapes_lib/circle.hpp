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

        bool setSizePolicy(Height h, Length l) override;

    protected:
        void setPixMap() override;

    private:
        Circle(Point position, Length r, Color color);
        Length r;
        Point relative_center;
    };
}
