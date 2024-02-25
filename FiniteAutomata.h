//
// Created by bozhidar_hristov on 25.02.24.
//

#ifndef FINITE_AUTOMATA_FINITEAUTOMATA_H
#define FINITE_AUTOMATA_FINITEAUTOMATA_H

#include <expected>
#include <string>
#include <utility>

using namespace std;

class FiniteAutomata {
protected:
    struct NotRecognized {
        explicit NotRecognized(string reason) : reason(std::move(reason)) {

        }

        string reason;
    };

    struct Recognized {

    };
public:
    virtual expected<Recognized, NotRecognized> recognizes(const string &word) = 0;
};


#endif //FINITE_AUTOMATA_FINITEAUTOMATA_H
