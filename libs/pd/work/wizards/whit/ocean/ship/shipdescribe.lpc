//  Ship Description Simulator
//    Whit
//  Provides custom describs for ships...
#include <daemons.h>
string long_desc;
#define BAD_WORDS ({"shit", "fuck", "cunt", "bitch", "bastard", "slut", "ass", "pussy", "clit"})
string query_long_short() {
    return long_desc;
}
int query_valid_long(string str) {
    int i;

    return "/daemon/filter_d"->filter("say", str);
    i=sizeof(BAD_WORDS);
    while(i--)
	if(strsrch(str, BAD_WORDS[i])!=-1) return 0;
    return 1;
}
void set_long_short(string str) {
    long_desc=str;
   this_object()->save();
}
