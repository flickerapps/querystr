#include "../querystr.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    var query = querystr(
        "GET /foo HTTP/1.1\r\n"
        "Host: 127.0.0.1\r\n"
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
    /*
    var Host = query->find(query, "Host");
    var Cache_Control = query->find(query, "Cache-Control");
    printf("Host: %s\n", Host->getString(Host) );
    printf("Cache-Control: %s\n", Host->getString(Cache_Control));
    */

    char* strgified = stringify(
        query, /* query parsed */
        ": ", /* key/val delimiter (string)*/
        "\r\n", /* items delimiter (string)*/
        1 /*mode = if mode is > 0 include delimiter #2 in last key*/
    );

    printf("%s\n", strgified);
    return 0;
}
