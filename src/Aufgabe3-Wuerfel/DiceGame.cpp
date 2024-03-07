//
// Created by keanu on 05.03.2024.
//

#include "DiceGame.h"

game::dice::DiceGame::DiceGame(): facesSelectors({Rectangle{0,100,150,150}, Rectangle{200,100,150,150}, Rectangle{400,100,150,150}, Rectangle{600,100,150,150}, Rectangle{800,100,150,150}, Rectangle{1000,100,150,150}})
{
    selectedFace = d4;
    resultsDisplay = {new std::string("Player: 0"), new std::string("Computer: 0")};
    points = {0,0};
    selectorToFace = {
            {d4, facesSelectors[0]},
            {d6, facesSelectors[1]},
            {d8, facesSelectors[2]},
            {d10, facesSelectors[3]},
            {d12, facesSelectors[4]},
            {d20, facesSelectors[5]}
    };
    resultdisplayToRec = {
            {resultsDisplay[0], {300, 300, 300, 150}},
            {resultsDisplay[1], {800, 300, 300, 150}}
    };
}

game::dice::DiceGame::~DiceGame()
{

}

void game::dice::DiceGame::draw()
{
    for (auto &i: selectorToFace)
    {
        DrawRectangleRec(i.second, DARKGRAY);
        DrawText(facesToText[i.first].c_str(), static_cast<int> (i.second.x + 10), static_cast<int>( i.second.y + 10), 30, WHITE);
    }
    for (auto &i : resultdisplayToRec)
    {
        DrawRectangleRec(i.second, DARKGRAY);
        DrawText((*i.first).c_str(), static_cast<int> (i.second.x + 10), static_cast<int>( i.second.y + 10), 30, WHITE);
    }
    std::string playerPoints = "Player: " + std::to_string(points[0]);
    std::string computerPoints = "Computer: " + std::to_string(points[1]);
    DrawText(playerPoints.c_str(), 10, 10, 30, BLACK);
    DrawText(computerPoints.c_str(), 10, 50, 30, BLACK);
}

void game::dice::DiceGame::update()
{
    Vector2 mousePos = GetMousePosition();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        for (auto &i: selectorToFace)
        {
            if (CheckCollisionPointRec(mousePos, i.second))
            {
                selectedFace = i.first;
                playRound();
            }
        }

    }
}

int game::dice::DiceGame::roll()
{
    int selectedValue = selectedFace;
    return GetRandomValue(1, selectedValue);
}

void game::dice::DiceGame::playRound()
{
    int player = roll();
    int computer = roll();

    *resultsDisplay[0] = "Player: " + std::to_string(player);
    *resultsDisplay[1] = "Computer: " + std::to_string(computer);

    if (player > computer)
    {
        points[0]++;
    } else if (player < computer) {
        points[1]++;
    }
}
