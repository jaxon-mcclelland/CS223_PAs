#include <string>
class Player {
    public:
        Player(std::string name);
        ~Player();
        std::string getName() const;
        int getScore() const;
        void changeScore(int new_score);
    private:
        std::string name;
        int score;
};