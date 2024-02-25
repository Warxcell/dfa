#include "DeterministicFiniteAutomataState.h"

#include <utility>

DeterministicFiniteAutomataState::DeterministicFiniteAutomataState(std::string name, bool final) : name(
        std::move(name)), final(final) {
}

void DeterministicFiniteAutomataState::addMap(char c, DeterministicFiniteAutomataState *state) {
    this->letterToStateMapping[c] = state;
}

bool DeterministicFiniteAutomataState::has(char c) {
    return this->letterToStateMapping.contains(c);
}

DeterministicFiniteAutomataState *DeterministicFiniteAutomataState::get(char c) {
    return this->letterToStateMapping[c];
}

bool DeterministicFiniteAutomataState::isFinal() const {
    return this->final;
}

std::string DeterministicFiniteAutomataState::getName() const {
    return name;
}
