#pragma once
#include <string>

struct ClientInfo
{
    std::string clientId;
    std::string clientSecret;
    std::string redirectUri;
};

class AccesslinkData
{
public:
    AccesslinkData(std::string fileName);
    ClientInfo clientInfo;

private:
    ClientInfo readDataFile(const std::string& fileName) const;
    std::string getValue(const std::string& json, const std::string& key) const;
};
