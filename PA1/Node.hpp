#include <iostream>
#include <string>

class Node {
    friend class LinkedList;
    public:
        Node();
        Node(std::string command, std::string description);
        ~Node();
        void setCommand(std::string new_command);
        void setDescription(std::string new_desc);
        std::string getCommand() const;
        std::string getDescription() const;
    private:
        std::string command;
        std::string description;
        Node* pNext;
};
std::istream &operator>>(std::istream& lhs, Node* rhs);
std::ostream &operator<<(std::ostream& lhs, Node* rhs);