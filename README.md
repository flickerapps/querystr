querystr.h
====
Simple query string parse written in C using [Object.h](https://github.com/flickerapps/Objecth) lib.

```c
#include "querystr.h"

int main(int argc, char const *argv[])
{
    var query = querystr("foo=bar");
    var foo = query.find(query,"foo");

    printf("%s : %s\n",
        foo.getKey(foo), /* key */
        foo.getString(foo) /* value */
    );
    return 0;
}
```

License
====
[MIT](LICENSE)
