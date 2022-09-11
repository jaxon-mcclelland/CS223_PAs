#include <string>

struct Question {
    std::string command;
    std::string wrong_answer1;
    std::string wrong_answer2;
    std::string correct_answer;
    int correct_number;
    bool operator<(const Question& rhs);
};

