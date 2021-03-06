#include "pixmap.hpp"

#include <iostream>

namespace shapes
{
    PixMap::PixMap(Height l, Length h) : size{l, h}
    {
        array = new Color[l*h];
        
        clear();

        xMax = l - 1;
        yMax = h - 1;
    }
    PixMap::~PixMap()
    {
        delete[] array;
        array = nullptr;
    }

    void PixMap::clear()
    {
        std::fill(array, array + size.l*size.h, '\0');
    }

    const Color &PixMap::at(XCoord x, YCoord y) const
    {
        if ((x > size.l) || (y > size.h))
            throw std::out_of_range("out of range");

        return array[x * size.h + y];
    }

    Color &PixMap::at(XCoord x, YCoord y)
    {
        return const_cast<Color &>(const_cast<const PixMap *>(this)->at(x, y));
    }

    void PixMap::print() const
    {
        for (size_t i = 0; i < size.h; i++)
        {
            for (size_t j = 0; j < size.l; j++)
            {
                std::cout <<std::hex<< int(at(j,i));
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    bool PixMap::modify(Point point, const PixMap& pixMap,  Operation op)
    {
        auto pixXMax = point.x + pixMap.size.l - 1;
        auto pixYMax = point.y + pixMap.size.h - 1;
        if(pixXMax > xMax || pixYMax > yMax)
        {
            return false;   
        }

        for(Coord y = 0; y < pixMap.size.h; y++)
        {
            for(Coord x = 0; x < pixMap.size.l; x++)
            {
                const auto color = pixMap.at(x, y);
                if(color != 0)
                {
                    at(x+point.x, y+point.y) = op == Operation::Set ? color : 0;
                }
            }
        }
        return true;
    }

    bool PixMap::set(Point point, const PixMap& pixMap)
    {
        return modify(point, pixMap, Operation::Set);
    }
        
    bool PixMap::unset(Point point, const PixMap &pixMap)
    {
        return modify(point, pixMap, Operation::Unset);
    }
}
