//
// Created by keanu on 05.03.2024.
//

#ifndef RAYLIBSTARTER_DICEGAME_H
#define RAYLIBSTARTER_DICEGAME_H


#include <vector>
#include "DiceSupport.h"

namespace game::dice
{
    class DiceGame
    {
    public:
        DiceGame();
        ~DiceGame();
        void draw();
        void update();

    private:
        int roll();
        void playRound();
        std::vector<int> points;
        std::vector<std::string*> resultsDisplay;
        std::map<std::string*, Rectangle> resultdisplayToRec;

        const std::vector<Rectangle> facesSelectors;
        Faces selectedFace;
        std::map<Faces, Rectangle> selectorToFace;




    };
}


#endif //RAYLIBSTARTER_DICEGAME_H
