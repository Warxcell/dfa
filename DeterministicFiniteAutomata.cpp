#include "DeterministicFiniteAutomata.h"

DeterministicFiniteAutomata::DeterministicFiniteAutomata(DeterministicFiniteAutomataState *initialState) : initialState(
        initialState) {}

expected<DeterministicFiniteAutomata::Recognized, DeterministicFiniteAutomata::NotRecognized>
DeterministicFiniteAutomata::recognizes(const string &word) {

    auto state = this->initialState;

    for (int i = 0; i < word.size(); i++) {
        char letter = word[i];
        if (!state->has(letter)) {
            NotRecognized da = NotRecognized(
                    "буквата " + (string(1, letter)) + " на позиция " + to_string(i) +
                    " няма преход от "
                    + state->getName()
            );

            return std::unexpected(da);
        }

        state = state->get(letter);
    }


    if (state->isFinal()) {
        Recognized da = Recognized();
        return da;
    } else {
        NotRecognized da = NotRecognized(
                "последното състояние " + state->getName() + " не е заключително"
        );
        return std::unexpected(da);
    }
}