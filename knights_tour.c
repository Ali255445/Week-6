#include "knights_tour.h"
#include <stdio.h>

// Springerens træk
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited) {
    // Tjek om move ID er gyldigt
    if (move_id >= MOVE_COUNT) return false;
    
    // Beregn ny position
    int new_x = x + MOVES_X[move_id];
    int new_y = y + MOVES_Y[move_id];
    
    // Er vi stadig på brættet?
    if (new_x < 0 || new_x >= SIZE || new_y < 0 || new_y >= SIZE) {
        return false;
    }
    
    // Er feltet ubesøgt?
    return visited[new_y][new_x] == 0;
}

unsigned int tour_greedy(size_t start_x, size_t start_y) {
    // Stack-based memory med typedef
    board_t visited = {0};  // Initialiser med 0 (ubesøgt)
    
    size_t current_x = start_x;
    size_t current_y = start_y;
    unsigned int move_count = 1;
    visited[current_y][current_x] = move_count;
    
    // Fortsæt så længe vi kan finde træk
    while (1) {
        bool found_move = false;
        
        // Prøv alle 8 mulige træk
        for (size_t move_id = 0; move_id < MOVE_COUNT; move_id++) {
            if (move_is_possible(move_id, current_x, current_y, visited)) {
                // Udfør det første gyldige træk
                current_x += MOVES_X[move_id];
                current_y += MOVES_Y[move_id];
                move_count++;
                visited[current_y][current_x] = move_count;
                found_move = true;
                break;  // Tag det første vi finder
            }
        }
        
        // Ingen flere træk mulige
        if (!found_move) {
            break;
        }
    }
    
    return move_count;
}

void greedy_tour_from_each_square() {
    // Memory til resultater
    board_t results;
    
    // Kør tour fra alle startpositioner
    for (size_t y = 0; y < SIZE; y++) {
        for (size_t x = 0; x < SIZE; x++) {
            results[y][x] = tour_greedy(x, y);
        }
    }
    
    // Print resultater
    printf("Greedy:\n");
    for (size_t y = 0; y < SIZE; y++) {
        for (size_t x = 0; x < SIZE; x++) {
            printf("%2d ", results[y][x]);
        }
        printf("\n");
    }
}