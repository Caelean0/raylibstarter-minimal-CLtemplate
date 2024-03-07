//
// Created by keanu on 07.03.2024.
//

#include <iostream>
#include <limits>
#include "CarHandler.h"
#include "Cars/Audi/AudiEngine.h"
#include "Cars/Audi/AudiFrame.h"
#include "Cars/Audi/AudiGears.h"
#include "Cars/Audi/AudiSuspension.h"
#include "Cars/Audi/AudiWheels.h"
#include "Cars/Audi/AudiBrakes.h"
#include "Cars/Audi/AudiCar.h"
#include "Cars/Mercedes/MercedesEngine.h"
#include "Cars/Mercedes/MercedesFrame.h"
#include "Cars/Mercedes/MercedesGears.h"
#include "Cars/Mercedes/MercedesSuspension.h"
#include "Cars/Mercedes/MercedesWheels.h"
#include "Cars/Mercedes/MercedesBrakes.h"
#include "Cars/Mercedes/MercedesCar.h"


namespace console::car
{

    CarHandler::CarHandler()
    {
        carFrame_ = nullptr;
    }

    int CarHandler::handleUser()
    {
        do
        {
            delete carFrame_;
            carFrame_ = nullptr;

            CarType selected;
            std::cout << "Bitte waehlen Sie ein Auto aus:" << std::endl;
            for (auto &i: carTypeMap)
            {
                std::cout << i.first << ": " << i.second << std::endl;
            }
            std::cout << "2: Cancel" << std::endl;

            try
            {
                int selection = 0;
                std::cin >> selection;
                (selection < 0 || selection > 2) ? (throw std::exception())
                                                 : (selected = static_cast<CarType>(selection));
            } catch (...)
            {
                std::cout << "Ihre Eingabe ist ungueltig. Bitte versuchen Sie es erneut." << std::endl;
                continue;
            }

            //car init
            switch (selected)
            {
                case Audi:
                    engine_ = std::make_shared<audi::components::AudiEngine>(audi::components::AudiEngine());
                    frame_ = std::make_shared<audi::components::AudiFrame>(audi::components::AudiFrame());
                    gears_ = std::make_shared<audi::components::AudiGears>(audi::components::AudiGears());
                    suspension_ = std::make_shared<audi::components::AudiSuspension>(
                            audi::components::AudiSuspension());
                    wheels_ = std::make_shared<audi::components::AudiWheels>(audi::components::AudiWheels());
                    brakes_ = std::make_shared<audi::components::AudiBrakes>(audi::components::AudiBrakes());
                    carFrame_ = new audi::AudiCar(engine_, suspension_, frame_, wheels_, brakes_, gears_);
                    break;
                case Mercedes:
                    engine_ = std::make_shared<mercedes::components::MercedesEngine>(
                            mercedes::components::MercedesEngine());
                    frame_ = std::make_shared<mercedes::components::MercedesFrame>(
                            mercedes::components::MercedesFrame());
                    gears_ = std::make_shared<mercedes::components::MercedesGears>(
                            mercedes::components::MercedesGears());
                    suspension_ = std::make_shared<mercedes::components::MercedesSuspension>(
                            mercedes::components::MercedesSuspension());
                    wheels_ = std::make_shared<mercedes::components::MercedesWheels>(
                            mercedes::components::MercedesWheels());
                    brakes_ = std::make_shared<mercedes::components::MercedesBrakes>(
                            mercedes::components::MercedesBrakes());
                    carFrame_ = new mercedes::MercedesCar(engine_, suspension_, frame_, wheels_, brakes_, gears_);
                    break;
                default:
                    return 0;

            }

            std::cout << "Sie haben das Auto " << carTypeMap[selected] << " ausgewaehlt." << std::endl;

            do //Fahrt Routine
            {
                //Motor starten
                if (!carFrame_->getEngineOn())
                {
                    std::cout << "-------------------------------------------------------" << std::endl;
                    std::cout << std::endl;
                    std::cout << "Der Motor ist aus." << std::endl;
                    std::cout << "Soll er gestartet werden? (y/n)" << std::endl;
                    char answer = 'y';
                    try
                    {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> answer;
                    } catch (...)
                    {
                        std::cout << "Ihre Eingabe ist ungueltig. Bitte versuchen Sie es erneut." << std::endl;
                        continue;
                    }
                    if (answer == 'y')
                    {
                        carFrame_->startStopEngine();
                    } else
                    {
                        break;
                    }
                }

                //acceleration starten oder motor aus
                if (carFrame_->getMovementState() == resting && carFrame_->getEngineOn())
                {
                    std::cout << "-------------------------------------------------------" << std::endl;
                    std::cout << std::endl;
                    std::cout << "Der Motor ist gestartet." << std::endl;
                    std::cout << "Es gibt nun die folgenden Moeglichkeiten:" << std::endl;
                    std::cout << "0: Motor stoppen" << std::endl;
                    std::cout << "1: vorwaerts beschleunigen" << std::endl;
                    std::cout << "2: rueckwaerts beschleunigen" << std::endl;

                    int eingabe = 0;
                    try
                    {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> eingabe;
                        (eingabe < 0 || eingabe > 2) ? (throw std::exception()) : eingabe;
                    } catch (...)
                    {
                        std::cout << "Ihre Eingabe ist ungueltig. Bitte versuchen Sie es erneut." << std::endl;
                        continue;
                    }

                    if (eingabe == 0)
                    {
                        carFrame_->startStopEngine();
                        continue;
                    }
                    if (eingabe == 1)
                    {
                        carFrame_->setDriveDirection(forward);
                    } else if (eingabe == 2)
                    {
                        carFrame_->setDriveDirection(backward);
                    }
                    std::cout << "Wie lang soll beschleunigt werden? (in ganzen sek)" << std::endl;
                    try
                    {
                        eingabe = 0;
                        std::cin >> eingabe;
                        (eingabe < 0) ? (throw std::exception()) : eingabe;
                    } catch (...)
                    {
                        std::cout << "Ihre Eingabe ist ungueltig. Beschleunigung abgebrochen." << std::endl;
                        continue;
                    }
                    std::cout << "Das Auto wird jetzt beschleunigt." << std::endl;
                    std::cout << "Es wird mit " << carFrame_->accelerate(eingabe) << " m/s^2 beschleunigt."
                              << std::endl;
                    carFrame_->setMovementState(driving);
                    std::cout << "Die Geschwindigkeit betraegt jetzt: " << carFrame_->getSpeed() << " m/s" << std::endl;
                }

                //while driving
                if (carFrame_->getMovementState() == driving)
                {
                    Direction driveDir = carFrame_->getDriveDirection();
                    Turn turnDir = carFrame_->getTurnDirection();
                    GearShift currentGear = carFrame_->getCurrentGear();

                    std::cout << "-------------------------------------------------------" << std::endl;
                    std::cout << std::endl;
                    std::cout << "Auto faehrt mit einer Geschwindigkeit von: " << carFrame_->getSpeed()
                              << " m/s, im Gang: " << gearShiftMap[currentGear] << ", in Richtung: "
                              << directionMap[driveDir] << ", nach: " << turnMap[turnDir] << std::endl;
                    std::cout << "Es gibt nun die folgenden Moeglichkeiten:" << std::endl;

                    if (turnDir != straight)
                    {
                        std::cout << "0: Geradeaus fahren" << std::endl;
                    }
                    if (turnDir != left)
                    {
                        std::cout << "1: Linkskurve fahren" << std::endl;
                    }
                    if (turnDir != right)
                    {
                        std::cout << "2: Rechtskurvefahren" << std::endl;
                    }
                    std::cout << "3: Weiter beschleunigen" << std::endl;
                    std::cout << "4: Vollbremsung" << std::endl;

                    int eingabe = 0;

                    try
                    {
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin >> eingabe;
                        (eingabe < 0 || eingabe > 4 || eingabe == turnDir) ? (throw std::exception()) : eingabe;
                    } catch (...)
                    {
                        std::cout << "Ihre Eingabe ist ungueltig. Bitte versuchen Sie es erneut." << std::endl;
                        continue;
                    }

                    if (eingabe == 0)
                    {
                        carFrame_->setTurnDirection(straight);
                        std::cout << "Faehrt geradeaus" << std::endl;
                        continue;
                    } else if (eingabe == 1)
                    {
                        carFrame_->setTurnDirection(left);
                        std::cout << "Faehrt Linkskurve" << std::endl;
                        continue;
                    } else if (eingabe == 2)
                    {
                        carFrame_->setTurnDirection(right);
                        std::cout << "Faehrt Rechtskurve" << std::endl;
                        continue;
                    } else if (eingabe == 4)
                    {
                        long double brakeDistance = carFrame_->brake();
                        std::cout << "Es wird mit " << brakeDistance << " m Bremsweg gestoppt." << std::endl;
                        std::cout << "Dabei wurden " << carFrame_->getBrainDamagePercent(brakeDistance) << "% an Brain Damage erlitten." << std::endl;
                        carFrame_->setMovementState(resting);
                        continue;
                    }

                    std::cout << "Wie lang soll beschleunigt werden? (in ganzen sek)" << std::endl;
                    try
                    {
                        eingabe = 0;
                        std::cin >> eingabe;
                        (eingabe < 0) ? (throw std::exception()) : eingabe;
                    } catch (...)
                    {
                        std::cout << "Ihre Eingabe ist ungueltig. Beschleunigung abgebrochen." << std::endl;
                        continue;
                    }
                    std::cout << "Das Auto wird jetzt beschleunigt." << std::endl;
                    std::cout << "Es wird mit " << carFrame_->accelerate(eingabe) << " m/s^2 beschleunigt."
                              << std::endl;
                    std::cout << "Die Geschwindigkeit betraegt jetzt: " << carFrame_->getSpeed() << " m/s" << std::endl;
                }

            } while (true);
        } while(true);
    }
}
