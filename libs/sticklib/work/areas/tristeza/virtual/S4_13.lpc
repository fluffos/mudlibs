#include "../DEFS.h"

#ifndef _AREAS_H
#include <areas.h>
#endif

#include <guild.h>
inherit TRISTEZA_ROOM_C;

#include <gender.h>

string *ld_id_list;

void
create_room()
{
    ::create_room();
    ld_id_list = ({ });
    set_short("Godshire");
    set_long("You are on the Godshire which goes east \
and west. The Dragon Street goes north from here. There is \
a large shining white building to the south.");
    set_exits(([
	"north"   : CITY_DIR + "S4_12",
	"west"	: CITY_DIR + "S3_13",
	"east"	: CITY_DIR + "S5_13",
#ifdef GN_HEALER
	"south"	: GUILD_PATH_HEALER "room/entry",
#endif
      ]));
    add_command("south", "south_cmd");

    add_item(({"gnome","gnomes"}),
      "Gnomes are totally invulnerable to all attacks. They are building \
this world, you know! They don't have time for mortal affairs.");

    add_item(({"building","south","white building"}),
      "It is a tall, brightly white building made of stone. You notice \
hundreds of gnomes hammering, sawing, masoning and building the \
place in a great hurry.");
}

status
south_cmd()
{
    if (this_player() &&
      (this_player()->id("city_guard") ||
	this_player()->id("ebonflow") ||
	this_player()->id("ebonspawn") ||
	this_player()->id("leper") ||
	this_player()->id("janitor")))
	return 1;

    return 0;
}
