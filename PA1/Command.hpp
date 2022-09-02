#include <string>
#include <iostream>
class Command {
    public:
        Command();
        Command(std::string command, std::string answer);
        ~Command();
        std::string getKey() const;
        std::string getAnswer() const;
        void setKey(std::string newKey);
        void setAnswer(std::string newAnswer);
    private:
        std::string key;
        std::string answer;
};
std::istream &operator>>(std::istream& lhs, Command &rhs);
std::ostream &operator<<(std::ostream& lhs, Command &rhs);