#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include "screen.h"
#include "rect.h"
#include "game.h"

using namespace std;

int main() {
	Screen screen;

	if (!screen.init()) {
		cout << "Error initializing SDL..." << endl;
	}

    game game(10, screen.getWidth(), screen.getHeight());

    rect rect(screen, 100, 100, 20, 20, 1);

	while (true) {

		int width = screen.getWidth();
		int height = screen.getHeight();
        /*
         *for (int x = 0; x < width; x++) {
         *    for (int y = 0; y < height; y++) {
         *        // screen.setCell > set the status of each cell, rather than pixel
         *        screen.setPixel(x, y, 255, 255, 255);
         *    }
         *}
         */
        rect.draw();

		screen.update();

		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
