#include <iostream>
#include <string>
#include <map>
#include <limits>

using namespace std;

#include "DeterministicFiniteAutomataState.h"
#include "DeterministicFiniteAutomata.h"

int main() {
    auto
            *q0 = new DeterministicFiniteAutomataState("q0", false),
            *q1 = new DeterministicFiniteAutomataState("q1", false),
            *q2 = new DeterministicFiniteAutomataState("q2", false),
            *q3 = new DeterministicFiniteAutomataState("q3", false),
            *q4 = new DeterministicFiniteAutomataState("q4", false),
            *q5 = new DeterministicFiniteAutomataState("q5", false),
            *q6 = new DeterministicFiniteAutomataState("q6", true);

    q0->addMap('1', q1);
    q1->addMap('0', q2);
    q2->addMap('0', q3);
    q2->addMap('1', q3);
    q3->addMap('0', q4);
    q3->addMap('1', q4);
    q4->addMap('0', q5);
    q4->addMap('1', q5);
    q5->addMap('0', q6);
    q5->addMap('1', q3);
    q6->addMap('0', q4);
    q6->addMap('1', q4);

    auto automata = DeterministicFiniteAutomata(q0);

    string word;
    do {
        cout << "Въведи дума: (exit за изход): ";
        cin >> word;

        if (word == "exit") {
            return 0;
        }

        const auto result = automata.recognizes(word);

        if (result.has_value()) {
            cout << "Разпознава" << endl;
        } else {
            cout << "НЕ Разпознава, причина: " << result.error().reason << endl;
        }
    } while (true);
}
