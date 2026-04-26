#ifndef GITSIMULATOR_H
#define GITSIMULATOR_H

#include <list>      // linked list
#include <stack>     // stack for stash
#include <array>     // array for recent commits
#include <string>
#include "Commit.h"

class GitSimulator {
private:
    // Linked list of all commits
    std::list<Commit> commits;
    
    // Stack for stash
    std::stack<Commit> stashStack;
    
    // Array for last 3 commits
    static const size_t RECENT_SIZE = 3;
    std::array<Commit, RECENT_SIZE> recent;
    int nextId;
    
    void updateRecentArray();
    
public:
    GitSimulator();
    
    // Basic operations (1-8)
    void addCommit(const std::string& msg);          // اضافه
    void showAllCommits() const;                     // عرض كل اللي متخزن
    bool searchCommit(const std::string& keyword) const; // بحث
    bool deleteLastCommit();                         // حذف
    bool modifyLastCommit(const std::string& newMsg); // تعديل
    
    // Stack operation (stash)
    void stash();                                    // حفظ في الـ stack
    void stashPop();                                 // استرجاع من الـ stack
    
    // Array operation
    void showRecentCommits() const;
    
    // شرح الـ DS
    void explainDS() const;
};

#endif
