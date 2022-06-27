#pragma once

#include "common.hpp"
#include "abstract_shape.hpp"

namespace shapes
{
    class AbstractCanvas
    {
    public:
        virtual OptionalShapeHandle addShape(AbstractShapePtr shape) = 0;
        virtual bool removeShape(ShapeHandle handle) = 0;
        
        virtual const std::list<AbstractShapePtr> &GetShapes() = 0;
        virtual Size getSize() const = 0;
        virtual void update() = 0;
    };
}
