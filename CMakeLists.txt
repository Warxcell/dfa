cmake_minimum_required(VERSION 3.26)
project(finite_automata)

set(CMAKE_CXX_STANDARD 23)

add_executable(finite_automata main.cpp
        DeterministicFiniteAutomataState.cpp
        DeterministicFiniteAutomataState.h
        DeterministicFiniteAutomata.cpp
        DeterministicFiniteAutomata.h
)
