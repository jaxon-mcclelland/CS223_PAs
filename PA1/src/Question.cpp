#include "Question.hpp"

bool Question::operator<(const Question& rhs) {
    return this->command < rhs.command;
}