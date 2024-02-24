#ifndef FINITE_AUTOMATA_DETERMINEDFINITEAUTOMATA_H
#define FINITE_AUTOMATA_DETERMINEDFINITEAUTOMATA_H


#include "DeterminedFiniteAutomataState.h"
#include <string>

class DeterminedFiniteAutomata {
private:
    DeterminedFiniteAutomataState *initialState;
public:
    explicit DeterminedFiniteAutomata(DeterminedFiniteAutomataState *initialState);

    bool recognizes(const std::string &word);
};


#endif //FINITE_AUTOMATA_DETERMINEDFINITEAUTOMATA_H
