cmake_minimum_required(VERSION 3.17)
project(automate)

set(CMAKE_CXX_STANDARD 20)

add_executable(automate src/Engine.cpp headers/Engine.hpp src/Field.cpp headers/Field.h src/Settings.cpp headers/Settings.h src/genetic/Bot.cpp headers/genetic/Bot.h src/genetic/GACore.cpp headers/genetic/GACore.h src/ui/SettingsWindow.cpp headers/ui/SettingsWindow.h src/ui/Button.cpp headers/ui/Button.h headers/Values.h src/ui/MainWindow.cpp headers/ui/MainWindow.h)
#add_executable(automate src/hw.cpp)

include_directories(headers /usr/include D:\\\\Libraries\\SFML-2.5.1\\include)
set(CMAKE_EXE_LINKER_FLAGS -static)
#
set(SFML_ROOT D:\\\\Libraries\\SFML-2.5.1\\)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(automate ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${CMAKE_EXE_LINKER_FLAGS})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
##set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
#target_link_libraries(automate ${CMAKE_EXE_LINKER_FLAGS})