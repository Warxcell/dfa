#include <iostream>
#include <string>
#include <map>
#include <limits>

using namespace std;

#include "DeterminedFiniteAutomataState.h"
#include "DeterminedFiniteAutomata.h"


int main() {
    auto
            *q0 = new DeterminedFiniteAutomataState("q0", false),
            *q1 = new DeterminedFiniteAutomataState("q1", false),
            *q2 = new DeterminedFiniteAutomataState("q2", false),
            *q3 = new DeterminedFiniteAutomataState("q3", false),
            *q4 = new DeterminedFiniteAutomataState("q4", false),
            *q5 = new DeterminedFiniteAutomataState("q5", false),
            *q6 = new DeterminedFiniteAutomataState("q6", true);

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


    auto automata = DeterminedFiniteAutomata(q0);

    string word;
    do {
        cout << "Въведи дума: (exit за изход): ";
        cin >> word;

        if (word == "exit") {
            return 0;
        }

        automata.recognizes(word);
    } while (true);
}
