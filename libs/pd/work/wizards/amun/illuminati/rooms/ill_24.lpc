#include <std.h>
#include <guild.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack" : 1, "no magic" : 1, "no bump" : 1, "light" : 2, "no scry" : 1, "indoors" : 1, "no steal" : 1 ]));
    set("short", "ILLUMINATI");
    set("long","");
    set_exits( ([ "south" : ILLROOM "ill_25", "east" : ILLROOM "ill_26", "northeast" : ILLROOM "ill_27", "northwest" : ILLROOM "ill_28", "west": ILLROOM "ill_29", "up" : ILLROOM 
	"ill_30", "down" : ILLROOM "ill_20" ]) );
    add_pre_exit_function("northwest", "go_northwest");
    add_pre_exit_function("northeast", "go_northeast");
    add_pre_exit_function("east", "go_east");
    add_pre_exit_function("west", "go_west");
    add_pre_exit_function("south", "go_south");
}
int go_northwest() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "rogue") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "rogue's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int go_northeast() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "wanderer") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "wanderer's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int go_east() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "mage") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "mage's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int go_west() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "clergy") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "clergy's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int go_south() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "fighter") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "fighter's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
