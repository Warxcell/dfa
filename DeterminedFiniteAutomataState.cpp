#include "DeterminedFiniteAutomataState.h"

DeterminedFiniteAutomataState::DeterminedFiniteAutomataState(std::string name, bool final) : name(name), final(final) {
}

void DeterminedFiniteAutomataState::addMap(char c, DeterminedFiniteAutomataState *state) {
    this->map[c] = state;
}

bool DeterminedFiniteAutomataState::has(char c) {
    return this->map.contains(c);
}

DeterminedFiniteAutomataState *DeterminedFiniteAutomataState::get(char c) {
    return this->map[c];
}

bool DeterminedFiniteAutomataState::isFinal() const {
    return this->final;
}

const std::string DeterminedFiniteAutomataState::getName() const {
    return name;
}
