#ifndef RECT_H_
#define RECT_H_

#include "screen.h"

namespace std {
    class rect : public Screen{
        public:
        rect(const Screen &screen, int x, int y, int w, int h, int color);

        void draw() const;

        private:
        int _x, _y;
        int _w, _h;
        int _color; 
    };
}

#endif
