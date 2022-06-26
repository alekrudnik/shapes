#pragma once

#include "common.hpp"
#include "shape.hpp"
#include "pixmap.hpp"

#include <list>

namespace shapes
{
    class Canvas
    {
        public:
        Canvas(Height h, Length l) : pixMap(h,l)
        {} 

        bool addShape(AbstractShapePtr shape);
        bool removeShape(AbstractShapePtr shape);

        private:
        PixMap pixMap;
        std::list<AbstractShapePtr> shapes;
    };
}
