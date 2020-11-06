#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
constexpr unsigned TOTAL_TARGETS = 5;

main(int argc, char *argv[]){ 
    
    if (argc <= 1) {
        std::cout <<"Invalid input\nTo owo text type the executable's name followed by the string you want owoed enclosed in double quotes";
        return -1;
    }
    
    std::string str{ argv[1] };
    std::vector<bool> edited(str.size(), false); 

    //example inputs
    const char* const find [TOTAL_TARGETS]  {
        "r",
        "w",
        "n",  
        "ove",
        "this"
    };

    const int find_size[TOTAL_TARGETS]{
       1,
       1,
       1,
       3,
       4
    };

    const int replace_size[TOTAL_TARGETS]{
       1,
       5,
       2,
       2,
       3
    };

    const char* const replace_with[TOTAL_TARGETS]{
        "w",
        "adiin",
        "ny",
        "uv",
        "dis"
    };
    
    int last_found{ 0 };

    for (int i = 0; i < TOTAL_TARGETS; ++i) {
        do {

            std::cout << /*last_found =*/ str.find(find[i], last_found);
            last_found = str.find(find[i], last_found);

            if ((last_found == str.npos)) //if not found break or if edited break
                break;
            if (edited[last_found]) {
                ++last_found; //not unsafe,continue will bring to revaluation
                continue;
            }
            int editedOffset{ 0 };
            str.replace(last_found, find_size[i], replace_with[i]);
            if (replace_size[i] == 1 && find_size[i] == 1) {}
            else if (replace_size[i] > find_size[i]) { 
                edited.insert(edited.begin() + last_found, replace_size[i] - find_size[i], find[i]); //add the difference
            } else if (replace_size[i] < find_size[i]) {
                editedOffset = find_size[i] - replace_size[i];
                edited.erase(edited.begin() + last_found - editedOffset, edited.begin() + last_found);
            } 
            std::fill(edited.begin() + last_found - (editedOffset-1), edited.begin() + last_found + replace_size[i], true); 
            editedOffset = 0;
        } while (last_found < str.length());
        last_found = 0;
    }
    std::cout << str.c_str();

    return 0;   
}
