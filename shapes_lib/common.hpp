#pragma once

#include <cstdint>

namespace shapes
{
    using Coord = uint8_t;

    using Height = Coord;
    using Length = Coord;
    struct Size
    {
        Height h = 0;
        Length l = 0;
    };

    using XCoord = Coord;
    using YCoord = Coord;

    struct Point
    {
        XCoord x = 0;
        YCoord y = 0;
    };

    using Color = int;

    struct BoundingBox
    {
        XCoord xMin = 0;
        XCoord xMax = 0;
        YCoord yMin = 0;
        YCoord yMax = 0;
    };

}
