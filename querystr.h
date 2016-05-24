/*
    Name: querystr.h
    Description: Simple query-string parser written in C using Object.h
    URL: https://github.com/flickerapps/querystr
    Author: Christopher Ventura <chrisventjs@gmail.com>
    Author URL: http://github.com/flickerapps
*/

#ifndef QUERYSTR_H
#define QUERYSTR_H

#include "modules/Objecth/Object.h"
#include "modules/libstr/libstr.h"


int queryalone(const char* str, int i, int  ini, var parsed){
    int origin = ini;
    int fin = i-1;
    char* keyst = substr((char*)str, ini, fin);
    var key = ObjectCreate((const char*)keyst);
    int fin_val = indexOfSub('&', (char*)str, fin);
    char* value;
    if(fin_val == -1){ /* one key/val */
        value = substr((char*)str, fin + 2, strlen(str) - 1);
    }
    else{ /* two or more keys/vals */
        value = substr((char*)str, fin + 2, fin_val - 1);
        ini = fin_val + 1;
    }
    if (value[strlen(value)]){
        value[strlen(value)] = '\0';
    }
    key->setString(key, (const char*) value);
    if(origin == 0){ parsed->setChild(parsed, key); }
    else { parsed->appendChild(parsed, key); }
    return ini;
}
var querystr(const char* str){
    var parsed = ObjectCreate("querystr");
    int ini = 0;
    for(int i = 0 ; i < strlen(str) ; i++){
        if( str[i] == '='){
            ini = queryalone(str, i, ini, parsed);
        }
    }
    return parsed;
}

#endif
