#ifndef FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATA_H
#define FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATA_H


#include "DeterministicFiniteAutomataState.h"
#include <string>
#include "FiniteAutomata.h"

class DeterministicFiniteAutomata : public FiniteAutomata {
private:
    DeterministicFiniteAutomataState *initialState;
public:
    explicit DeterministicFiniteAutomata(DeterministicFiniteAutomataState *initialState);

    expected<Recognized, NotRecognized> recognizes(const string &word) override;
};


#endif //FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATA_H
