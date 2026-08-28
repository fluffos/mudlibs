//      /std/room/items.c
//      from the Nightmare mudlib
//      allows player to create dummy items for the room
//      created by Descartes of Borg 16 june 1993

#include <config.h>
#include <daemons.h>

#define DEFAULT_MSG "You do not notice that here.\n"
private mapping __Items;

void set_items(mapping mp);
void add_item(string str, mixed val);
void remove_item(string str);

void create() {
    __Items = ([]);
}

string *query_id() { return keys(__Items); }

int id(string str) { return (str && __Items[str]); }

void set_items(mapping mp) {
    mapping tmp;
    string *special;
    mixed *cles;
    int i, j;

    i = sizeof(cles = keys(mp));
    tmp = copy(mp);
    while(i--) {
        if(functionp(mp[cles[i]]))
          if(!((int)master()->valid_function(mp[cles[i]]))) continue;
        if(pointerp(cles[i])) {
          j = sizeof(cles[i]);
          while(j--) tmp[cles[i][j]] = mp[cles[i]];
          map_delete(tmp, cles[i]);
        }
    }
    __Items = tmp;
}

void add_item(string str, mixed val) {
    if(functionp(val) && (int)master()->valid_function(val))
      __Items[str] = copy(val);
    else if(stringp(val)) __Items[str] = val;
    else error("Bad argument 2 to add_item().\n");
}

void remove_item(string str) { map_delete(__Items, str); }

mixed query_item_description(string str) {
    if(functionp(__Items[str])) return copy(__Items[str]);
    else return __Items[str];
}

string query_no_item() { return DEFAULT_MSG; }

string describe(string str) {
    string tmp;

    if(!__Items[str]) return query_no_item();
    else if(functionp(__Items[str]))
      return ( (stringp(tmp=(string)((*__Items[str])(str)))) ? tmp: "" );
    else return __Items[str];
}
