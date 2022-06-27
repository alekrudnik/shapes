#include "shape.hpp"

namespace shapes
{
    bool Shape::checkCollision(const std::list<AbstractShapePtr> &colliders, const Size &margins)
    {
        if(checkCollision(margins))
        {
            return true;
        }
        
        for (auto const &i : colliders)
        {
            if (checkCollision(i))
            {
                return true;
            }
        }
        return false;
    }

    bool Shape::checkCollision(const Size &margins)
    {
        if(boundingBox.xMax >= margins.l || boundingBox.yMax >= margins.h)
        {
            return true;
        }
        return false;
    }

    bool Shape::checkCollision(const AbstractShapePtr &otherShape)
    {
        auto otherBoundingBox = otherShape->getBoundingBox();

        // Simplified collision detection, only bounding box checking
        if (boundingBox.xMin > otherBoundingBox.xMax)
        {
            return false;
        }
        if (boundingBox.xMax < otherBoundingBox.xMin)
        {
            return false;
        }
        if (boundingBox.yMin > otherBoundingBox.yMax)
        {
            return false;
        }
        if (boundingBox.yMax < otherBoundingBox.yMin)
        {
            return false;
        }

        return true;
    }
}
