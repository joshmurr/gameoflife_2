/*
 * screen.h
 *
 *  Created on: 23 Jul 2019
 *      Author: joshmurr
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace std {

class Screen {
public:
	const static int SCREEN_WIDTH = 600;
	const static int SCREEN_HEIGHT = 400;
private:
	SDL_Window *m_window;
protected:
	SDL_Renderer *m_renderer;

public:
	Screen();
	bool init();
	void update();
	bool processEvents();
	void close();
    int getWidth();
    int getHeight();
};

} /* namespace std */

#endif /* SCREEN_H_ */
