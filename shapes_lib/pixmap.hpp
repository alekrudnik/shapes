#pragma once

#include "common.hpp"

#include <stdexcept>
#include <memory>

namespace shapes
{
    class PixMap
    {
    private:
        std::unique_ptr<Color[]> array;
        Size size;

        XCoord xMax = 0;
        YCoord yMax = 0;

    public:
        PixMap(Size size) : PixMap(size.l, size.h) {}
        PixMap(Height l, Length h);

        virtual ~PixMap() = default;

        const Color &at(XCoord x, YCoord y) const;
        Color &at(XCoord x, YCoord y);

        Size GetSize() const
        {
            return size;
        }

        bool set(Point point, const PixMap &pixMap);
        bool unset(Point point, const PixMap &pixMap);

        void print();

    private:
        enum class Operation
        {
            Set,
            Unset
        };
        bool modify(Point point, const PixMap &pixMap, Operation op);
    };
}
