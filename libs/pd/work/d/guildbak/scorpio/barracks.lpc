#include <std.h>
#include <guild.h>
#include <rest.h>
inherit ROOM;

void create() {
    object b;
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );
    set_long("This is the barracks of the Scorpio guild. "
      "Around you, you see many beds, each with the name "
      "of a member of the guild inscribed on them. The "
      "room is very clean, for the leaders promote "
      "neatness.  If you wish to sleep on a bed simply "
      "<lay bed>\n");
    set_name("Scorpio Barracks");
    set_short("Scorpio Barracks");
    set_exits((["north":SCORPIO"lounge",]));
    b = new(OBJECT);
    b->set_name("bed");
    b->set_short("a bed");
    b->set_prevent_get("Share will ya?\n");
    b->set_long("Many beds line the walls so that the "
      "members of the guild may have a peaceful sleep.");
    b->move(this_object());
}

void init() {
    ::init();
    add_action("lay", "lay");
}

int lay(string str) {
    if(str != "bed") return 0;
    if(this_player()->query_current_attacker()) return 
	notify_fail("You cannot rest in battle.\n");
    if (this_player()->query_rest_type() == LAY ) {
	write("You are already laying on the bed.\n");
	return 1;
    }
    if((this_player()->query_riding() ||
	this_player()->query_mounting()))
	this_player()->force_me("dismount");
    write("You find an unoccupied bed and lay down on it.");
    this_player()->set_rest_type( LAY );
    say(capitalize(this_player()->query_cap_name())+" finds a nice "
      "bed and lays down on it.");
    return 1;
}

