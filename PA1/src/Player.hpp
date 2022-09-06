#include <string>
#include <iostream>
class Player {
    public:
        Player();
        Player(std::string name);
        ~Player();
        std::string getName() const;
        int getScore() const;
        void changeName(std::string new_name);
        void changeScore(int new_score);
        Player& operator=(const Player& rhs);
    private:
        std::string name;
        int score;
};

std::ostream& operator<<(std::ostream& lhs, const Player& rhs);
std::istream& operator>>(std::istream& lhs, Player& rhs);