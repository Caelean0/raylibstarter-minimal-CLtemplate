//
// Created by keanu on 06.03.2024.
//

#include <iostream>
#include <limits>
#include "PlantHandler.h"
#include "Tree.h"
#include "Grass.h"
#include "Bush.h"
#include "Flower.h"


namespace console::plant
{
    int PlantHandler::handleUser()
    {
        bool cont = true;
        PlantType selected = TREE;
        int input = 0;
        do
        {
            std::cout << "Hier koennen Informationen zu verschiedenen Pflanzen angezeigt werden." << std::endl;
            std::cout << "Bitte waehlen Sie die Pflanze Ihres Interesses aus:" << std::endl;
            for (auto &i: plantTypeMap)
            {
                std::cout << i.first << ": " << i.second << std::endl;
            }

            try
            {
               std::cin >> input;
                (input<0 || input>3) ? (throw std::exception()) : (selected = static_cast<PlantType>(input));
            } catch(...)
            {
                std::cout << "Ihre Eingabe ist ungueltig. Bitte versuchen Sie es erneut." << std::endl;
                continue;
            }
            switch (selected)
            {
                case TREE:
                    plantFrame_ = new Tree();
                    break;
                case GRASS:
                    plantFrame_ = new Grass();
                    break;
                case BUSH:
                    plantFrame_ = new Bush();
                    break;
                case FLOWER:
                    plantFrame_ = new Flower();
                    break;
            }
            int years = 0;
            std::cout << "Ihre Pflanzenart: " << plantTypeMap[selected] << std::endl;
            std::cout << "Diese hat eine maximale Hoehe von: " << plantFrame_->getMaxSize() << "cm" << std::endl;
            std::cout << "Diese hat eine maximale Wurzellaenge von: " << plantFrame_->getMaxRootLength() << "cm" << std::endl;
            std::cout << "Diese hat die Blattfarbe: " << plantFrame_->getLeafColor() << std::endl;
            std::cout << "Diese hat einen Samendurchmesser von: " << plantFrame_->getSeedDiameter() << "mm" << std::endl;
            std::cout << "Bitte geben Sie die Anzahl der Wuchsjahre an: " << std::endl;

            do
            {

                try
                {
                    std::cin >> years;
                    (years<0) ? (throw std::exception()) : years;
                } catch (...)
                {
                    std::cout << "Ihre Eingabe ist ungueltig. Bitte versuchen Sie es erneut." << std::endl;
                }
                break;
            } while(true);

            std::cout << "Die Pflanze hat nach " << years << " Wuchsjahren eine Hoehe von: " << plantFrame_->getHeight(years) << "cm" << std::endl;
            std::cout << "Die Pflanze hat nach " << years << " Wuchsjahren eine Wurzellaenge von: " << plantFrame_->getRootLength(years) << "cm" << std::endl;
            std::cout<<std::endl;

            delete plantFrame_;
            plantFrame_ = nullptr;

            char again = 'n';
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wollen Sie eine andere Pflanze auswaehlen? (j/n) " << std::endl;
            std::cin >> again;
            if (again != 'j')
            {
                cont = false;
            }


        } while (cont);


        return 0;
    }

    PlantHandler::PlantHandler()
    {
        plantFrame_ = nullptr;
    }

}