//
// Created by bozhidar_hristov on 25.02.24.
//

#include "NonDeterministicFiniteAutomataState.h"

NonDeterministicFiniteAutomataState::NonDeterministicFiniteAutomataState(bool final) : final(final) {

}

void NonDeterministicFiniteAutomataState::addMap(char c, NonDeterministicFiniteAutomataState *state) {
    this->letterToStateMapping[c].push_back(state);
}

bool NonDeterministicFiniteAutomataState::has(char c) {
    return this->letterToStateMapping.contains(c);
}

vector<NonDeterministicFiniteAutomataState *> NonDeterministicFiniteAutomataState::get(char c) {
    return this->letterToStateMapping[c];
}

bool NonDeterministicFiniteAutomataState::isFinal() const {
    return this->final;
}

