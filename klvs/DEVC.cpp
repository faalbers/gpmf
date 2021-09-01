#include "DEVC.hpp"
#include <iostream>

GPMF::DEVC::DEVC(std::string filePath, uint64_t filePos, std::string pathParent)
    : klv(filePath, filePos, pathParent)
{
}

std::vector<GPMF::STRM *> GPMF::DEVC::getStreams()
{
    return getTypeKlvs<STRM>();
}

void GPMF::DEVC::printData(bool fullLists)
{
    int levelCount = std::count(path_.begin(), path_.end(), '/');
    std::cout << path_ << " (<datatype> <datasize> <repeat>) : main container" << std::endl;
}

void GPMF::DEVC::printHierarchyData(bool fullLists)
{
    printData(fullLists);
    for ( auto child : children_ ) child->printHierarchyData(fullLists);
}

std::string GPMF::DEVC::key = "DEVC";

