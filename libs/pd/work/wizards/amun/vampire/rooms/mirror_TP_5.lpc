#include <std.h>
#include <vampq.h>
inherit ROOM;
string make_a_long();
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "indoors" : 1 ]));
    set("short", "Hall of Mirrors");
    set_long( (: make_a_long :) );
    set_exits( ([ "east" : VR"mirror_TP_6" ]) );
    set_invis_exits( ({ "south" }) );
    add_pre_exit_function("enter", "go_enter");
}
string make_a_long() {
    return "%^BOLD%^%^BLACK%^This room is unlike the others. A single mirror is placed in the middle of the room, and no reflection can be seen. Looking at the mirror more closely might prove to be helpful.%^RESET%^";
}
void reset() {
    if(!present("black mirror"))
	new(VO"hom_mirror")->move(this_object());
}
void init() {
    ::init();
    add_action("smash", "smash");
}
int go_enter() {
    if (present("black mirror")) {
	return notify_fail("Try smashing the mirror!\n"); 
    }
    else {
	return 1; }
}
int smash(string str) {
    if (str == "mirror") {
	write("%^BOLD%^%^BLACK%^You smash the mirror into pieces, this causes your reflection to leave you!!%^RESET%^"); 
	present("black mirror")->remove();
	add_exit(VR"od_1", "enter");
	return 1;
    }
    write("Try breaking the mirror somehow!");
    return 1;

}
