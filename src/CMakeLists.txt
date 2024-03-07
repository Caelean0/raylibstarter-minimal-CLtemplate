cmake_minimum_required(VERSION 3.24)

include(../cmake/raylib.cmake)

project(game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cpp
        Aufgabe2-Sprite/Sprite.cpp
        Aufgabe2-Sprite/Sprite.h
        Aufgabe2-Sprite/SpriteHelp.h
        Aufgabe5-CustomDynamicArray/CustomDynamicArray.h
        Aufgabe5-CustomDynamicArray/CustomDynamicArray.hpp
        Aufgabe5-CustomDynamicArray/testmains.cpp
        Aufgabe5-CustomDynamicArray/testmains.h
        Aufgabe7-RaylibSpriteKlasse/RaylibSprite.cpp
        Aufgabe7-RaylibSpriteKlasse/RaylibSprite.h
        Aufgabe7-RaylibSpriteKlasse/AsteroidsSupport.h
        Aufgabe8-LevelKlasse/Level.cpp
        Aufgabe8-LevelKlasse/Level.h
        Aufgabe7-RaylibSpriteKlasse/PlayerSprite.cpp
        Aufgabe7-RaylibSpriteKlasse/PlayerSprite.h
        Aufgabe8-LevelKlasse/AsteroidsHandler.cpp
        Aufgabe8-LevelKlasse/AsteroidsHandler.h
        Aufgabe3-Wuerfel/DiceGame.cpp
        Aufgabe3-Wuerfel/DiceGame.h
        Aufgabe3-Wuerfel/DiceSupport.h
        Aufgabe4-Pflanzen/Plant.cpp
        Aufgabe4-Pflanzen/Plant.h
        Aufgabe4-Pflanzen/Tree.cpp
        Aufgabe4-Pflanzen/Tree.h
        Aufgabe4-Pflanzen/Flower.cpp
        Aufgabe4-Pflanzen/Flower.h
        Aufgabe4-Pflanzen/Bush.cpp
        Aufgabe4-Pflanzen/Bush.h
        Aufgabe4-Pflanzen/Grass.cpp
        Aufgabe4-Pflanzen/Grass.h
        Aufgabe4-Pflanzen/PlantSupport.h
        Aufgabe4-Pflanzen/PlantHandler.cpp
        Aufgabe4-Pflanzen/PlantHandler.h
        Aufgabe6-Auto/Bases/BaseCar.cpp
        Aufgabe6-Auto/Bases/BaseCar.h
        Aufgabe6-Auto/Bases/BaseWheels.cpp
        Aufgabe6-Auto/Bases/BaseWheels.h
        Aufgabe6-Auto/Bases/BaseGears.cpp
        Aufgabe6-Auto/Bases/BaseGears.h
        Aufgabe6-Auto/Bases/BaseEngine.cpp
        Aufgabe6-Auto/Bases/BaseEngine.h
        Aufgabe6-Auto/Bases/BaseFrame.cpp
        Aufgabe6-Auto/Bases/BaseFrame.h
        Aufgabe6-Auto/Bases/BaseSuspension.cpp
        Aufgabe6-Auto/Bases/BaseSuspension.h
        Aufgabe6-Auto/Bases/BaseBrakes.cpp
        Aufgabe6-Auto/Bases/BaseBrakes.h
        Aufgabe6-Auto/CarSupport.h
        Aufgabe6-Auto/Cars/Audi/AudiCar.cpp
        Aufgabe6-Auto/Cars/Audi/AudiCar.h
        Aufgabe6-Auto/Cars/Audi/AudiEngine.cpp
        Aufgabe6-Auto/Cars/Audi/AudiEngine.h
        Aufgabe6-Auto/Cars/Audi/AudiBrakes.cpp
        Aufgabe6-Auto/Cars/Audi/AudiBrakes.h
        Aufgabe6-Auto/Cars/Audi/AudiFrame.cpp
        Aufgabe6-Auto/Cars/Audi/AudiFrame.h
        Aufgabe6-Auto/Cars/Audi/AudiSuspension.cpp
        Aufgabe6-Auto/Cars/Audi/AudiSuspension.h
        Aufgabe6-Auto/Cars/Audi/AudiWheels.cpp
        Aufgabe6-Auto/Cars/Audi/AudiWheels.h
        Aufgabe6-Auto/Cars/Audi/AudiGears.cpp
        Aufgabe6-Auto/Cars/Audi/AudiGears.h
        Aufgabe6-Auto/Cars/Mercedes/MercedesCar.cpp
        Aufgabe6-Auto/Cars/Mercedes/MercedesCar.h
        Aufgabe6-Auto/Cars/Mercedes/MercedesEngine.cpp
        Aufgabe6-Auto/Cars/Mercedes/MercedesEngine.h
        Aufgabe6-Auto/Cars/Mercedes/MercedesBrakes.cpp
        Aufgabe6-Auto/Cars/Mercedes/MercedesBrakes.h
        Aufgabe6-Auto/Cars/Mercedes/MercedesFrame.cpp
        Aufgabe6-Auto/Cars/Mercedes/MercedesFrame.h
        Aufgabe6-Auto/Cars/Mercedes/MercedesSuspension.cpp
        Aufgabe6-Auto/Cars/Mercedes/MercedesSuspension.h
        Aufgabe6-Auto/Cars/Mercedes/MercedesWheels.cpp
        Aufgabe6-Auto/Cars/Mercedes/MercedesWheels.h
        Aufgabe6-Auto/Cars/Mercedes/MercedesGears.cpp
        Aufgabe6-Auto/Cars/Mercedes/MercedesGears.h
        Aufgabe6-Auto/CarHandler.cpp
        Aufgabe6-Auto/CarHandler.h
)

# Add config.h.in file
configure_file(config.h.in config.h)
target_include_directories(${PROJECT_NAME} PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

# Link to Raylib
# Static linking may be interesting, especially under Windows with MinGW,
# so that the MinGW DLLs do not have to be supplied.
# (Unfortunately, there is no easy way to link the C++ standard libraries
# statically and other libraries dynamically.)
if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    target_link_libraries(${PROJECT_NAME} raylib)
else()
    target_link_libraries(${PROJECT_NAME} raylib -static)
endif()

# Copy assets to assets path
add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -P "${CMAKE_CURRENT_LIST_DIR}/../cmake/copy-assets.cmake"
        )
add_dependencies(${PROJECT_NAME} copy_assets)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()

# CPack instructions
# call e.g. cpack -G ZIP -C Debug to create a binary distribution
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${PROJECT_NAME}_Bundle")
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/assets" DESTINATION "${PROJECT_NAME}_Bundle")