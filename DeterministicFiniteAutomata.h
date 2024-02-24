#ifndef FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATA_H
#define FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATA_H


#include "DeterministicFiniteAutomataState.h"
#include <string>

class DeterministicFiniteAutomata {
private:
    DeterministicFiniteAutomataState *initialState;
public:
    explicit DeterministicFiniteAutomata(DeterministicFiniteAutomataState *initialState);

    bool recognizes(const std::string &word);
};


#endif //FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATA_H
