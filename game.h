#ifndef GAME_H
#define GAME_H


class Game
{
public:
    Game();

    int get_order();
    int check_win();
    void set_input(const int& row, const int& col);
    void next_game();

private:
    int order;
    int arr[3][3];
};

#endif // GAME_H
