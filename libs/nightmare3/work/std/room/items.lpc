//      /std/room/items.c
//      from the Nightmare mudlib
//      allows player to create dummy items for the room
//      created by Descartes of Borg 16 june 1993

#include <config.h>
#include <daemons.h>
#include <astronomy.h>

#define DEFAULT_MSG "You do not notice that here.\n"
#define ASTRA (: find_object(ASTRONOMY_D), "la_sky" :)
#define DEFAULT_ITEMS ([ "sky":ASTRA, "sun":ASTRA, "moon":ASTRA, "moons":ASTRA,\
MOONS[0]:ASTRA, MOONS[1]:ASTRA, MOONS[2]:ASTRA, MOON_DESC[0]:ASTRA,\
MOON_DESC[1]:ASTRA, MOON_DESC[2]:ASTRA ])

private mapping __Items;

void set_items(mapping mp);
void add_item(string str, mixed val);
void remove_item(string str);

#ifdef __OLD_ROOM_BEHAVIOUR
#include <old_items.h>
#endif

void create() {
    __Items = DEFAULT_ITEMS;
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
        if(pointerp(cles[i])) {
          j = sizeof(cles[i]);
          while(j--) tmp[cles[i][j]] = mp[cles[i]];
          map_delete(tmp, cles[i]);
        }
    }
    __Items = DEFAULT_ITEMS + tmp;
}

void add_item(string str, mixed val) {
    if(functionp(val)) __Items[str] = val;
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
    else if(functionp(__Items[str])) {
        tmp = (string)(*__Items[str])(str);
        if(!tmp) return "You see nothing.";
        else return tmp;
    }
    else return __Items[str];
}
