#include "DeterminedFiniteAutomata.h"
#include <iostream>

DeterminedFiniteAutomata::DeterminedFiniteAutomata(DeterminedFiniteAutomataState *initialState) : initialState(initialState) {}

bool DeterminedFiniteAutomata::recognizes(const std::string &word) {
    auto state = this->initialState;

    for (int i = 0; i < word.size(); i++) {
        char letter = word[i];
        if (!state->has(letter)) {
            std::cout << "Не разпознава, защото буквата " << letter << " на позиция " << i << " няма преход от "
                      << state->getName() << std::endl;

            return false;
        }

        std::cout << "Буква " << letter << " на позиция " << i << " води от състояние " << state->getName() << " към ";

        state = state->get(letter);

        std::cout << state->getName() << std::endl;
    }

    if (!state->isFinal()) {
        std::cout << "Не разпознава, защото последното състояние " << state->getName() << " не е заключително"
                  << std::endl;
    } else {
        std::cout << "разпознава" << std::endl;
    }

    return state->isFinal();
}