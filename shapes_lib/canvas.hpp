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

        OptionalShapeHandle addShape(AbstractShapePtr shape) override;
        bool removeShape(ShapeHandle handle) override;

        const std::list<AbstractShapePtr>& GetShapes() override
        {
            return shapes;
        }

        static ShapeHandle generateHandle()
        {
            return ++handleGenerator;
        }

        Size getSize() const override
        {
            return pixMap.getSize();
        }

        void update() override;

        const PixMap & getPixMap() const
        {
            return pixMap;
        }

        private:
        PixMap pixMap;
        std::list<AbstractShapePtr> shapes;
        static ShapeHandle handleGenerator;
    };
}
