#pragma once

#include "abstract_shape.hpp"

namespace shapes
{
    class Shape : public AbstractShape
    {
    public:
        Shape(Point position, Size size, Color color) : attributes{position, size, color}, pixMap(size)
        {
            setBoundingBox();
        }

        virtual ~Shape() = default;

        const PixMap& getPixMap() override{
            return pixMap;
        }

        Color getColor() const override
        {
            return attributes.color;
        }
        void setColor(Color color) override
        {
            attributes.color = color;
        }

        Point getPosition() const override
        {
            return attributes.position;
        }

        Size getSize() const override
        {
            return attributes.size;
        }

        bool move(Point position, const std::list<AbstractShapePtr> &colliders) override
        {
            // TODO:: do
            return true;
        }

    protected:
        struct
        {
            Point position;
            Size size;
            Color color = 0;
        } attributes;

        virtual void setPixMap() = 0;
        PixMap pixMap;

        void setBoundingBox()
        {
            boundingBox.xMin = attributes.position.x;
            boundingBox.yMin = attributes.position.y;
            boundingBox.xMax = attributes.position.x + attributes.size.l;
            boundingBox.yMax = attributes.position.y + attributes.size.h;
        }
        BoundingBox boundingBox;

        bool checkCollision(const std::list<AbstractShapePtr> &colliders)
        {
            for(auto const& i : colliders)
            {
               if(checkCollision(i))
               {
                return true;
               }
            }
            return false;
        }

        bool checkCollision(const AbstractShapePtr& otherShape)
        {
            return true;
        }
    };

}
