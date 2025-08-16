#include "AccesslinkData.hpp"

#include <iostream>

int main(){
    const auto accesslinkData = AccesslinkData("accesslink_information.json");
    std::cout << accesslinkData.clientInfo.clientId << std::endl;
    std::cout << accesslinkData.clientInfo.clientSecret << std::endl;
    std::cout << accesslinkData.clientInfo.redirectUri << std::endl;
    return 0;
}
