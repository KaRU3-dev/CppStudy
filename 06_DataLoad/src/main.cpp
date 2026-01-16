#include <cstdio>
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <tinyxml2.h>

int main()
{
#pragma region JSON

    FILE *testJsonFile = std::fopen("data/test.json", "rb");
    if (!testJsonFile)
    {
        std::cerr << "Failed to open test.json" << std::endl;
        return 1;
    }

    char buffer[4096];
    rapidjson::FileReadStream testJsonFileStream(testJsonFile, buffer, sizeof(buffer));

    rapidjson::Document testJsonDocument;
    testJsonDocument.ParseStream(testJsonFileStream);

    std::fclose(testJsonFile);

    if (!testJsonDocument.IsObject())
    {
        std::cerr << "Failed to parse test.json" << std::endl;
        return 1;
    }

    std::string data = testJsonDocument["data"]["text"].GetString();
    std::cout << data << std::endl;

#pragma endregion

#pragma region XML

    tinyxml2::XMLDocument testXmlDocument;
    testXmlDocument.LoadFile("data/test.xml");

    tinyxml2::XMLElement *rootElement = testXmlDocument.FirstChildElement("data");
    tinyxml2::XMLElement *textElement = rootElement->FirstChildElement("text");
    const char *text = textElement->GetText();
    std::cout << text << std::endl;

#pragma endregion
    return 0;
}
