#pragma once

#include "common.hpp"
#include "pixmap.hpp"

#include <list>
#include <memory>

namespace shapes
{
    class AbstractShape;
    using AbstractShapePtr = std::unique_ptr<AbstractShape>;

    class AbstractShape
    {
        public:
        virtual ~AbstractShape() = default;
        
        virtual const PixMap& getPixMap() = 0;

        virtual bool setSize(Height h, Length l, const std::list<AbstractShapePtr>& colliders) = 0;
        virtual bool setHeight(Height h, const std::list<AbstractShapePtr>& colliders) = 0;
        virtual bool setLength(Length l, const std::list<AbstractShapePtr>& colliders) = 0;
        virtual Size getSize() const = 0;

        virtual Color getColor() const = 0;
        virtual void setColor(Color color) = 0;
        
        virtual Point getPosition() const = 0;
        virtual bool move(Point point, const std::list<AbstractShapePtr>& colliders) = 0;
    };
}
