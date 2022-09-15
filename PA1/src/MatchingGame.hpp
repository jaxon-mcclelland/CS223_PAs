#include "LinkedList.hpp"
#include "Player.hpp"
#include "Question.hpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>


class MatchingGame {
    public:
        MatchingGame();
        ~MatchingGame();
        void startGame();
        void displayMenu() const;
        void displayRules() const;
        void displayQuestion(Question& input) const;
        void loadCommands();
        void loadPlayers();
        void addCommand();
        void removeCommand();
        void copyPlayerArr();
        void writeDataToFiles();
        void loadPreviousGame();
        void generateQuestionList();
    private:
        std::fstream command_file;
        std::fstream player_file;
        LinkedList<std::string, std::string>* command_List;        
        int num_players;
        int current_player_arr_size;
        std::vector<Player*> player_arr;
        //Player* player_arr;
        int currPlayerIdx;
        std::string currentPlayerName;
        int currentPlayerScore;
        int num_questions;
        std::set<Question> question_list;
        

};