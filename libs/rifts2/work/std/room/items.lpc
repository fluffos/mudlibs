//      /std/room/items.c
//      from the Nightmare mudlib
//      allows player to create dummy items for the room
//      created by Descartes of Borg 16 june 1993
//      Modified for v21 4/16/96

#include <config.h>
#include <daemons.h>


// handler for add_action( call_other, 'func');
#define ASTRA (: call_other, ASTRONOMY_D, "la_sky" :)
#define DEFAULT_ITEMS ([ "sky":ASTRA, "sun":ASTRA, "moon":ASTRA, ])

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
/*    string *special;
--caused warning Parnell*/
    mixed *cles;
    int i, j;

    i = sizeof(cles = keys(mp));
    tmp = mp;
    while(i--) {
        if(functionp(mp[cles[i]])) mp[cles[i]] = bind(mp[cles[i]], this_object());
//  Call to bind() above for v21 compat.
        if(pointerp(cles[i])) {
          j = sizeof(cles[i]);
          while(j--) tmp[cles[i][j]] = mp[cles[i]];
          map_delete(tmp, cles[i]);
        }
    }
    __Items = DEFAULT_ITEMS + tmp;
}

//  call to bind() added to insure v21 compat.
void add_item(string str, mixed val) {
    if(functionp(val)) val = bind(val, this_object());
    __Items[str] = val;
}

void remove_item(string str) { map_delete(__Items, str); }

mixed query_item_description(string str) { return __Items[str]; }

string query_no_item() { return DEFAULT_MSG; }

string describe(string str) {
    string tmp;

    if(!__Items[str]) return query_no_item();
    else if(functionp(__Items[str]))
    return ( (stringp(tmp=(string)((*__Items[str])(str)))) ? tmp: "" );
    else return __Items[str];
}
