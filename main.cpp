#include "AccesslinkData.hpp"

#include <iostream>

int main(){
    const auto accesslinkData = AccesslinkData("accesslink_information.json");
    std::cout << accesslinkData.fileData.clientId << std::endl;
    std::cout << accesslinkData.fileData.clientSecret << std::endl;
    std::cout << accesslinkData.fileData.redirectUri << std::endl;
    return 0;
}
