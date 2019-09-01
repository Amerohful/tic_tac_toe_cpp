#include "game.h"

Game::Game() {
    order = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = 0;
        }
    }
}

int Game::get_order() {
    return order;
}

int Game::check_win() {
    for (int i = 0; i < 3; ++i) {
        if (arr[i][0] == 1 && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
            return 1;
        } else if (arr[i][0] == 2 && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
            return 2;
        } else if (arr[0][i] == 1 && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) {
            return 1;
        } else if (arr[0][i] == 2 && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) {
            return 2;
        } else if (arr[0][0] == 1 && arr[1][1] == arr[0][0] && arr[2][2] == arr[0][0] ||
                   arr[0][2] == 1 && arr[1][1] == arr[0][2] && arr[2][0] == arr[0][2]) {
            return 1;
        } else if (arr[0][0] == 2 && arr[1][1] == arr[0][0] && arr[2][2] == arr[0][0] ||
                   arr[0][2] == 2 && arr[1][1] == arr[0][2] && arr[2][0] == arr[0][2]) {
            return 2;
        }
    }
    return 3;
}

void Game::set_input(const int &row, const int &col) {
    if (arr[row][col] == 0) {
        order % 2 == 0 ? arr[row][col] = 1 : arr[row][col] = 2;
        order++;
    }
}

void Game::next_game() {
    order = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = 0;
        }
    }
}
