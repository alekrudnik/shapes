#pragma once

#include "shape.hpp"

namespace shapes
{
    class Triangle : public Shape
    {
    public:
        // named constructor
        static AbstractShapePtr create(Point position, Height Height, Color color);

        ~Triangle() = default;

        bool setSize(Height h, Length l) override;
        bool setHeight(Height h) override;
        bool setLength(Length l) override;

        protected:
        void setPixMap() override;
        
        private:
        Triangle(Point position, Height height, Color color);
    };
}
