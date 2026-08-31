//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

mapping get_items();

int tmp;

void create() {
    ::create();
    set_name("shack");
    set_short("rundown shack");
    set_long("The shack looks even worse from the inside.  The wood "
      "floors creak and buckle from the weight of the objects "
      "on it.  A small table sits in the northwest corner of "
      "the room.  There is a small lantern on top of it.  A "
      "skin rug lays on the floor in the middle of the shack."
      "  A bed sits in the southeast part of the shack.");
    set_items( get_items() );
    set_exits(([
	"out":ROOMS"72",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,"indoors":1,
	"no attack":1, "no steal":1,"no bump":1,]));
}

void do_clean() {
    object blah;
    blah = present("alverest");
    if(blah) {
	blah->force_me("say Ahh what a day.  I should hit the sac.");
	blah->force_me("emote crawls into bed and starts snoring.");
	blah->remove();
    }
}

void reset() {
    ::reset();
    tmp = 0;
    /*
	if(!query_night() && !present("alverest")) {
	    new(MON"alverest")->move(this_object());
	    message("", "A loud groan is heard as Alverest gets out of bed.", 
	      this_object());
	}
	if(query_night()) do_clean();
    */
    if(!present("alverest")) new(MON"alverest")->move(this_object());
}

mapping get_items() {
    mapping out;
    if(query_night() && !present("alverest")) out = ([ "bed":"A man is "
	  "sleeping in it." ]); 
    else out = ([ "bed":"The bed looks recently used." ]);
    out += ([
      "table":"There is a lantern on top of it.",
      "lantern":"The lantern is old and looks unusable.",
      ({"skin rug", "rug"}):"It lays in the center of the shack.",
    ]);
    return out;
}

int no() {
    write("Peace removed.\n");
    this_object()->set_properties((["light":1,"night
light":1,"forest":1,"indoors":1,
        "no attack":0, "no steal":0,"no bump":0,]));

}

void init() {
    ::init();
    add_action("lift", "lift");
    if(wizardp(this_player())) add_action("no", "nopeace");
}

int lift(string str) {
    if(!str || str != "lantern") return notify_fail("Lift what?\n");
    if(tmp == 1) return notify_fail("Lift what?\n");
    if(present("alverest")) {
      say("Alverest blocks "+this_player()->query_name()+" from lifting "
        "the lantern.");
      write("Alverest blocks you from lifting the lantern.\n");
      return 1;
    }
    write("The lantern lifts up with ease.  You notice a small note under "
      "the lantern.  A clicking noise comes from outside.\n");
    tmp = 1;
    say(this_player()->query_name()+" lifts the lantern.\n"
      "A clicking noise comes from outside.");
    new("/d/citrin/obj/quest/note")->move(this_object());
    return 1;
}

int query_tmp() { return tmp; }

