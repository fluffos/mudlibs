// Coded by Whit

#include <std.h>
#include <tombar.h>


inherit ROOM;
int rt;
void reset() {
    ::reset();
    if(!present("guard")) {
	new(MON"guard1")->move(this_object());
	new(MON"guard1")->move(this_object());
	new(MON"guard1")->move(this_object());
    }

    rt=1;
}

void init() {
    ::init();
    add_action("look", "look");
    add_action("southeast", "southeast");
}

void create() {
    ::create();
    set_name("a long, black hallway");
    set_long("The hallway is well lit.  There are several table here "
      "full of small provisions that guards use to stay here constantly "
      "to guard the temple.  The walls are wet from the dripping water "
      "that comes from the ceiling.  The floor is covered in a black, "
      "soupy substance.  It looks like it may be poison.");
    set_items(([
	(({"wall","walls"})) : "The walls are wet from constant exposure to water.",
	"ceiling" : "Water seems to run from the ceiling making the floor wet.",
	"floor" : "There seems to be a black poison on the floor.",
      ]));
    set_property("light", 0 );
    set_property("night light", 0);
    set_property("inside", 1);
    set_exits(([
	"southeast" : ROOMS"16",
	"north" : ROOMS"14",
      ]));

}

int southeast() {
    if(!present("tombar guard")) {
	this_player()->move_player(ROOMS"16");
	return 1;
    }
    write("One of the guards hold you back as you try to pass.");
    say("One of the guards hold "+this_player()->query_cap_name()+" back from the exit.");
    return 1;
}

int look(string str) {
    if(str == "provisions") {
	if(rt==1) {
	    write("You find a small letter under the provisions.");
	    new(OBJ"letter")->move(this_player());
	    rt==0;
	    return 1;
	}
	write("You find nothing odd in the provisions.");
	return 1;
    }
    return 0;
}
