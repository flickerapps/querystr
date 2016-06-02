#include "../querystr.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    var query = querystr(
        "foo=bar&lorem=ipsum&content=helloworld",
        '&', /* delimiter for items */
        '=', /* delimiter for key/val */
        QUERY_SOFT /* mode = not remove spaces, '\n', '\r' or '\t' */
        );
    var foo = query->find(query,"foo");
    printf("%s : %s\n",
        foo->getKey(foo), /* key */
        foo->getString(foo) /* value */
    );

    var lorem = query->find(query,"lorem");
    printf("%s : %s\n",
        lorem->getKey(lorem), /* key */
        lorem->getString(lorem) /* value */
    );

    var content = query->find(query,"content");
    printf("%s : %s\n",
        content->getKey(content), /* key */
        content->getString(content) /* value */
    );
    return 0;
}
