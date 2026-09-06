#include "../DEFS.h"
#include <areas.h>

#include <generic_items.h>

inherit TRISTEZA_ROOM_C;

// Undef this to remove emote //Graah

#define EMOTE_ROOM
#define NATURE	nature()

#ifdef EMOTE_ROOM
inherit "/basic/misc/emote";
#endif

void
create_room()
{
    ::create_room();
    add_permanent(GENERIC_TRASHCAN);
    add_permanent(GENERIC_BENCH);
#ifdef EMOTE_ROOM
    set_short("Market Square (Emote plaza)");
#else
    set_short("Market Square");
#endif
    set_long("Southwestern part of the market square. This is the place\
 where the Adventurers tend to rest and torment each other with awful stories\
 of their \"glorious adventures\". You hear merry voices from the entrances\
 to south and southwest."
#ifdef EMOTE_ROOM
      +"\nWarning! Emote command can be used here! ('help emote' for more info.)."
#endif
    );
    set_exits(([
	"north" :	CITY_DIR + "S6_7",
	"northeast" :	CITY_DIR + "S7_7",
	"east"	:	CITY_DIR + "S7_8",
	"south"	:	PUB,
	"southwest" :	LORD_PUB,
      ]));
    set_commands(([
	"south"	: "south",
	"southwest" : "southwest",
	"awe"	: "awe",
#ifdef EMOTE_ROOM
	"emote"	: "emote_cmd",
	"help"	: "help"
      ]));
#endif
    add_monster(AREA_TRISTEZA+"npc/leper",
      "Leper arrives and cries: Unclean!", 1);
}

status
south()
{
    int hour;
    if ((hour = (int) NATURE->query_24_hour()) >= 4 && hour < 8) {
	this_player()->tell_me("The pub is closed. A sign on the\
 door says: CLOSED 4.00 AM - 8.00 AM.");
	return 1;
    }
    return 0;
}

status
southwest()
{
    if (interactive(this_player()) && !this_player()->query_lord() 
      && !this_player()->query_coder_level()
      || !interactive(this_player()) && !this_player()->query_ctrl())
    {
	this_player()->tell_me("The largest guardsman you've ever seen\
 blocks the way. He looks scornly at you and hisses: Lords only, you fool.");
	return 1;
    }
    return 0;
}

status
help(string str)
{
    if (!str || lower_case(str) != "emote") return 0;
    this_player()->tell_me(
      "Command: emote      (Local command - this room only)\n\
Arguments: message\n\
Generates a neat feeling which you can design yourself.\n\
For example, you (player Foobar), type:\n\
'emote scans the horizon with his bloodshot eyes.'\n\
And the other players in this room see:\n\
'Foobar scans the horizon with his bloodshot eyes.'\n\n\
Beware of those who emote 'gives you 10000 gold'... :-)");
    return 1;
}

status
awe()
{
    if ((int) this_player()->query_level() > 24) return 0;
    this_player()->tell_me("You are not powerful enough to scare anyone here.");
    return 1;
}
