#include <map>
#include "TwitterData.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower", "Smit", "Rick", "smitRick@gmail.com", "1117", "power lifting"},
                             {"kittyKat72", "Smith", "Kathryn", "kat@gmail.com", "56", "health"},
                             {"lexi5", "Anderson", "Alexis", "lexi5@gmail.com", "900", "education"},
                             {"savage1", "Savage", "Ken", "ksavage@gmail.com", "17", "president"},
                             {"smithMan", "Smith", "Rick", "rick@hotmail.com", "77", "olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i)
    {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    //
    // Your code goes here
    //
    std::map<std::string, TwitterData> name_map;
    
    for(int i = 0; i < 5; ++i) {
        name_map.insert(make_pair(twitter_data[i].getUserName(), twitter_data[i]));
    }
    std::cout << "Printing userName map: \n";
    for(auto i : name_map) {
        std::cout << "Key: " << i.first << " Value: " << i.second.getActualName() << "," << i.second.getEmail() << "," << i.second.getNumTweets() << "," << i.second.getCategory() << "\n";
    }
    std::cout << "Search for Key: savage1 Value: ";
    auto search_data = name_map.find("savage1");
    if(search_data != name_map.end()) {
        std::cout << search_data->second.getActualName() << "," << search_data->second.getEmail() << "," << search_data->second.getNumTweets() << "," << search_data->second.getCategory() << "\n";
        name_map.erase("savage1");
    } else {
        std::cout << "Key not found!\n";
    }

    
    std::map<std::string, TwitterData> email_map;
    
    for(int i = 0; i < 5; ++i) {
        email_map.insert(make_pair(twitter_data[i].getEmail(), twitter_data[i]));
    }
    std::cout << "Printing email map: \n";
    for(auto i : email_map) {
        std::cout << "Key: " << i.first << " Value: " << i.second.getActualName() << "," << i.second.getUserName() << "," << i.second.getNumTweets() << "," << i.second.getCategory() << "\n";
    }
    std::cout << "Search for Key: kat@gmail.com Value: ";
    auto search_data2 = email_map.find("kat@gmail.com");
    if(search_data2 != email_map.end()) {
        std::cout << search_data2->second.getActualName() << "," << search_data2->second.getUserName() << "," << search_data2->second.getNumTweets() << "," << search_data2->second.getCategory() << "\n";
        email_map.erase("kat@gmail.com");
    } else {
        std::cout << "Key not found!\n";
    }


    return 0;
}