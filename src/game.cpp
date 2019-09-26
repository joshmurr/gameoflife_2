/*
 * game.cpp
 *
 *  Created on: 23 Jul 2019
 *      Author: joshmurr
 */

#include "game.h"
#include <iostream>

namespace std {

game::game(const int cs, const int w, const int h) :
    lastTime(0) {
        width = w;
        height = h;
        cell_size = cs;
        cols = width/cell_size;
        rows = height/cell_size;
        total_cells = cols * rows;
        m_cells = new unsigned char[total_cells];
        m_cells_buffer = new unsigned char[total_cells];

        // Initialize cells with random state (1 or 0)
        for (int i = 0; i < total_cells; i++) {
            m_cells[i] = (2.0 * rand()) / RAND_MAX;
        }
    }

game::~game() {
	delete[] m_cells;
    delete[] m_cells_buffer;
}

void game::update(int elapsed) {
	int interval = elapsed - lastTime;

	for (int x = 0; x < cols; x++) {
		for (int y = 0; y < rows; y++) {
            // State of curent cell
			unsigned char current_state = m_cells[y * cols + x];
			int sum = 0;
			for (int x_local = -1; x_local <= 1; x_local++) {
				for (int y_local = -1; y_local <= 1; y_local++) {

                    // Cell to check
					int currentX = x + x_local;
					int currentY = y + y_local;

                    // Edge checking
					if (currentX < 0) {
						currentX = width;
					}
					if (currentX > width) {
						currentX = 0;
					}
					if (currentY < 0) {
						currentY = height;
					}
					if (currentY > height) {
						currentY = 0;
					}

					//if (currentX >= 0 && currentX < width && currentY >= 0 && currentY < height) {
					sum += m_cells[currentY * cols + currentX];


				}
			}
			sum -= m_cells[y * cols + x];
			if (current_state == 0 && sum == 3) {
				m_cells_buffer[y * width + x] = 1;
			} else if (current_state == 1 && (sum < 2 || sum > 3)) {
				m_cells_buffer[y * width + x] = 0;
			} else {
				m_cells_buffer[y * width + x] = m_cells[y * cols + x];
			}

			//m_cells_buffer[y * width + x] = (2.0 * rand()) / RAND_MAX;
		}
	}

	m_cells = m_cells_buffer;

	lastTime = elapsed;
}

} /* namespace std */
