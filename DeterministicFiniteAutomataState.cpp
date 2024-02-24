#include "DeterministicFiniteAutomataState.h"

DeterministicFiniteAutomataState::DeterministicFiniteAutomataState(std::string name, bool final) : name(name), final(final) {
}

void DeterministicFiniteAutomataState::addMap(char c, DeterministicFiniteAutomataState *state) {
    this->map[c] = state;
}

bool DeterministicFiniteAutomataState::has(char c) {
    return this->map.contains(c);
}

DeterministicFiniteAutomataState *DeterministicFiniteAutomataState::get(char c) {
    return this->map[c];
}

bool DeterministicFiniteAutomataState::isFinal() const {
    return this->final;
}

const std::string DeterministicFiniteAutomataState::getName() const {
    return name;
}
