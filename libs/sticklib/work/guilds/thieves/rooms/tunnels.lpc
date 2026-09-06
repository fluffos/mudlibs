/* Secret Tunnels of the Thieves */
#include <areas.h>
#include <room.h>
#include <door_defs.h>
#include <guild.h>
#include <areas.h>

#include "dirs.h"

object *guard;
string alarm;

void reset_room()
{
    int i, lvl;

    alarm ="";

    if (!guard || sizeof(guard) < 5)
	guard = ({ 0, 0, 0, 0, 0, 0 });

    if (present("lesser_thief_guard", this_object()))
	return;

    for (i = 0; i < 4; i++)
    {
	guard[i] = clone_object(GDIR + "npc/treasure_guard");
	guard[i]->move_player("ff", this_object());
    }
}

void create_room()
{
    object ob;

    set_short("Secret Tunnels");
    set_long("From this place many one-way secret tunnels give the "+
      "thieves a quick access to various places near Tristeza.");
    set_light_level(LT_LIGHTS);
    set(YES_PK);
    set(PREVENT_TELEPORT_TO);
    // To prevent thieves from abusing these guards to cause PK. -+ Doomdark +-
    set(ROOM_GUILD);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_TELEPORT);

    set_exits(([
	"up"          : GDIR + "rooms/guild",
	"southlands"  : "/areas/landover/trollv/strabo/foot5",
	//"down"        : AREA_SEWERS+"lvl2/tube10",
	//"inn"         : AREA_FROBOZZ_INN+"inn/lobby",
	"clearing"    : AREA_WEST+"forest/clearing",
	//"finnclub"    : "/areas/tristeza/finnclub/foyer",
	"church"      : "/room/church",
	//"orctown"     : AREA_ORCTOWN + "lvl1/round_cave",
	"well"        : AREA_TRISTEZA+"rooms/well",
	"herbs"       : "/areas/islands/herbs/shop",
	// "bigtree"     : AREA_WEST+"plains/big_tree",
	// "mountain"    : AREA_WEST+"forest/mountain_top",
	// "shop"        : AREA_TRISTEZA+"shops/shop",
      ]));

    if ((ob = clone_object(DOOR_FILE)))
    {
	ob->add_door( ({
	    "It is a heavy iron door.",
	    "It is a heavy iron door." }),
	  "west", GDIR + "rooms/trap", "fine steel",
	  "thief_key", 0, 0, 1, 60,
	  "It is quite a complex lock, but not impossible.");
    }

    reset_room();
}

void init_room()
{
    int i;

    for (i = 0; i < 5; i++)
	if (guard[i]  &&  !guard[i]->query_dead()  &&
	  !guard[i]->query_attacker()  &&
	  !present(guard[i], this_object()))
	    guard[i]->move_player("X#" + GDIR2 + "rooms/tunnels");

    add_action("block", "up");
    add_action("block", "down");
    add_action("block", "inn");
    add_action("block", "clearing");
    add_action("block", "finnclub");
    add_action("block", "orctown");
    add_action("block", "bigtree");
    add_action("block", "mountain");
    add_action("block", "well");
    add_action("block", "southlands");
    add_action("block", "herbs");
    add_action("block", "shop");
    add_action("block", "church");
}

status block()
{
    object ob;

    if ((ob = present("lesser_thief_guard"))  &&
      (string)this_player()->query_guild() != GN_THIEF  &&
      !this_player()->query_coder_level())
    {
	this_player()->tell_me((string)ob->query_name() +
	  " blocks your way!");

	/* Shout on channel */
	if (alarm != ((string)this_player()->query_real_name()))
	{
	    alarm = (string)this_player()->query_real_name();

	    call_other(GDIR + "rooms/guild", "cant_msg",
	      (string)ob->query_name(),
	      "Alarm! Intruder " + (string)this_player()->query_name() +
	      " at tunnels!");
	}

	return 1;
    }

    return 0;
}
