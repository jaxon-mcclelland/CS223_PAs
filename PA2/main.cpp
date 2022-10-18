#include "src/AVL_Tree.h"
#include <algorithm>
#include <random>
#include <chrono>


AVL_Tree<int>* insert_vector_into_tree(std::vector<int>& nums) {
    AVL_Tree<int>* tree = new AVL_Tree<int>;
    for(int i = 0; i < nums.size(); ++i) {
        tree->insert(nums[i]);
    }
    return tree;
}

void run_bonus_test(AVL_Tree<int>* tree) {
    for(int i = 1; i < 101; ++i) {
        bool result = tree->contains(i);
        if(i % 2 == 0 && result || i % 2 != 0 && !result) {
            std::cout << i << " was " << (result != true ? "not " : " ") << "in the tree\n";
            std::cout << "My AVL Tree Implementation is wrong\n";
            return;
        }
    }
    std::cout << "Contains test passed\n";
}

void run_unit_tests(AVL_Tree<int>* tree) {
    std::string validate_result = tree->validate() == true ? "true" : "false";
    std::cout << "Validate Result: " << validate_result << "\n";

    std::cout << "Height of Tree: " << tree->height() << "\n";

    run_bonus_test(tree);
}

int main(void) {
    
    std::vector<int> odd_nums;
    for(int i = 0; i <= 100; ++i) {
        if(i % 2 != 0) {
            odd_nums.push_back(i);
        }
    }
    std::vector<int> shuffled_nums = odd_nums;
    std::shuffle(shuffled_nums.begin(), shuffled_nums.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));

    std::vector<int> ascending_nums = odd_nums;
    std::sort(ascending_nums.begin(), ascending_nums.end());

    std::vector<int> descending_nums = odd_nums;
    std::sort(descending_nums.begin(), descending_nums.end(), [](int a, int b){return a > b;});

    auto shuffle_tree = insert_vector_into_tree(shuffled_nums);
    auto ascending_tree = insert_vector_into_tree(ascending_nums);
    auto descending_tree = insert_vector_into_tree(descending_nums);

    std::cout << "\n*** SHUFFLE TREE UNIT TESTS ****\n\n";
    run_unit_tests(shuffle_tree);

    std::cout << "\n*** ASCENDING TREE UNIT TESTS ****\n\n";
    run_unit_tests(ascending_tree);

    std::cout << "\n*** DESCENDING TREE UNIT TESTS ****\n\n";
    run_unit_tests(descending_tree);
 
    return 0;
}