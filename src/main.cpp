#include <iostream>
#include <algorithm>

#include <cpr/cpr.h>
#include "clParser.h"

int main()
{

    cpr::Response r = cpr::Get(cpr::Url{"https://wikipedia.com"});
    CandleLight::clParser test;
    std::vector<std::string> results;
    results = test.clParseLinks(r.text);
    for(auto& x : results)
    {
        std::cout << x << std::endl;
    }





    return 0;
}
