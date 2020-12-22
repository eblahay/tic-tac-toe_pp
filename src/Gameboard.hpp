#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <vector>
#include <memory>

#include "Coord.hpp"
#include "player.hpp"

class Gameboard{
    public:
        Gameboard(std::vector<char> theme={'0', '1', '2'});

        void changeTurn();

        void claimSpace(Coord position, int claimant);

        void drawBoard();

        void handleTurn();

        int findWinner();

        //functions that set the value(s) of class members
        void setMark(Coord position, char mark);

        //functions that return objects
        char getMark(Coord position);
        char getMark(int x, int y);

        int getBoardWidth() const ;
        int getBoardHeight() const ;

        //public non-function class members
        const std::vector<char> MARKS;
        constexpr static int
            UNDECIDED = -1,
            STALEMATE = -2
        ;
    private:
        const int BOARD_WIDTH, BOARD_HEIGHT;

        std::vector<std::vector<char>> board;
        std::vector<std::unique_ptr<PlayerBase>> players;

        int turn=0, turn_holder_index=0;
};

#endif