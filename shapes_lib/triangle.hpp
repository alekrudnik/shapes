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

        bool setSizePolicy(Height h, Length l) override;

        protected:
        void setPixMap() override;
        
        private:
        Triangle(Point position, Height height, Color color);
    };
}
