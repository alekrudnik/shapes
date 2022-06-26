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

        bool setSize(Height h, Length l, const std::list<AbstractShapePtr> &colliders) override;
        bool setHeight(Height h, const std::list<AbstractShapePtr> &colliders) override;
        bool setLength(Length l, const std::list<AbstractShapePtr> &colliders) override;

        protected:
        void setPixMap() override;
        
        private:
        Rectangle(Point position, Size size, Color color);
    };
}
