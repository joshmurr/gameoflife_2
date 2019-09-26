/*
 * screen.cpp
 *
 *  Created on: 23 Jul 2019
 *      Author: joshmurr
 */

#include "screen.h"

namespace std {
// Constructor
Screen::Screen() : m_window(NULL), m_renderer(NULL) { }

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	m_window = SDL_CreateWindow("Game of Life",
	SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	return true;
}

/*void Screen::clear() {
 *    memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
 *}
 */

void Screen::update() {
	SDL_RenderPresent(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 200, 255);
	SDL_RenderClear(m_renderer);
}

bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}
void Screen::close() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}

int Screen::getWidth(){
    return SCREEN_WIDTH;
}

int Screen::getHeight(){
    return SCREEN_HEIGHT;
}


} /* namespace std */
