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

