#include "../querystr.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    var query = querystr(
        "GET /foo HTTP/1.1\r\n"
        "Host: 127.0.0.1\r\n"
        "User-Agent: Mozilla/5.0 (X11; Linux i686; rv:46.0) Gecko/20100101 Firefox/46.0\r\n"
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
        "Accept-Language: en-US,en;q=0.5\r\n"
        "Accept-Encoding: gzip, deflate\r\n"
        "Connection: keep-alive\r\n"
        "Cache-Control: max-age=0\r\n"
        "sid=2345454234fjf\r\n",
        '\n', /* delimiter of items */
        ':', /* delimiter of key/val*/
        QUERY_HARD /* remove spaces, '\t', '\r', '\n' in keys/values */
    );
    var Host = query->find(query, "Host");
    var Cache_Control = query->find(query, "Cache-Control");
    printf("Host: %s\n", Host->getString(Host) );
    printf("Cache-Control: %s\n", Host->getString(Cache_Control));
    return 0;
}
