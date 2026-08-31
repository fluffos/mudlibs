#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^BLUE%^There are %^MAGENTA%^bu%^RESET%^%^MAGENTA%^tt%^BOLD%^%^YELLOW%^er%^GREEN%^fl%^RED%^ie%^WHITE%^s %^BLUE%^of all colors and shapes flowing in and out of the area. An %^WHITE%^ice chest %^BLUE%^can be seen lying open along the west wall. To the north, drums can be heard and a %^RESET%^%^RED%^ca%^BOLD%^%^BLACK%^mp%^RESET%^%^ORANGE%^fi%^BOLD%^%^BLACK%^re%^RESET%^%^RED%^s l%^BOLD%^%^BLACK%^ig%^RESET%^%^ORANGE%^ht %^BOLD%^%^BLUE%^can be faintly seen. A slight breeze flows along the trail.%^RESET%^");
    set_items( ([ "butterflies": "%^BOLD%^%^BLUE%^There are %^MAGENTA%^bu%^RESET%^%^MAGENTA%^tt%^BOLD%^%^YELLOW%^er%^GREEN%^fl%^RED%^ie%^WHITE%^s %^BLUE%^of all colors and shapes flowing in and out of the area.%^RESET%^", "chest": "%^BOLD%^%^BLUE%^The %^WHITE%^ice chest %^BLUE%^is open and fish heads can be seen staring up at the sky.%^RESET%^" ]) );
    set_exits( ([ "north" : SKYROOM "wanderer_hall2", "south" : SKYROOM "rs_5" ]) );
    add_pre_exit_function("north", "go_north");
}
void init() {
    ::init();
    add_action("lookin", "peer");
}
int go_north() {
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
int lookin(string str) {
    string *disallow;
    disallow = ({ "north", "n" });
    if(member_array(str, disallow) == -1)
	return 0;
    else {
	message("info", "This hall is closed off from view.", this_player(),
	);
	return 1;
    }
    message("bug", "ERROR: This shouldn't happen!", this_player(), );
    return 1;
}
