#pragma once

#include "common.hpp"
#include "abstract_shape.hpp"

namespace shapes
{
    class AbstractCanvas
    {
    public:
        virtual ShapeHandle addShape(AbstractShapePtr shape) = 0;
        virtual bool removeShape(ShapeHandle handle) = 0;

        virtual const std::list<AbstractShapePtr> &GetShapes() const = 0;
    };
}
