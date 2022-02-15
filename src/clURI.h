#ifndef CANDLELIGHT_CLURI_H
#define CANDLELIGHT_CLURI_H

#include <string>
#include <uriparser/Uri.h>

namespace CandleLight
{
    class clURI
    {
    public:
        explicit clURI(std::string t_uri);
        ~clURI();
        [[nodiscard]] bool isValid() const;

        [[nodiscard]] std::string scheme() const { return fromRange(m_uriParse.scheme); }
        [[nodiscard]] std::string host() const { return fromRange(m_uriParse.hostText); }
        [[nodiscard]] std::string port() const { return fromRange(m_uriParse.portText); }
        [[nodiscard]] std::string path() const { return fromList(m_uriParse.pathHead, "/"); }
        [[nodiscard]] std::string query() const { return fromRange(m_uriParse.query); }
        [[nodiscard]] std::string fragment() const { return fromRange(m_uriParse.fragment); }
    private:
        std::string m_uri;
        UriUriA  m_uriParse{};
        bool m_isValid;

        [[nodiscard]] static std::string fromRange(const UriTextRangeA &t_range) ;
        [[nodiscard]] static std::string fromList(UriPathSegmentA* t_xs, const std::string &t_delim) ;
    };

}

#endif //CANDLELIGHT_CLURI_H
