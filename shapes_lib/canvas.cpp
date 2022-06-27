#include "canvas.hpp"

namespace shapes
{
    Handle Canvas::handleGenerator = 0;

    ShapeHandle Canvas::addShape(AbstractShapePtr shape)
    {   
        if(!shape)
        {
            return std::nullopt;
        }

        if(shape->checkCollision(shapes))
        {
            return std::nullopt;
        }
        
        auto ret = pixMap.set(shape->getPosition(), shape->getPixMap());
        pixMap.print();
        if(ret)
        {
            shape->setParent(this);
            shapes.emplace_back(std::move(shape));
        }
        return ret;
    }
    
    
    bool Canvas::removeShape(ShapeHandle handle)
    {
        auto it = std::find_if(shapes.begin(), shapes.end(), [handle](const AbstractShapePtr& ptr){return ptr->getHandle() == handle;});
        if(it == shapes.end())
        {
            // cannot find
            return false;
        }
        auto ret = pixMap.unset((*it)->getPosition(), (*it)->getPixMap());
        pixMap.print();
        if(ret)
        {
            (*it)->setParent(nullptr);
            shapes.remove(*it);
        }
        return ret;
    }
}
