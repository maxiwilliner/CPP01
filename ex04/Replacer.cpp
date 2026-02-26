#include "Replacer.hpp"
#include <iostream>
#include <fstream>

Replacer::Replacer(std::string filename, std::string s1, std::string s2)
    : _filename(filename), _s1(s1), _s2(s2)
{
}

Replacer::~Replacer()
{
}

bool Replacer::replace() const
{
    if (this->_filename.empty() || this->_s1.empty())
    {
        std::cerr << "Error: Filename and s1 cannot be empty." << std::endl;
        return false;
    }

    std::ifstream inFile(this->_filename.c_str());
    if (!inFile.is_open())
    {
        std::cerr << "Error: Could not open the file " << this->_filename << " for reading." << std::endl;
        return false;
    }

    std::string outFilename = this->_filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not open the file " << outFilename << " for writing." << std::endl;
        inFile.close();
        return false;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        size_t pos = 0;
        size_t foundPos;
        
        while ((foundPos = line.find(this->_s1, pos)) != std::string::npos)
        {
            outFile << line.substr(pos, foundPos - pos);
            outFile << this->_s2;
            pos = foundPos + this->_s1.length();
        }
        outFile << line.substr(pos);
        
        if (!inFile.eof())
            outFile << std::endl;
    }

    inFile.close();
    outFile.close();

    return true;
}
