#include "priest_room.h"

#include <guild.h>

void create_room()
{
    set_light(LT_LIGHTS);
    set(ROOM_GUILD);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set(IN_CITY);
    set_short("The hallway before the altar of Boccob");
    set_long("You stand in awe before the altar of Boccob.  The altar is made \
entirely of mithril, formed and coloured with skills long lost in this age. \
Priceless hangings cover the walls and tables of this place.  There is an \
oculous here, which streams bright light onto the altar, day or night.");
    set_exits(([
	"south" : PRIEST_ROOM_DIR "hall",
	"north" : PRIEST_ROOM_DIR "guild_room",
	"northwest" : PRIEST_ROOM_DIR "nwpassage",
	"northeast" : PRIEST_ROOM_DIR "nepassage"
      ]));
    add_monster(PRIEST_MON_DIR "cheng",
      "Cheng salutes you as he walks in.",1);
    add_monster(PRIEST_MON_DIR "outer_guard",
      "Templar salutes you.",1);
    add_monster(PRIEST_MON_DIR "outer_guard",
      "Templar returns to his post.",1);
    add_command("north", "north_cmd");
}

status
north_cmd(){
    object blocker,me;

    me = this_player();
    blocker = present("templar",this_object());

    if(blocker && (!this_player()->query_coder_level())){
	if((string)me->query_guild() == GN_PRIEST) return 0;
	if(GUEST_D->query_guest(me->query_real_name())) return 0;
	me->tell_me("Templar says: Only members of the \
Holy Order may enter the Inner Sanctum.");
	return 1;
    }
    return 0;
}

