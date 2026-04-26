#ifndef COMMIT_H
#define COMMIT_H

#include <string>
#include <iostream>

class Commit {
public:
    int id;
    std::string message;
    std::string timestamp;
    
    Commit(int id, const std::string& msg);
    void print() const;
};

#endif
