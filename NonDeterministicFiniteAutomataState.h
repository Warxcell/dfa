//
// Created by bozhidar_hristov on 25.02.24.
//

#ifndef FINITE_AUTOMATA_NONDETERMINISTICFINITEAUTOMATASTATE_H
#define FINITE_AUTOMATA_NONDETERMINISTICFINITEAUTOMATASTATE_H

#include <map>
#include <vector>

using namespace std;

class NonDeterministicFiniteAutomataState {
private:
    bool final{};
    map<char, vector<NonDeterministicFiniteAutomataState * >> letterToStateMapping;
public:
    explicit NonDeterministicFiniteAutomataState(bool final);

    void addMap(char c, NonDeterministicFiniteAutomataState *state);

    bool has(char c);

    vector<NonDeterministicFiniteAutomataState *> get(char c);

    bool isFinal() const;
};


#endif //FINITE_AUTOMATA_NONDETERMINISTICFINITEAUTOMATASTATE_H
