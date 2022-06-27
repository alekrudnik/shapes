#pragma once

#include "shape.hpp"

namespace shapes
{
    class Circle : public Shape
    {
    public:
        // named constructor
        static AbstractShapePtr create(Point position, Length r, Color color);

        ~Circle() = default;

        bool setSize(Height h, Length l, const std::list<AbstractShapePtr> &colliders) override;
        bool setHeight(Height h, const std::list<AbstractShapePtr> &colliders) override;
        bool setLength(Length l, const std::list<AbstractShapePtr> &colliders) override;

        protected:
        void setPixMap() override;
        
        private:
        Circle(Point position, Length r, Color color);
        Length r;
        Point relative_center;

    };
}
