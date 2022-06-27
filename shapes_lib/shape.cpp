#include "shape.hpp"

namespace shapes
{
    bool Shape::checkCollision(const std::list<AbstractShapePtr> &colliders)
    {
        for (auto const &i : colliders)
        {
            if (checkCollision(i))
            {
                return true;
            }
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
