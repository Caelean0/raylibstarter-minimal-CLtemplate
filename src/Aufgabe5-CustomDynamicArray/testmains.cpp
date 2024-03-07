//
// Created by keanu on 28.02.2024.
//

#include "testmains.h"


int DynamicArrayMain()
{
    game::memory::CustomVector<float> vectorInitlist = {1.5f, 2.3f, 3.2f};
    std::cout << "Vector Initlist: ";
    vectorInitlist.consoleOut();
    std::cout << std::endl;

    game::memory::CustomVector<int> vectorSize(10);
    for (int i = 0; i < 10; ++i)
    {
        vectorSize.add(i);
        std::cout << "Vector Size: ";
        vectorSize.consoleOut();
        std::cout << std::endl;
    }

    game::memory::CustomVector<char> vectorChar = {'a', 'b', 'c', 'd', 'e', 'd', 'f'};
    std::cout << "Vector Char: ";
    vectorChar.consoleOut();
    std::cout << std::endl;

    game::memory::CustomVector<std::string> vectorString = {"hello", "world", "!"};
    std::cout << "Vector String: ";
    vectorString.consoleOut();
    std::cout << std::endl;

    vectorInitlist.add(27.2f);
    std::cout << "Vector Initlist: ";
    vectorInitlist.consoleOut();
    std::cout << std::endl;

    for (auto &elem: vectorInitlist)
    {
        elem *= 2;
        std::cout << "Vector Initlist: ";
        vectorInitlist.consoleOut();
        std::cout << std::endl;
    };

    /*for (int i = 0; i < 10; ++i) {
    vectorInitlist[i] *= 2;
    std::cout << "Vector Initlist: ";
    vectorInitlist.consoleOut();
    std::cout << std::endl;
    }*/

    vectorSize[2] = 100;
    std::cout << "Vector Size: ";
    vectorSize.consoleOut();
    std::cout << std::endl;

    vectorSize.remove(4);
    std::cout << "Vector Size: ";
    vectorSize.consoleOut();
    std::cout << std::endl;

    std::cout << "Vector Size Alloc: " << vectorSize.getAllocatedSize() << std::endl;
    std::cout << "Vector Size Written: " << vectorSize.getWrittenSize() << std::endl;

    try
    {
        std::cout << vectorSize[10] << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }

    try
    {
        vectorSize[-1] = 0;
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Vector Init Max: " << vectorInitlist.getMax() << std::endl;
    } catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Vector Init Min: " << vectorInitlist.getMin() << std::endl;
    } catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Vector Init Max Start: " << vectorInitlist.getMax(1, 3) << std::endl;
    } catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Vector Init Min Start: " << vectorInitlist.getMin(1, 3) << std::endl;
    } catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Vector Size Max: " << vectorSize.getMax() << std::endl;
    } catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Vector Char Max: " << vectorChar.getMax() << std::endl;
    } catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Vector String Max: " << vectorString.getMax() << std::endl;
    } catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }

    game::memory::CustomVector<int> charIndices = vectorChar.getValueIndices('d');
    std::cout << "Vector Char Indices: ";
    charIndices.consoleOut();
    std::cout << std::endl;

    try
    {
        game::memory::CustomVector<int> charIndicesRange = vectorChar.getValueIndices('d', 4, 7);
        std::cout << "Vector Char Indices: ";
        charIndicesRange.consoleOut();
        std::cout << std::endl;

    } catch (std::logic_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        game::memory::CustomVector<int> charIndicesRange = vectorChar.getValueIndices('d', 4, 6);
        std::cout << "Vector Char Indices: ";
        charIndicesRange.consoleOut();
        std::cout << std::endl;

    } catch (std::logic_error &e)
    {
        std::cout << e.what() << std::endl;
    }





    return 0;

}