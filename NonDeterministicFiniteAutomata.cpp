//
// Created by bozhidar_hristov on 25.02.24.
//

#include "NonDeterministicFiniteAutomata.h"
#include <queue>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;


template<class T>
int getIndexFromVector(const vector<T> v, const T item) {
    const auto it = find(v.begin(), v.end(), item);

    if (it != v.end()) {
        return it - v.begin();
    } else {
        return -1;
    }
}


DeterministicFiniteAutomataState *convertNdfaToDfa(
        vector<NonDeterministicFiniteAutomataState *> statesNdka,
        vector<char> symbols
) {
    map<string, DeterministicFiniteAutomataState *> newStates;
    map<string, map<char, string>> newStatesMap;

    queue<string> q;
    q.emplace("0");
    for (; !q.empty(); q.pop()) {
        const auto item = q.front();
        bool newStateIsFinal = false;

        for (int c = 0; c < symbols.size(); c++) {
            string newState;

            for (int i = 0; i < item.size(); i++) {
                const auto indexInt = item[i] - '0';

                if (statesNdka[indexInt]->isFinal()) {
                    newStateIsFinal = true;
                }

                if (!statesNdka[indexInt]->has(symbols[c])) {
                    continue;
                }
                const auto states = statesNdka[indexInt]->get(symbols[c]);

                for (auto z = 0; z < states.size(); z++) {
                    const auto index = to_string(getIndexFromVector(statesNdka, states[z]))[0];

                    if (find(newState.begin(), newState.end(), index) == newState.end()) {
                        newState += index;
                    }
                }
            }

            if (newState.empty()) {
                continue;
            }

            sort(newState.begin(), newState.end());

            if (!newStates.contains(newState)) {
                q.emplace(newState);
            }

            newStatesMap[item][symbols[c]] = newState;
        }

        newStates[item] = new DeterministicFiniteAutomataState(item, newStateIsFinal);
    }

    for (const auto &[stateIndex, state]: newStates) {
        auto map = newStatesMap[stateIndex];

        for (const auto &[symbol, targetStateIndex]: map) {
            newStates[stateIndex]->addMap(symbol, newStates[targetStateIndex]);
        }
    }

    return newStates["0"];
}


NonDeterministicFiniteAutomata::NonDeterministicFiniteAutomata(
        vector<NonDeterministicFiniteAutomataState *> statesNdka,
        vector<char> symbols
) : deterministicFiniteAutomata(
        DeterministicFiniteAutomata(convertNdfaToDfa(std::move(statesNdka), std::move(symbols)))
) {

}

expected<FiniteAutomata::Recognized, FiniteAutomata::NotRecognized>
NonDeterministicFiniteAutomata::recognizes(const string &word) {
    return this->deterministicFiniteAutomata.recognizes(word);
}
