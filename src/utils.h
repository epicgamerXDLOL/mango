#pragma once
#include <SDL.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "gui/button.h"
#include "gui/canvas.h"
#include "gui/pen.h"
#include <map>
#include <SDL_ttf.h>
#include <iostream>
#include <algorithm>

#define HEXPEN hex(pen.color())

namespace utils
{
    struct CirclePoint
    {
        int xval;
        int yval;
        int arrayval;
    };

    class Circle
    {
    public:
        Circle(int r, int xc, int yc)
            : m_xc(xc), m_yc(yc), m_radius(r) {}

        void drawCircle(std::map<int, std::vector<int>>& circ_points, SDL_Renderer* rend, int xc, int yc, int x, int y);
       
        void draw(SDL_Renderer* rend);
        
        void move(int x, int y);

        int xc() { return m_xc; }
        int yc() { return m_yc; }
        int radius() { return m_radius; }

    private:
        int m_radius;
        int m_xc;
        int m_yc;
    };

    bool collides(int mx, int my, const SDL_Rect& rect);

    uint32_t hex(SDL_Color color);

    void render_text(SDL_Renderer* rend, const SDL_Rect& rect, const char* text, TTF_Font* font);

    void color_adjust(int& r, int& g, int& b);

    void label(SDL_Renderer* rend, const char* text, TTF_Font* font, const SDL_Point& point);

    void thickness_adjust(int& thickness);

    bool valid_point(gui::Canvas& canvas, CirclePoint c);
    
    void draw_with_thickness(uint32_t* arr, gui::Pen& pen, gui::Canvas& canvas, int xc, int yc, int r);

    void draw_circle(SDL_Renderer* rend, int xc, int yc, int r);
}
