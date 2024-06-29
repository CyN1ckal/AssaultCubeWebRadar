#include "pch.h"

void TestPostRequest()
{
    try
    {
        http::Request request{ "http://10.0.0.3:3000/" };
        const std::string body = "foo=1&bar=baz";
        const auto response = request.send("POST", body, {
            {"Content-Type", "application/x-www-form-urlencoded"}
            });
        std::cout << std::string{ response.body.begin(), response.body.end() } << '\n'; // print the result
    }
    catch (const std::exception& e)
    {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }
}