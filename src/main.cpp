#include <iostream>
#include <algorithm>

#include <cpr/cpr.h>
#include "clURI.h"
#include <lexbor/html/parser.h>
#include <lexbor/dom/interfaces/element.h>

int main()
{
    lxb_html_document_t* document = lxb_html_document_create();
    lxb_dom_collection_t* collection;


    cpr::AsyncResponse fr = cpr::GetAsync(cpr::Url{"https://google.com"});
    cpr::Response r = fr.get();

    //static const auto* html = reinterpret_cast<const lxb_char_t *>(r.text.c_str());
    size_t htmlLen = r.text.size() - 1;
    lxb_char_t html[htmlLen + 1];
    std::copy(r.text.begin(), r.text.end(), html);


    lxb_html_document_parse(document, html, htmlLen);
    collection = lxb_dom_collection_make(&document->dom_document, 128);
    //lxb_dom_elements_by_tag_name(lxb_dom_interface_element(document->body), collection, (const lxb_char_t*) "a", 3);
    lxb_dom_elements_by_tag_name(lxb_dom_interface_element(document->body), collection, (const lxb_char_t*)"a", 1);
    for(size_t i = 0; i < lxb_dom_collection_length(collection); i++)
    {
        auto node = lxb_dom_collection_node(collection, i);
        auto attr = lxb_dom_element_attr_by_name(lxb_dom_interface_element(node), (const lxb_char_t* )"href", 4);
        std::string test = reinterpret_cast<const char*>(lxb_dom_attr_value(attr, nullptr));
        CandleLight::clURI mine(test);
        std::cout << mine.host() << std::endl;
    }
    lxb_dom_collection_destroy(collection, true);
    lxb_html_document_destroy(document);
    return 0;
}
