#include "AccesslinkData.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

AccesslinkData::AccesslinkData(std::string fileName)
{
    fileData = readDataFile(fileName);
}

AccesslinkInfo AccesslinkData::readDataFile(const std::string& fileName) const
{
    std::ifstream file(fileName);
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + fileName);

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string json = buffer.str();

    AccesslinkInfo info;
    info.clientId = getValue(json, "client_id");
    info.clientSecret = getValue(json, "client_secret");
    info.redirectUri = getValue(json, "redirect_uri");

    file.close();
    return info;
}

std::string AccesslinkData::getValue(const std::string& json, const std::string& key) const
{
    size_t pos = json.find("\"" + key + "\"");
    if(pos == std::string::npos)
        return "";

    pos = json.find(":", pos);
    if(pos == std::string::npos)
        return "";
    
    pos++;
    while(pos < json.size() && (json[pos] == ' ' || json[pos] == '\"'))
        pos++;
    
    std::string value;
    while(pos < json.size() && json[pos] != ',' && json[pos] != '}' && json[pos] != '\"')
        value += json[pos++];
    return value;
}