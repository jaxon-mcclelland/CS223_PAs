#include "Node.hpp"

Node::Node() {
    this->command = "";
    this->description = "";
}
Node::Node(std::string command, std::string description) {
    this->command = command;
    this->description = description;
}
Node::Node(const Node& rhs) {
    this->command = rhs.command;
    this->description = rhs.description;
    // not intended to give access to the rest of the list
    this->pNext = nullptr;
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
