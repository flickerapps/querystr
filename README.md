querystr.h
====
Simple query string parse written in C using [Object.h](https://github.com/flickerapps/Objecth) lib.


Use
====

clone the repo and add the modules:
```
 $ git clone https://github.com/flickerapps/querystr.git --recurse-submodules
```


```c
#include "querystr.h"

int main(int argc, char const *argv[])
{
    var query = querystr(
        "foo=bar&hello=world", /* query */
        '&', /* delimiter for items */
        '=', /* delimiter for key/val */
        QUERY_SOFT /*  mode = not remove spaces, '\n', '\r' or '\t' */
    );
    var foo = query.find(query,"foo");

    printf("foo : %s\n", foo.getString(foo) );
    return 0;
}
```

Stringify query:
```c
char* str = stringify(
    query, /* query parsed */
    ": ", /* key/val delimiter (string)*/
    "\r\n", /* items delimiter (string)*/
    1  /* mode = if mode is > 0 include delimiter #2 in last key */
);
```
License
====
[MIT](LICENSE)
