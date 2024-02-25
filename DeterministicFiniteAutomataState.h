#ifndef FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATASTATE_H
#define FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATASTATE_H

#include <map>
#include <string>

using namespace std;

class DeterministicFiniteAutomataState {
private:
    string name;
    bool final;
    map<char, DeterministicFiniteAutomataState *> letterToStateMapping;
public:
    explicit DeterministicFiniteAutomataState(string name, bool final = false);

    void addMap(char c, DeterministicFiniteAutomataState *state);

    bool has(char c);

    DeterministicFiniteAutomataState *get(char c);

    bool isFinal() const;

    const string getName() const;
};


#endif //FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATASTATE_H
