#ifndef FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATASTATE_H
#define FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATASTATE_H

#include <map>
#include <string>

class DeterministicFiniteAutomataState {
private:
    std::string name;
    bool final;
    std::map<char, DeterministicFiniteAutomataState *> map;
public:
    explicit DeterministicFiniteAutomataState(std::string name, bool final = false);

    void addMap(char c, DeterministicFiniteAutomataState *state);

    bool has(char c);

    DeterministicFiniteAutomataState *get(char c);

    bool isFinal() const;

    const std::string getName() const;
};


#endif //FINITE_AUTOMATA_DETERMINISTICFINITEAUTOMATASTATE_H
