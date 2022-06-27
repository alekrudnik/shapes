#pragma once

#include "common.hpp"
#include "pixmap.hpp"

#include <list>
#include <memory>
#include <limits>

namespace shapes
{
    class AbstractShape;
    using AbstractShapePtr = std::unique_ptr<AbstractShape>;

    class AbstractCanvas;
    
    class AbstractShape
    {
        public:
        virtual ~AbstractShape() = default;
        
        // returns generated pixMap
        virtual const PixMap& getPixMap() = 0;

        virtual bool setSize(Height h, Length l) = 0;
        virtual bool setHeight(Height h) = 0;
        virtual bool setLength(Length l) = 0;
        virtual Size getSize() const = 0;

        virtual Color getColor() const = 0;
        virtual void setColor(Color color) = 0;
        
        virtual Point getPosition() const = 0;
        virtual bool move(Point point) = 0;

        virtual ShapeHandle getHandle() const = 0;

        virtual const BoundingBox& getBoundingBox() const = 0;

        virtual bool checkCollision(const std::list<AbstractShapePtr> &colliders) = 0;

        virtual void setParent (AbstractCanvas* canvas) = 0;

        
    };
}
