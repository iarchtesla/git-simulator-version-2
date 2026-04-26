#include "GitSimulator.h"
#include <iostream>
#include <string>
#include <limits>

void printMenu() {
    std::cout << "\n===== Git Simulator (Simple) =====\n";
    std::cout << "1. Add commit\n";
    std::cout << "2. Show all commits\n";
    std::cout << "3. Search commit by message\n";
    std::cout << "4. Delete last commit\n";
    std::cout << "5. Modify last commit\n";
    std::cout << "6. Stash (save last commit to stack)\n";
    std::cout << "7. Stash pop (restore from stack)\n";
    std::cout << "8. Show recent commits (via Array)\n";
    std::cout << "9. Explain data structures\n";
    std::cout << "0. Exit\n";
    std::cout << "Choice: ";
}

int main() {
    GitSimulator git;
    int choice;
    std::string input;

    do {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                std::cout << "Commit message: ";
                std::getline(std::cin, input);
                git.addCommit(input);
                break;
            case 2:
                git.showAllCommits();
                break;
            case 3:
                std::cout << "Search keyword: ";
                std::getline(std::cin, input);
                git.searchCommit(input);
                break;
            case 4:
                git.deleteLastCommit();
                break;
            case 5:
                std::cout << "New commit message: ";
                std::getline(std::cin, input);
                git.modifyLastCommit(input);
                break;
            case 6:
                git.stash();
                break;
            case 7:
                git.stashPop();
                break;
            case 8:
                git.showRecentCommits();
                break;
            case 9:
                git.explainDS();
                break;
            case 0:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
