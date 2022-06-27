#include "canvas.hpp"

namespace shapes
{
    ShapeHandle Canvas::handleGenerator = 0;

    OptionalShapeHandle Canvas::addShape(AbstractShapePtr shape)
    {
        if (!shape)
        {
            return std::nullopt;
        }

        if (shape->checkCollision(shapes, pixMap.getSize()))
        {
            return std::nullopt;
        }

        shape->setParent(this);
        auto h = generateHandle();
        shape->setHandle(h);
        shapes.emplace_back(std::move(shape));
        return h;
    }

    bool Canvas::removeShape(ShapeHandle handle)
    {
        auto it = std::find_if(shapes.begin(), shapes.end(), [handle](const AbstractShapePtr &ptr)
                               { return ptr->getHandle() == handle; });
        if (it == shapes.end())
        {
            // cannot find
            return false;
        }
        auto ret = pixMap.unset((*it)->getPosition(), (*it)->getPixMap());
        if (ret)
        {
            (*it)->setParent(nullptr);
            shapes.remove(*it);
        }
        return ret;
    }

    void Canvas::update()
    {
        pixMap.clear();
        pixMap.print();
        for (const auto &shape : shapes)
        {
            pixMap.set(shape->getPosition(), shape->getPixMap());
        }
        pixMap.print();
    }
}
