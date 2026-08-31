//descriptions for Roston by Stormy
#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    object oi;
    ::create();
    set_name("Roston Square");
    set_properties(([      "light" : 2,
                     "night light" : 1,
                       "no attack" : 1,
                        "no magic" : 1,
                         "no bump" : 1,
                        "no steal" : 1,
                            "town" : 1]));
    set_short("Roston Square");
    set_long("Roston Square is the meeting place of this dwarven town. The hunters "
             "and miners of Roston come here to trade their goods and services. Snow "
             "covered mountains dominate the skyline of the entire area. The settlement "
             "spreads out in all directions from here. A large building dominates the "
             "northeast corner of town.");
    set_items(([    "snow" : "Snow covers the ground and the nearby mountains.",
	          "mountain" : "Snow covered mountains tower over this valley.",
                "building" : "A small fortified castle."]));
    set_exits( ([  "north" : ROOMS "roston2",
	             "south" : ROOMS "roston3",
	             "west"  : ROOMS "roston11",
	             "east"  : ROOMS "roston12" ]));
    set_smell("default", "The scent of leather wafts in from the south.");
    set_listen("default", "The sound of clanging metal comes from the west.");
    oi = new("/std/bboard");
    oi->set_name("roston board");
    oi->set_id( ({ "board", "town board", "roston board" }) );
    oi->set_board_id("roston_board");
    oi->set_max_posts(999);
    oi->set_location(ROOMS "roston");
    oi->set("short", "Roston Town Board");
    oi->set("long", "A weathered board for posting notes to others in the Roston area.");
}

void reset() {
    if(!present("statue"))
	new(OBJ "statue")->move(this_object());
    if(!present("monster"))
	new(MOB "guard")->move(this_object());
} 
