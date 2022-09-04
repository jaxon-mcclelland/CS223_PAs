#include "Node.hpp"

Node::Node() {
    this->command = "";
    this->description = "";
}
Node::Node(std::string command, std::string description) {
    this->command = command;
    this->description = description;
}
Node::~Node() {}
void Node::setCommand(std::string new_command) {
    this->command = new_command;
}
void Node::setDescription(std::string new_desc) {
    this->description = new_desc;
}
std::string Node::getCommand() const {
    return this->command;
}
std::string Node::getDescription() const {
    return this->description;
}

std::istream &operator>>(std::istream& lhs, Node* rhs) {
    char command[100];
    char answer[100];
    lhs.getline(command, 100, ',');
    lhs.getline(answer, 100, '\n');
    
    rhs->setCommand(command);
    rhs->setDescription(answer);
    
    return lhs;

}
std::ostream &operator<<(std::ostream& lhs, Node* rhs) {
    return lhs;
}