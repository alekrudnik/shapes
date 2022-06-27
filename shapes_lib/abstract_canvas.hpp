#pragma once

#include "common.hpp"
#include "abstract_shape.hpp"

namespace shapes
{
    class AbstractCanvas
    {
    public:
        // adds shape to the canvas
        //
        // @param shape shapes to be added
        //
        // @return valid handle on success, std::nullopt on failure
        virtual OptionalShapeHandle addShape(AbstractShapePtr shape) = 0;

        // removes shapes from canvas
        //
        // @param handle - shape handle 
        //
        // @return true on success, false on failure
        virtual bool removeShape(ShapeHandle handle) = 0;
        
        // returns list of shapes
        virtual const std::list<AbstractShapePtr> &GetShapes() = 0;
        
        // update changes to internal data structure after applying modifications
        virtual void update() = 0;

        virtual Size getSize() const = 0;
        
    };
}
