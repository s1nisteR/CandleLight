#include "clURI.h"

#include <utility>

using namespace CandleLight;

clURI::clURI(std::string t_uri) : m_uri(std::move(t_uri))
{
    UriParserStateA state;
    state.uri = &m_uriParse;
    m_isValid = uriParseUriA(&state, m_uri.c_str()) == URI_SUCCESS;
}

bool clURI::isValid() const
{
    return m_isValid;
}

clURI::~clURI()
{
    uriFreeUriMembersA(&m_uriParse);
}

std::string clURI::fromRange(const UriTextRangeA &t_range)
{
    return {t_range.first, t_range.afterLast};
}

std::string clURI::fromList(UriPathSegmentA *t_xs, const std::string &t_delim)
{
    UriPathSegmentStructA* head(t_xs);
    std::string accum;
    while(head)
    {
        accum += t_delim + fromRange(head->text);
        head = head->next;
    }
    return accum;
}
