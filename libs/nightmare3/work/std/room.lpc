/*    /std/room.c
 *    from Nightmare IV
 *    the generic room object
 *    created by Descartes of Borg 940711
 */

#include <std.h>
#include <move.h>
#include <rooms.h>
#include "room.h"

inherit CONTAINER;
inherit EXITS;
inherit ITEMS;
inherit SENSES;

nosave private int __ResetNumber;
nosave private string __DayLong, __NightLong;

void create() {
    container::create();
    exits::create();
    items::create();
    senses::create();
    __ResetNumber = 0;
    reset();
    call_out("reinitiate", 0);
}

protected  void reset() {
    container::reset();
    __ResetNumber++;
}

void init() {
    container::init();
    exits::init();
    senses::init();
}

void set_short(string str) { container::set_short(str); }

void set_long(mixed val) { container::set_long(val); }

string query_short() {
    return container::query_short();
}

varargs string query_long(string str) {
    string ret;
    object ob;

    if(str) return describe(str);
    else if(__DayLong && !query_night()) ret = __DayLong;
    else if(__NightLong && query_night()) ret = __NightLong;
    else ret = container::query_long();
    if( !ret ) ret = "";
    if(query_extra_long() != "") ret += query_extra_long();
    return ret;
}

string query_extra_long() {
    object *inv;
    string ret, tmp;
    int i;

    ret = "";
    i = sizeof(inv = all_inventory(this_object()));
    while(i--)
      if(tmp = (string)inv[i]->affect_environment()) ret += "  "+tmp;
    return ret;
}

int query_reset_number() { return __ResetNumber; }

int move(mixed dest) { return MOVE_NOT_ALLOWED; }

string *query_id() { return items::query_id(); }

int id(string str) { return items::id(str); }

varargs int receive_objects(object ob) {
    if(!ob) ob = previous_object();
    if(ob == this_object()) return 0;
    return 1;
}

void set_day_long(string str) { __DayLong = str; }

string query_day_long() { return __DayLong; }

void set_night_long(string str) { __NightLong = str; }

string query_night_long() { return __NightLong; }
