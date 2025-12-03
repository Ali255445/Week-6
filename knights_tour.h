#ifndef KNIGHTS_TOUR_H
#define KNIGHTS_TOUR_H

#include <stdbool.h>
#include <stddef.h>

#define SIZE 8       // Brætstørrelse

// Springerens mulige træk fra nuværende position
#define MOVE_COUNT 8 // Antal mulige træk for en springer
extern const int MOVES_X[MOVE_COUNT];
extern const int MOVES_Y[MOVE_COUNT];

// Typedef for 2D array
typedef int board_t[SIZE][SIZE];

// Tjekker om et springertræk er muligt
bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited);

// Forsøger en tour med greedy-algoritme
unsigned int tour_greedy(size_t start_x, size_t start_y);

// Kører tour fra alle felter og printer resultater
void greedy_tour_from_each_square();

#endif // KNIGHTS_TOUR_H