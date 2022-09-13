#include <iostream>
#include <string>
#pragma once

class Node {
    template <class T, class J>
    friend class LinkedList;
    public:
        Node();
        Node(std::string command, std::string description);
        Node(const Node& rhs);
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
