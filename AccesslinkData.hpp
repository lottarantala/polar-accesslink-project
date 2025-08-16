#pragma once
#include <string>

struct AccesslinkInfo
{
    std::string clientId;
    std::string clientSecret;
    std::string redirectUri;
};

class AccesslinkData
{
public:
    AccesslinkData(std::string fileName);
    AccesslinkInfo fileData;

private:

    AccesslinkInfo readDataFile(const std::string& fileName) const;
    std::string getValue(const std::string& json, const std::string& key) const;
};
