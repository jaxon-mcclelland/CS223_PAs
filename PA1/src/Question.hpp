#include <string>
#include <stdlib.h>
#include "LinkedList.hpp"
class Question {
    public:
        Question(std::string command, std::string wrong_answer1, std::string wrong_answer2, std::string correct_answer);
        std::string getCommand() const;
        std::string getWrongAnswer1() const;
        std::string getWrongAnswer2() const;
        std::string getCorrectAnswer() const;
        int getCorrectNumber() const;
        void setCorrectNumber(int new_correct_number);
    private:
        std::string command;
        std::string wrong_answer1;
        std::string wrong_answer2;
        std::string correct_answer;
        int correct_number;
    
};
bool operator<(const Question& lhs, const Question& rhs);
bool operator>(const Question& lhs, const Question& rhs);
bool operator<=(const Question& lhs, const Question& rhs);
bool operator>=(const Question& lhs, const Question& rhs);
