#include "clParser.h"

#include <iostream>
using namespace CandleLight;

clParser::clParser()
{
    document = lxb_html_document_create();
    collection = lxb_dom_collection_make(&document->dom_document, 128);
}

clParser::~clParser()
{
    lxb_dom_collection_destroy(collection, true);
    lxb_html_document_destroy(document);
}

std::vector<std::string> clParser::clParseLinks(const std::string& html)
{
    std::string link;
    std::vector<std::string> links;
    size_t htmlLen = html.size() - 1;
    lxb_char_t htmlForParser[htmlLen + 1];
    std::copy(html.begin(), html.end(), htmlForParser);
    lxb_status_t status;
    status = lxb_html_document_parse(document, htmlForParser, htmlLen);
    if(status != LXB_STATUS_OK)
    {
        //TODO: Handle Errors
    }
    //TODO: what about <iframe src=.... links?
    lxb_dom_elements_by_tag_name(lxb_dom_interface_element(document->body), collection, (const lxb_char_t*)"a", 1);
    for(size_t i = 0; i < lxb_dom_collection_length(collection); i++)
    {
        auto node = lxb_dom_collection_node(collection, i);
        auto attr = lxb_dom_element_attr_by_name(lxb_dom_interface_element(node), (const lxb_char_t* )"href", 4);
        link = reinterpret_cast<const char*>(lxb_dom_attr_value(attr, nullptr));
        //std::cout << link << std::endl;

        if(std::regex_match(link, std::regex("(http|https)://([^/ :]+):?([^/ ]*)(/?[^ #?]*)\\x3f?([^ #]*)#?([^ ]*)")))
        {
            links.push_back(link);
        }
        if(std::regex_match(link, std::regex("//([^/ :]+):?([^/ ]*)(/?[^ #?]*)\\x3f?([^ #]*)#?([^ ]*)")))
        {
            link.insert(0, "http:");
            links.push_back(link);
        }
    }
    return links;
}
