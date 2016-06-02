/*
    Name: querystr.h
    Description: Simple query-string parser written in C using Object.h
    URL: https://github.com/flickerapps/querystr
    Author: Christopher Ventura <chrisventjs@gmail.com>
    Author URL: http://github.com/flickerapps
*/

#ifndef QUERYSTR_H
#define QUERYSTR_H

#include "modules/Object.h/Object.h"
#include "modules/libstr/libstr.h"
#include <stdio.h>

#define QUERY_HARD 1
#define QUERY_SOFT 1
var querystr(const char* str, char delim1, char delim2, int mode){
    char* nstr = (char*)calloc(strlen(str) + 1, sizeof(char));
    strncpy(nstr, str, strlen(str));
    var parsed = ObjectCreate((char*)"querystr");
    int ini = 0;
    int i;
    char** splited = strsplit(delim1, (char*)str);
    char rem[] = " \n\r\t";
    char remsoft[] = "\r\n\t";
    char** item;
    for(i = 0; i < arraylen(splited) ; i++){
        item = strsplit(delim2, splited[i]);
        if(item[1] != NULL){
            if(mode == QUERY_HARD){
                item[0] = removechars(rem, item[0]);
                item[1] = removechars(rem, item[1]);
            }
            var child = ObjectCreate(item[0]);
            child->setString(child, item[1]);
            if(parsed->value == NULL){
                parsed->setChild(parsed, child);
            }
            else{
                parsed->appendChild(parsed, child);
            }
        }
        else{
            if(mode == QUERY_HARD){
                item[0] = removechars(remsoft, item[0]);
            }
        }
    }
    return parsed;
}

char* stringify(var parsed, const char* delim1, const char* delim2, int mode){
    /*
    * if mode is 0 not include delim2 in last item.
    */
    char* strgify = (char*)calloc(1, sizeof(char));
    int stlen = 0;
    if(parsed->value == NULL){
        return (char*)"Empty";
    }
    else{
        var item = parsed->getChild(parsed);
        int itemlen = 0;
        while(item != NULL){
            itemlen += strlen(item->getKey(item)) + strlen(delim1) + strlen(item->getString(item)) + strlen(delim2);
            stlen += itemlen;
            strgify = (char*)realloc(strgify, sizeof(char) * stlen);
            strncat(strgify, item->getKey(item), strlen(item->getKey(item)));
            strncat(strgify, delim1, strlen(delim1));
            strncat(strgify, item->getString(item), strlen(item->getString(item)));
            strncat(strgify, delim2, strlen(delim2));
            item = item->next;
        }
    }
    strgify[stlen] = '\0';
    return strgify;
}
#endif
