#include "DVNM.hpp"
#include "../klvs.hpp"
#include <fstream>
#include <iostream>

GPMF::DVNM::DVNM(std::string &dataString, std::string pathParent)
    : klv(dataString, pathParent)
{
    // throw an error if at one point they decide to change the data type
    if ( dataType != 'c' )
        error_("DVNM klv wrong data type: "+std::string((char *)&dataType).substr(0,1));

    name = dataString.substr(0, sampleSize * dataRepeat);
}

void GPMF::DVNM::printData(bool fullLists)
{
    auto levelCount = std::count(path_.begin(), path_.end(), '/');
    std::string dataIndent = std::string((levelCount)*5+1, ' ');
    std::cout << path_ << " ('" << dataType << "' " << sampleSize << " " << dataRepeat << ") : device name" << std::endl;
    std::cout << dataIndent << getZeroTerminatedString(name) << std::endl;
}

void GPMF::DVNM::printHierarchyData(bool fullLists)
{
    printData(fullLists);
    for ( auto child : children_ ) child->printHierarchyData(fullLists);
}

std::string GPMF::DVNM::key = "DVNM";

