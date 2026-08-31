//      /std/room/items.c
//      from the Nightmare mudlib
//      allows player to create dummy items for the room
//      created by Descartes of Borg 16 june 1993

#include <config.h>
#include <daemons.h>
#include <astronomy.h>

inherit ASTRONOMY_D;
#define DEFAULT_MSG "You do not notice that here."
#define DEFAULT_NO_ITEM_MSG "There is nothing extraordinary about it."
#define ASTRA (: la_sky :)
#define DEFAULT_ITEMS ([ "sky":ASTRA, "sun":ASTRA, "moon":ASTRA, "moons":ASTRA,\
MOONS[0]:ASTRA, MOONS[1]:ASTRA, MOONS[2]:ASTRA, MOON_DESC[0]:ASTRA,\
MOON_DESC[1]:ASTRA, MOON_DESC[2]:ASTRA ])

private mapping __Items;

void set_items(mapping mp);
void add_item(string str, mixed val);
void remove_item(string str);



void create() {
    __Items = DEFAULT_ITEMS;
    astronomy_d::create();
}

string *query_id() { return keys(__Items); }

int id(string str) { 
   if(!__Items) return 0;
   return (str && __Items[str]); 
}

void set_items(mapping mp) {
    mapping tmp;
    mixed *cles;
    int i, j;

    i = sizeof(cles = keys(mp));
    tmp = mp;
    while(i--) {
        
        if(pointerp(cles[i])) {
          j = sizeof(cles[i]);
          while(j--) tmp[cles[i][j]] = mp[cles[i]];
          map_delete(tmp, cles[i]);
        }
    }
    __Items = DEFAULT_ITEMS + tmp;
}

void add_item(string str, mixed val) {
    
    __Items[str] = val;
}

void remove_item(string str) { map_delete(__Items, str); }

mixed query_item_description(string str) { return __Items[str]; }

string query_no_item(string str) { 
if (str) {
  if(strsrch(this_object()->query_long(),str)!=-1) {
    return DEFAULT_NO_ITEM_MSG;
  }
}
 return DEFAULT_MSG; 
}

string describe(string str) {
    string tmp;

    if (!str || str=="") return query_no_item("");
    if(!__Items[str]) return query_no_item(str);
    else if(functionp(__Items[str]))
    return ( (stringp(tmp=(string)((*__Items[str])(str)))) ? tmp: "" );
    else return __Items[str];
}
