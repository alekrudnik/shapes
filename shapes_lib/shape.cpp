#include "shape.hpp"
#include "abstract_canvas.hpp"

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
            // check if self
            if(getHandle() == i->getHandle())
            {
                continue;
            }

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

    bool Shape::setSize(Length l, Height h)
    {
        auto sizeCopy = attributes.size;
        auto applyChanges = [this]()
        {
            setBoundingBox();
            pixMap = PixMap(attributes.size);
            setPixMap();
        };
        if(!setSizePolicy(l,h))
        {
            return false;
        }
        attributes.size.h = h;
        attributes.size.l = l;
        applyChanges();
        if (parent && checkCollision(parent->GetShapes(), parent->getSize()))
        {
            attributes.size = sizeCopy;
            applyChanges();
            return false;
        }

        return true;
    }

    bool Shape::setSizePolicy(Length l, Height h)
    {
        return true;
    }

    bool Shape::move(Point position)
    {
        auto positionCopy = attributes.position;
        auto applyChanges = [this]()
        {
            setBoundingBox();
        };
        attributes.position = position;
        applyChanges();
        if (parent && checkCollision(parent->GetShapes(), parent->getSize()))
        {
            attributes.position = positionCopy;
            applyChanges();
            return false;
        }

        return true;
    }
}
