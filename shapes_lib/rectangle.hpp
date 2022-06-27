#pragma once

#include "shape.hpp"

namespace shapes
{
    class Rectangle : public Shape
    {
    public:
        // named constructor
        static AbstractShapePtr create(Point position, Size size, Color color);

        ~Rectangle() = default;

        protected:
        void setPixMap() override;
        
        private:
        Rectangle(Point position, Size size, Color color);
    };
}
