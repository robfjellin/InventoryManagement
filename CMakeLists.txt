cmake_minimum_required(VERSION 3.29)
project(InventoryManagement)

set(CMAKE_CXX_STANDARD 20)

add_executable(InventoryManagement main.cpp
        Item.cpp
        Item.h
        Inventory.cpp
        Inventory.h
        UserInterface.cpp
        UserInterface.h)
