#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set("short", "Last Saints");
    set("long", "%^BOLD%^%^WHITE%^The fourth floor of the Last Saints holds the halls for its members. The Clergy, Mage, fighter, Rogue and Wanderer halls go off into different directions. You can hear different sounds coming from each hall.%^RESET%^");
    set_exits( ([ "down" : GUILDROOM+"level3_main", "southwest" : GUILDROOM+"rogue_hall", "west" : GUILDROOM+"clergy_hall", "east" : GUILDROOM+"mage_hall", "southeast" : GUILDROOM+"fighter_hall", "north" : GUILDROOM+"wanderer_hall", "up" : GUILDROOM+"level5_main" ]) );
}
void init() {
    ::init();
    add_action("lookin", "peer");
    add_action("enterin", ({ "north", "southwest", "southeast", "east",
	"west"}));
}
int enterin(string str) {
    string hall, classn;
    if(str && str != "")
	return 0;
    hall = query_verb();
    switch(hall) {
    case "west"       : classn = "clergy"; break;
    case "southwest"  : classn = "rogue"; break;
    case "north"      : classn = "wanderer"; break;
    case "southeast"  : classn = "fighter"; break;
    case "east"       : classn = "mage"; break;
    default           : classn = "fail"; break;
    }
    if(classn != this_player()->query_class() && !wizardp(this_player())) {
	message("info", "As a "+this_player()->query_class()+" you may not enter a hall of the "+classn+".", this_player(), );
	return 1;
    }
    else {
	message("info", "You are admitted into the Last Saints hall of the "+classn+".\n", this_player(), );
	return 0;
    }
    message("bug", "ERROR: This shouldn't happen!", this_player(), );

    return 1;
}

int lookin(string str) {
    string *disallow;
    disallow = ({ "north", "southwest", "southeast", "east", "west", "n", "sw", "se", "e", "w" });
    if(member_array(str, disallow) == -1)
	return 0;
    else {
	message("info", "The halls are closed off from view.", this_player(), );
	return 1;
    }
    message("bug", "ERROR: This shouldn't happen!", this_player(), );
    return 1;
}
