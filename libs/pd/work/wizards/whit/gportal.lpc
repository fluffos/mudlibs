//  Created by Whit

#include <std.h>
#include <citrin.h>
#define VALID_GUILDS ({ "aod", \
                        "scorpio", \
                        "darksoul", \
                        "vorticon", \
                        "illuminati", \
                        "dw", \
                        "acheron", \
                        "chosen", \
                        "forsaken", \
                        "unholy", })

inherit OBJECT;

void create() {
    ::create();
    set_name("guild portal");
    set_long("This will take you to any guild.  Just type <portal "
      "to [guild]>");
    set_short("guild portal");
    set_id(({"portal","guild portal"}));
    set_prevent_get("You cannot take a portal.");
}

void init() {
    ::init();
    add_action("portal","portal");
}

int portal(string str) {
    string to;
    if(sscanf(str, "to %s", to) != 1) return 
	notify_fail("Syntax: <portal to [guild]>\n");
    if(to != "meeting" && to != "vote" &&
      member_array(lower_case(to), VALID_GUILDS) == -1) return 
	notify_fail("Invalid guild.\n");
    if(lower_case(to) == "aod") 
	this_player()->move_player("/d/guilds/AoD/hall");
    else
    if(lower_case(to) == "meeting") 
	this_player()->move_player("/d/guilds/meeting");
    else
    if(lower_case(to) == "vote") 
	this_player()->move_player("/d/guilds/vote");
    else
    if(lower_case(to) == "illuminati")
	this_player()->move_player("/d/guilds/illuminati/new/board");
    else
	this_player()->move_player("/d/guilds/"+lower_case(to)+"/hall");
    return 1;
}

