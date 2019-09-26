/*
 * game.h
 *
 *  Created on: 23 Jul 2019
 *      Author: joshmurr
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include "screen.h"

namespace std {

class game {
private:
	int width, height;
    int cell_size;
    int cols, rows;
    int total_cells;
	unsigned char *m_cells;
    unsigned char *m_cells_buffer;
	int lastTime;
public:
	game(const int cs, const int w, const int h);
	virtual ~game();
	void update(int elapsed);

	unsigned char *getCells() {
		return m_cells;
	}
};

} /* namespace std */

#endif /* SRC_GAME_H_ */
