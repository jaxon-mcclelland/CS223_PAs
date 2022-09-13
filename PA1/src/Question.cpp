#include "Question.hpp"

Question::Question(std::string command, std::string wrong_answer1, std::string wrong_answer2, std::string correct_answer) {
    this->command = command;
    this->wrong_answer1 = wrong_answer1;
    this->wrong_answer2 = wrong_answer2;
    this->correct_answer = correct_answer;
    this->correct_number = -1;
}

std::string Question::getCommand() const {
    return command;
}

std::string Question::getWrongAnswer1() const {
    return wrong_answer1;
}
std::string Question::getWrongAnswer2() const {
    return wrong_answer2;
}
std::string Question::getCorrectAnswer() const {
    return correct_answer;
}
int Question::getCorrectNumber() const {
    return correct_number;
}
void Question::setCorrectNumber(int new_correct_number) {
    this->correct_number = new_correct_number;
}

bool operator<(const Question& lhs, const Question& rhs) {
    return lhs.getCommand() < rhs.getCommand();
}
bool operator>(const Question& lhs, const Question& rhs) {
    return lhs.getCommand() > rhs.getCommand();
}
bool operator<=(const Question& lhs, const Question& rhs) {
    return lhs.getCommand() <= rhs.getCommand();
}
bool operator>=(const Question& lhs, const Question& rhs) {
    return lhs.getCommand() >= rhs.getCommand();
}
