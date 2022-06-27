#pragma once

#include "common.hpp"

#include <stdexcept>
#include <memory>

namespace shapes
{
    class PixMap
    {
    private:
        Color* array = nullptr;
        Size size;

        XCoord xMax = 0;
        YCoord yMax = 0;

    public:
        PixMap(Size size) : PixMap(size.l, size.h) {}
        PixMap(Height l, Length h);
        PixMap(const PixMap& other) : PixMap(other.getSize())
        {
        }
        PixMap &operator=(PixMap other) noexcept
        {
            std::swap(array, other.array);
            this->size = other.size;
            this->xMax = other.xMax;
            this->yMax = other.yMax;
            return *this;
        }

        virtual ~PixMap();

        const Color &at(XCoord x, YCoord y) const;
        Color &at(XCoord x, YCoord y);

        Size getSize() const
        {
            return size;
        }

        bool set(Point point, const PixMap &pixMap);
        bool unset(Point point, const PixMap &pixMap);

        void clear();

        void print() const;

    private:
        enum class Operation
        {
            Set,
            Unset
        };
        bool modify(Point point, const PixMap &pixMap, Operation op);
    };
}
