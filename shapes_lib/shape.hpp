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

        const PixMap &getPixMap() override
        {
            return pixMap;
        }

        Color getColor() const override
        {
            return attributes.color;
        }
        void setColor(Color color) override
        {
            attributes.color = color;
            setPixMap();
        }

        Point getPosition() const override
        {
            return attributes.position;
        }

        bool setSize(Length l, Height h) override;
        virtual bool setSizePolicy(Length l, Height h);
        Size getSize() const override
        {
            return attributes.size;
        }

        bool move(Point position) override
        {
            // TODO:: do
            return true;
        }

        void setHandle(ShapeHandle handle_) override
        {
            handle = handle_;
        }

        OptionalShapeHandle getHandle() const override
        {
            return handle;
        }

        bool checkCollision(const std::list<AbstractShapePtr> &colliders, const Size &size) override;

        void setParent(AbstractCanvas *canvas) override
        {
            parent = canvas;
        }

        const BoundingBox &getBoundingBox() const override
        {
            return boundingBox;
        }

    protected:
        struct
        {
            Point position;
            Size size;
            Color color = 0;
        } attributes;

        OptionalShapeHandle handle;
        AbstractCanvas *parent = nullptr;

        virtual void setPixMap() = 0;
        PixMap pixMap;

        void setBoundingBox()
        {
            boundingBox.xMin = attributes.position.x;
            boundingBox.yMin = attributes.position.y;
            boundingBox.xMax = attributes.position.x + attributes.size.l-1;
            boundingBox.yMax = attributes.position.y + attributes.size.h-1;
        }
        BoundingBox boundingBox;

        bool checkCollision(const AbstractShapePtr &otherShape);
        bool checkCollision(const Size &size);
    };

}
