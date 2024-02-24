#ifndef FINITE_AUTOMATA_DETERMINEDFINITEAUTOMATASTATE_H
#define FINITE_AUTOMATA_DETERMINEDFINITEAUTOMATASTATE_H

#include <map>
#include <string>

class DeterminedFiniteAutomataState {
private:
    std::string name;
    bool final;
    std::map<char, DeterminedFiniteAutomataState *> map;
public:
    explicit DeterminedFiniteAutomataState(std::string name, bool final = false);

    void addMap(char c, DeterminedFiniteAutomataState *state);

    bool has(char c);

    DeterminedFiniteAutomataState *get(char c);

    bool isFinal() const;

    const std::string getName() const;
};


#endif //FINITE_AUTOMATA_DETERMINEDFINITEAUTOMATASTATE_H
