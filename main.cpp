//
//  main.cpp
//  gao-filesys-util
//
//  Created by Mohammad Esmaeilirad  on 2022-10-13.
//

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    
//    char s[20], d[20];
    fs::path sourceFile, targetParent;
    sourceFile = argv[argc-2];
    targetParent = argv[argc-1];
    
    auto target = targetParent / sourceFile.filename(); // sourceFile.filename() returns "sourceFile.ext".

//    std::cout << "Please enter the source directory?\n";
//    std::cin >> s;
//
//    std::cout << "Please enter the destination directory?\n";
//    std::cin >> d;
    
    
    try // If you want to avoid exception handling, then use the error code overload of the following functions.
        {
            fs::create_directories(targetParent); // Recursively create target directory if not existing.
            fs::copy_file(sourceFile, target, fs::copy_options::overwrite_existing);
        }
        catch (std::exception& e) // Not using fs::filesystem_error since std::bad_alloc can be thrown too.
        {
            
            std::cout << "error: " << e.what();
        }
  
    return 0;
}
