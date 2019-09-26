#include "rect.h"

namespace std {
    rect::rect(const Screen &screen, int x, int y, int w, int h, int color) :
   Screen(screen), _x(x), _y(y), _w(w), _h(h), _color(color) {}

    void rect::draw() const {
        SDL_Rect rect; 

        rect.x = _x;
        rect.y = _y;
        rect.w = _w;
        rect.h = _h;

        int bwcolor = _color*255;

        SDL_SetRenderDrawColor(m_renderer, bwcolor, bwcolor, bwcolor, 255);
        SDL_RenderFillRect(m_renderer, &rect);

    };

}
