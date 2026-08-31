#include <std.h>
#include <guild.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack" : 1, "no magic" : 1, "no bump" : 1, "light" : 2, "no scry" : 1, "indoors" : 1, "no steal" : 1 ]));
    set("short", "ILLUMINATI");
    set("long","");
    set_exits( ([ "south" : ILLROOM "ill_31", "northeast" : ILLROOM "ill_33", "northwest" : ILLROOM "ill_34", "up" : ILLROOM "ill_36", "down" : ILLROOM "ill_24" ]) );
}
void init() {
    ::init();
    add_action("south", "south");
}
int south() {
    if (this_player()->query_name() == "furiae" || wizardp(this_player())){
	this_player()->move_player(ILLROOM "ill_31");
	return 1;
    }
    if (this_player()->query_name() == "goldenberry" || wizardp(this_player())){
	this_player()->move_player(ILLROOM "ill_31");
	return 1;
    }
    else {
	write("You are not permitted into Furiae's Personal Chambers");
	return 1;
    }
}
