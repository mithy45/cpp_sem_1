#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Not enough argument.\n";
        return 1;
    }

    std::ifstream file_stream;
    file_stream.open(argv[1]);

    if (!file_stream.is_open())
    {
        std::cout << "The file " << argv[1] << " could not be opened.\n";
        return 1;
    }

    std::string motive = argv[2], word;
    int counter = 0;
    while (file_stream >> word)
    {
        // if (word.find(motive) != std::string::npos)
        if (strstr(word.c_str(), motive.c_str()))
            counter++;
    }

    std::cout << "The file " << argv[1] << " contains " << counter << " words containing the motive " << motive << "\n";
    return 0;
}