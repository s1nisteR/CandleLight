#ifndef CANDLELIGHT_CLPARSER_H
#define CANDLELIGHT_CLPARSER_H

#include <lexbor/html/parser.h>
#include <lexbor/dom/interfaces/element.h>
#include <vector>
#include <string>
#include <regex>
#include "clURI.h"


namespace CandleLight
{
    class clParser
    {
    public:
        clParser();
        ~clParser();
        [[nodiscard]] std::vector<std::string> clParseLinks(const std::string& html);
    private:
        lxb_html_document_t* document;
        lxb_dom_collection_t* collection;

    };
}

#endif //CANDLELIGHT_CLPARSER_H
