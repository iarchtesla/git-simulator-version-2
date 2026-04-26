#include "GitSimulator.h"
#include <iostream>
#include <algorithm>

GitSimulator::GitSimulator() : nextId(1) {
  
    for (auto& c : recent) c = Commit(-1, "");
}

void GitSimulator::updateRecentArray() {
   
    if (commits.empty()) return;
    
    std::list<Commit>::reverse_iterator rit = commits.rbegin();
    for (size_t i = 0; i < RECENT_SIZE && rit != commits.rend(); ++i, ++rit) {
        recent[i] = *rit;
    }
    
    for (size_t i = commits.size(); i < RECENT_SIZE; ++i) {
        recent[i] = Commit(-1, "");
    }
}


void GitSimulator::addCommit(const std::string& msg) {
    commits.push_back(Commit(nextId++, msg));
    updateRecentArray();
    std::cout << "Commit added successfully.\n";
}


void GitSimulator::showAllCommits() const {
    if (commits.empty()) {
        std::cout << "No commits yet.\n";
        return;
    }
    std::cout << "\n=== All Commits (oldest -> newest) ===\n";
    for (const auto& c : commits) {
        c.print();
    }
}


bool GitSimulator::searchCommit(const std::string& keyword) const {
    bool found = false;
    for (const auto& c : commits) {
        if (c.message.find(keyword) != std::string::npos) {
            c.print();
            found = true;
        }
    }
    if (!found) std::cout << "No matching commits.\n";
    return found;
}


bool GitSimulator::deleteLastCommit() {
    if (commits.empty()) {
        std::cout << "No commits to delete.\n";
        return false;
    }
    commits.pop_back();
    updateRecentArray();
    std::cout << "Last commit deleted.\n";
    return true;
}

/
bool GitSimulator::modifyLastCommit(const std::string& newMsg) {
    if (commits.empty()) {
        std::cout << "No commits to modify.\n";
        return false;
    }
    commits.back().message = newMsg;
    updateRecentArray();
    std::cout << "Last commit message updated.\n";
    return true;
}

void GitSimulator::stash() {
    if (commits.empty()) {
        std::cout << "No commits to stash.\n";
        return;
    }
    stashStack.push(commits.back());
    std::cout << "Last commit saved to stash stack.\n";
}


void GitSimulator::stashPop() {
    if (stashStack.empty()) {
        std::cout << "Stash is empty.\n";
        return;
    }
    Commit stashed = stashStack.top();
    stashStack.pop();
    addCommit(stashed.message + " (restored from stash)");
    std::cout << "Stash restored and added as new commit.\n";
}


void GitSimulator::showRecentCommits() const {
    std::cout << "\n=== Last " << RECENT_SIZE << " commits (via Array) ===\n";
    bool any = false;
    for (const auto& c : recent) {
        if (c.id != -1) {
            c.print();
            any = true;
        }
    }
    if (!any) std::cout << "No commits.\n";
}


void GitSimulator::addDelayedCommit(const std::string& msg) {
    pendingQueue.push(Commit(-1, msg)); // id مؤقت
    std::cout << "Delayed commit added to queue.\n";
}

void GitSimulator::processDelayedCommit() {
    if (pendingQueue.empty()) {
        std::cout << "No delayed commits.\n";
        return;
    }
    Commit delayed = pendingQueue.front();
    pendingQueue.pop();
    addCommit(delayed.message);
    std::cout << "Processed delayed commit from queue.\n";
}

void GitSimulator::explainDS() const {
    std::cout << "\n=== Data Structures Used ===\n";
    std::cout << "1. Linked List (std::list): Stores all commits in order.\n";
    std::cout << "2. Stack (std::stack): Implements stash (LIFO).\n";
    std::cout << "3. Queue (std::queue): Holds delayed commits (FIFO).\n";
    std::cout << "4. Array (std::array): Stores last 3 commits for quick access.\n";
}
