#include <std.h>
#include <tirun.h>

inherit ROOM;

int sofas, tables;

void create() {
    ::create();
    set_smell("default", "Thick dust makes breathing difficult.");
    set_listen("default", "Silence.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
      "%^BLUE%^A cold breeze blows by from nowhere...%^RESET%^\n"
      "The entrance to this house is old and worn.  When this house was first built, "
      "it must have been a marvelous sight to see.  Plush rugs are now torn and "
      "ragged from animals taking their fibers.  Small toppled end tables lay askew "
      "to each side, once fine sofas sit gutted and uncomfortable looking.  A deep "
      "forboding fills the room.");
    set_items(
      (["entrance" : "The entrance to this house leads out to the streets of tirun.",
	"rugs" : "Tattered and torn, the rugs are full of holes and have lost most of their padding.",
	({"endtable", "endtables"}) : "The endtables have been knocked over, almost as if someone had been searching for something.",
	"sofas" : "Rats and other small animals have torn most of the stuffing out of the sofas."]) );
    set_exits( ([ "east" : ROOMS"hhouse/4",
	"west" : ROOMS"hhouse/2",
	"north" : ROOMS"hhouse/3",
	"out" : ROOMS"wmullin5" ]) );
    sofas = 0;
    tables = 0;
}

void init() {
    ::init();
    add_action("search", "search");
}

void reset() {
    ::reset();
    sofas = 0;
    tables = 0;
}

int search(string str) {
    object mon;
    if(!str) return 0;

    switch(str) {
    case "sofas": if(sofas) return 0; break;
    case "endtables": if(tables) return 0; break;
    default: return 0;
    }

    if(str == "sofas") {
	write("You find a nest of angry rats!");
	say(this_player()->query_cap_name()+" uncovers a nest of angry rats!");
	for(int i=0;i < 4;i++) {
	    mon = new(MOB"rat");
	    mon->set_level(2+random(2));
	    mon->move(this_object());
	}
	sofas = 1;
    }

    if(str == "endtables") {
	write("You find a note stuck to the back of a drawer.");
	say(this_player()->query_cap_name()+" finds a piece of paper.");
	new(ROOMS"hhouse/note")->move(this_player());
	tables = 1;
    }
    return 1;
}
