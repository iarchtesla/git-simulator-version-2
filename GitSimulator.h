#ifndef GITSIMULATOR_H
#define GITSIMULATOR_H

#include <list>
#include <stack>
#include <array>
#include <string>
#include "Commit.h"

class GitSimulator {
private:
    std::list<Commit> commits;
    std::stack<Commit> stashStack;
    static const size_t RECENT_SIZE = 3;
    std::array<Commit, RECENT_SIZE> recent;
    int nextId;

    void updateRecentArray();

public:
    GitSimulator();
    void addCommit(const std::string& msg);
    void showAllCommits() const;
    bool searchCommit(const std::string& keyword) const;
    bool deleteLastCommit();
    bool modifyLastCommit(const std::string& newMsg);
    void stash();
    void stashPop();
    void showRecentCommits() const;
    void explainDS() const;
};

#endif
