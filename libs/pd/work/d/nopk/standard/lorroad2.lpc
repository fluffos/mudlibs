#include <std.h>
#include <sindarii.h>
inherit ROOM;

int dug;
string orig_long, dug_long;

void look_at_mound() {
    if(!dug) write("It looks as if someone dug a hole there, "
                   "then covered it back up.");
    else write("It is a mound of dirt dug out from the hole beside it.");
}

int dig() {
    if(!present("shovel", this_player()) && !present("spade",this_player())) {
        notify_fail("You have nothing to dig with!\n");
        return 0;
    }
    write("You dig into the mound and uncover a hole.");
    say(this_player()->query_cap_name()+" digs into the mound "
        "and uncovers a hole.", this_player());
    dug = 1;
    add_item("hole", "A hole where someone just dug into the ground by the mound by the road.");
    add_exit(ROOMS"hole", "down");
    call_other(ROOMS"hole", "digging");
    return 1;
}

int query_dug() { return dug; }

string is_dug() {
   if (!dug) return "Lore road is an old dirt road leading past a few huts. "
     "An old hut on the western side of the road has a weathered sign hanging "
     "outside it. This is just about the middle of Lore Road. A mound of loose "
     "dirt covers part of the west side of the road.";
    else return "Lore road is an old dirt road leading past a few huts. An old "
     "hut on the western side of the road has a weathered sign hanging outside "
     "it. This is just about the middle of Lore Road. Near the run down hut on "
     "the west side of the road is a hole that looks like it has been recently "
     "dug.";
}

void init() {
    ::init();
    add_action("read", "read");
    add_action("dig", "dig");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "Middle of Lore Road");
    set("long", (: is_dug :));
    set_no_clean(1);
    set_items(
	(["road"  : "There is a mound of loose dirt piled by its side.",
	  "dirt"  : "It is very loose.",
	  "hut"   : "It is fairly run down and weathered, as well as the sign "
                    "hanging outside it.",
	  "sign"  : "The sign depicts a lantern and torch.",
	  "mound" : (: this_object(), "look_at_mound" :)
     ]));
      set_exits( 
		(["north" : ROOMS"lorroad3",
		  "south" : ROOMS"lorroad1",
                  "west"  : ROOMS"light" ]));
    dug = 0;
}

void reset() {
    ::reset();
    if(!dug) return;
    dug = 0;
    remove_item("hole");
    remove_exit("down");
    call_other(ROOMS"hole", "fixing_a_hole");
}
