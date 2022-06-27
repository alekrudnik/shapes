#pragma once

#include "abstract_canvas.hpp"
#include "common.hpp"
#include "shape.hpp"
#include "pixmap.hpp"

#include <list>

namespace shapes
{
    class Canvas : public AbstractCanvas
    {
        public:
        Canvas(Height h, Length l) : pixMap(h,l)
        {} 

        ShapeHandle addShape(AbstractShapePtr shape) override;
        bool removeShape(ShapeHandle handle) override;

        const std::list<AbstractShapePtr>& GetShapes() const override
        {
            return shapes;
        }

        static Handle generateHandle()
        {
            return ++handleGenerator;
        }

        private:
        PixMap pixMap;
        std::list<AbstractShapePtr> shapes;
        static Handle handleGenerator;
    };
}
