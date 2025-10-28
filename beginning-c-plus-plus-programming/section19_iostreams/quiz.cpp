#include <iostream>
#include <fstream>

void read_file(std::string file_name) {   
    std::ifstream in_file {file_name};
    if (!in_file)
        std::cerr <<  "Error opening file" << std::endl;
    else {
        std::string word;
        while (in_file >> word) {
            std::cout << word << std::endl;
         }
        in_file.close();
    }

}