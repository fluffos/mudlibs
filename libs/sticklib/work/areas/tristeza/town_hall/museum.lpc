#include <room.h>
#include <mud_name.h>

#include "DEFS.h"

void
create_room()
{
    set(NO_PK);
    set(IN_CITY);
    set_outdoors(WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set_short("Museum of "+MUD_NAME);
    set_long("The museum looks quite empty, you can see lots of show cases\
 to be filled with exotic and interesting items from the past and present. In\
 one corner is a\npedestal.");
    set_items(([
	({ "case", "cases", "show case", "show cases" }) : "Glass show cases to show\
 items and still protect them from a bit too interested viewers. They are empty\
 at the moment.",
	"pedestal" : "It is a wooden pedestal with a brass plaque. A book lies on it.",
	"plaque" : "This book used to be in the adventurer's guild, to guide players\
 into the mud"
      ]));
    set_exits(([
	"northeast"	: THALL_ROOMS "hall"
      ]));
    add_permanent(THALL_OBJ "book_ancient");
}

status
read_cmd(string str)
{
    if(str!="plaque" && str!="brass plaque") return 0;
    this_player()->tell_me(query_long(str, this_player()));
    return 1;
}
