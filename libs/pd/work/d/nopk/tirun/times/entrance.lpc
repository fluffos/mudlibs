#include <std.h>
#include <tirun.h>
#define MASTER ROOMS"times/master"
inherit ROOM;

void create() {
 ::create();
    set_short("Tirun Times");
    set_long("Welcome to the Tirun Times.  A large archway marks the entrance into the great hall.  The "
	"bright red carpet on the floor is fairly new.  Portraits of past scholars and students adorn "
	"the walls.  A large desk sits in the back of the room next to a large door.  A portly woman is "
	"sitting behind it, busily at work.");
    set_night_long("Welcome to the Tirun Times.  The building seems very quiet.  Not much activity is taking place "
	"except for the occasional late night reporter hard at work.  A desk sits to the north next to a large "
	"door.  The door is blocked off by a red, velvet rope.");
    set_exits( 
              (["north" : ROOMS"times/newsroom",
                "south" : ROOMS"whonin5",
]) );

    set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1 ]) );
    set_items(
        ([
	"carpet":"Its nice and new.  Very bouncy!",
	"desk":"The desk is a made from oak.  Its varnished in an antique red giving it a sense of class.  It is neat and "
		"clean.",
	"portaits":"The portaits are of scholars.",
]) );
    add_pre_exit_function("north", "go_north");
}

int go_north() {
	if(!MASTER->is_member() && query_night()) {
		write("Only reporters are allowed in the offices at night.");
		return 0;
	}
	write("Welcome to the Tirun Times News Room");
	return 1;
}
