// One can now enter the dump and dump oneself. //Graah
// New: mices for Utters //Frobozz

#include <areas.h>
#include "../DEFS.h"

inherit TRISTEZA_ROOM_C;

#define JANITORS 4
#define MICE 6

object *janitor,*mouse;

void
create_janitor()
{
    int i;
    for (i = 0; i < JANITORS; i++)
	if (!janitor[i]) {
	    janitor[i] = clone_object(NPC_DIR+"janitor");
	    janitor[i]->move_player("ff", this_object());
	    add_monster(janitor[i], 0, 0);
	}
}

void
create_mouse()
{
    int i;
    for (i = 0; i < MICE; i++)
	if (!mouse[i]) {
	    mouse[i] = clone_object(NPC_DIR+"mouse");
	    mouse[i]->move_player("ff", this_object());
	    add_monster(mouse[i], 0, 0);
	}
}

void
reset_room()
{
    create_janitor();
    call_out("create_mouse",2);
}

void
create_room()
{
    ::create_room();
    set_short("Crossing at the City Dump");
    set_long("You are at the crossing of the Newbie Road, which goes\
 north and south, and the Secret Street which goes east and west. The City\
 Dump is here - it's a bottomless-looking black pit of ten feet in diameter.");
    janitor = allocate(4);
    mouse = allocate(6);
    set_items(([
	({ "dumo", "pit", "hole" }) :
	"Gack! What an AWFUL smell! You feel too sick to look down."
      ]));
    set_exits(([
	"north"	: CITY_DIR + "S7_9",
	"east"	: CITY_DIR + "S8_10",
	"south"	: CITY_DIR + "S7_11",
	"west"	: CITY_DIR + "S6_10"
      ]));
    add_command("dump", "dump_stuff");
    add_command("enter","enter");
    add_command("jump","jump");
}

status
enter(string str)
{
    if (str != "dump" && str != "hole" && str != "pit")
	return notify_fail(capitalize(query_verb())+" where?\n"), 0;
    this_player()->tell_me("What???!?! Oh, very well then. You jump\
 down into the hole.");
#ifdef AREA_SEWERS
    this_player()->move_player("Vjumps into the dump", SEWERS2);
#else
    this_player()->tell_me("... but no. For some reason you bounce back!");
#endif
    return 1;
}

status
dump_stuff(string str)
{
    object ob;
    string tmp1,tmp2;

    if (!str) return notify_fail("Dump what?\n"), 0;

    if(sscanf(str,"%s coin%s",tmp1,tmp2)) return
	notify_fail("What??? Throw away money??? No way!\n"), 0;

    if (str == "me" || str == "myself" || str == "self" ||
      str == (string) this_player()->query_real_name())
	return enter("dump");

    if (!(ob = present(lower_case(str),this_player())))
	return notify_fail("You are not carrying any \"" + str + "\".\n"), 0;

    if (ob->drop()) return notify_fail("You cannot dump that.\n"), 0;

    if (!ob->short()) return notify_fail("That thing is too strange to be dumped.\n"), 0;

    move_object(ob, "/room/void");
    this_player()->recount_weight();

    this_player()->tell_me("Ok.");
    tell_here((string) this_player()->query_name() + " throws "
      + (string) ob->query_name() + " into the dump.");
    this_player()->add_exp(random(6));
    if (ob) destruct(ob);
    return 1;
}

status
jump(string str)
{
    string s;
    if (!str || !sscanf(str, "to %s", s))
	return notify_fail("Jump where? (to dump?)\n"), 0;
    return enter(s);
}

status is_city_dump() { return 1; }
