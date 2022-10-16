//
//  main.cpp
//  gao-filesys-util
//
//  Created by Mohammad Esmaeilirad  on 2022-10-13.
//

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        std::cout << "Usage: main.cpp sourceFile targetFile"
                  << "\n";
        return 0;
    }

    fs::path sourceFile, targetParent;
    sourceFile = argv[1];
    targetParent = argv[2];

    auto target = targetParent / sourceFile.filename();

    try
    {
        fs::create_directories(targetParent); // Recursively create target directory if not existing.
        fs::copy_file(sourceFile, target, fs::copy_options::overwrite_existing);
    }
    catch (std::exception &e) // Not using fs::filesystem_error since std::bad_alloc can be thrown too.
    {

        std::cout << "error: " << e.what();
    }

    return 0;
}
