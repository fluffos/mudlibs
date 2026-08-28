//      /std/room.c
//      from the Nightmare Mudlib
//      the room object
//      written by Descartes of Borg 17 june 1993
//      ::create() added by Pallando (93-06-18)
//      ::create() changed to container::create() with calls to
//      items::create(), exits::create(), and senses::create() added
//      by Descartes 930619
//      this_object()->setup(); removed from reset() by Pallando (93-06-20)
//      seteuid(getuid()) removed from create() by Pallando (93-06-23)
//      query_long() changed not to give error if none set by Pallando 93-07-10
// Modified by Misery 030696 whom is too lazy to correctly indent this
// Modified by Thrace 070499 to fix an eval limit bug.
// comment

#include <std.h>
#include <rooms.h>
#include <move.h>

inherit CONTAINER;
inherit "/std/room/senses";
inherit "/std/room/exits";
inherit "/std/room/items";


private int reset_number;

void reset();
void reinitiate();
void set_short(string str);
void set_long(string str);
string query_short();
string query_long(string str);
string query_extra_long();
int move(mixed dest);
int query_reset_number();

void create() {
    container::create();
    exits::create();
    items::create();
    senses::create();
    reset_number = 0;
    this_object()->reset();
}

void reset() {
   reset_eval_cost();
    container::reset();
    reset_number++;
}

void init() {
    exits::initiate_exits();
    senses::initiate();
}

/*
 * Now clean_up will only be called in rooms, and basically if
 * it doesnt contain pets or players and isnt a locker room,
 * everything in it gets rocked.
 *
 *
 * Diewarzau 7/22/96
  */

int clean_up()
{
    object *inv = all_inventory(this_object());
    object ob;

    if (query_property("storage room"))
        return 0;
    foreach (ob in inv)
    {
        if (ob->is_player())
            return 1;
        if (ob->is_pet() && stringp(ob->query_owner()) &&
            find_player((string)ob->query_owner()))
            return 1;
        if (ob->query_property("no clean"))
            return 1;
        reset_eval_cost();
    }
    inv = deep_inventory(this_object());
    foreach (ob in inv)
    {
        reset_eval_cost();
        if (ob)
            ob->remove();
    }
    this_object()->remove();
    return 0;
}

void set_short(string str) { container::set_short(str); }

void set_long(string str) { container::set_long(str); }

string query_short() {
    return container::query_short();
}

string query_long(string str) {
    string ret;


    if(str) return describe(str);
    else {
	if(query_night() && query("night long")) ret = query("night long");
	else if(!query_night() && query("day long")) ret = query("day long");
else ret = container::query("long");
    }
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
      if(tmp = (string)inv[i]->affect_environment()) ret += tmp;
    return ret;
}

void reinitiate() {
    object *inv;
    int i;

    i = sizeof(inv = all_inventory(this_object()));
    while(i--) {
	inv[i]->move(ROOM_VOID);
	inv[i]->move(this_object());
    }
}

int query_reset_number() { return reset_number; }

int move(mixed dest) { return MOVE_NOT_ALLOWED; }

string *query_id() { return items::query_id(); }

int id(string str) { return items::id(str); }

/*  Added by Misery 030696 so move.c would function properly */
nomask int query_room() { return 1; }
