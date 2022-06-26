#include "canvas.hpp"

namespace shapes
{
    bool Canvas::addShape(AbstractShapePtr shape)
    {   
        auto ret = pixMap.set(shape->getPosition(), shape->getPixMap());
        pixMap.print();
        if(ret)
        {
            shapes.emplace_back(std::move(shape));
        }
        return ret;
    }
    
    
    bool Canvas::removeShape(AbstractShapePtr shape)
    {
        return pixMap.unset(shape->getPosition(), shape->getPixMap());
    }
}
