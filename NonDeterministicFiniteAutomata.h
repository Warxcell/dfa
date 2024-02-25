//
// Created by bozhidar_hristov on 25.02.24.
//

#ifndef FINITE_AUTOMATA_NONDETERMINISTICFINITEAUTOMATA_H
#define FINITE_AUTOMATA_NONDETERMINISTICFINITEAUTOMATA_H

#include "FiniteAutomata.h"
#include "NonDeterministicFiniteAutomataState.h"
#include "DeterministicFiniteAutomata.h"

class NonDeterministicFiniteAutomata : public FiniteAutomata {
private:
    DeterministicFiniteAutomata deterministicFiniteAutomata;
public:
    NonDeterministicFiniteAutomata(
            vector<NonDeterministicFiniteAutomataState *> statesNdka,
            vector<char> symbols
    );

    expected<Recognized, NotRecognized> recognizes(const string &word) override;
};


#endif //FINITE_AUTOMATA_NONDETERMINISTICFINITEAUTOMATA_H
