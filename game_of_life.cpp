#include "game_of_life.h"
#include <cstdlib>
#include <iostream>

using namespace std;

game_of_life::game_of_life() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            _generation[i][j] = rand() % 2 == 1;
        }
    }
}

bool game_of_life::cell_taken(int i, int j) {
    return i >= 0 && i < ROWS&& j >= 0 && j < COLS&& _generation[i][j];
}

void game_of_life::next_generation() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;

            neighbors += cell_taken(i - 1, j - 1);
            neighbors += cell_taken(i - 1, j);
            neighbors += cell_taken(i - 1, j + 1);
            neighbors += cell_taken(i, j - 1);
            neighbors += cell_taken(i, j + 1);
            neighbors += cell_taken(i + 1, j - 1);
            neighbors += cell_taken(i + 1, j);
            neighbors += cell_taken(i + 1, j + 1);

            if (_generation[i][j]) {
                _next_generation[i][j] = (neighbors == 2 || neighbors == 3);
            }
            else {
                _next_generation[i][j] = (neighbors == 3);
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            _generation[i][j] = _next_generation[i][j];
        }
    }
}

void game_of_life::draw() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << (_generation[i][j] ? "O" : ".");
        }
        cout << endl;
    }
}
