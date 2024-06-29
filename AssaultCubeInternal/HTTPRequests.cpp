#include "pch.h"

void jsonPostRequest()
{
    std::cout << "Json Post Request" << std::endl;
    try
    {
        http::Request request{ "http://10.0.0.3:3000/set" };
        const std::string body = "";
        const auto response = request.send("POST", body, {
            {"Content-Type", "application/json"}
            });
    }
    catch (const std::exception& e)
    {

    }
    std::cout << "End of Json Post Request" << std::endl;
}