#include "../DEFS.h"

#include <door_defs.h>
#include <room_defs.h>
#include <city_name.h>

inherit TRISTEZA_ROOM_C;
#include <criminal.h>

object ob;

void
create_room()
{
    int foobar;
    ::create_room();
    set_short("Court Hall");
    set_long("This is the Court Hall of the city of " CITY_NAME ". It\
 was built a thousand years ago, at the end of the rule of the Thief-Mages.\
 Last of them were the first criminals to be sentenced in this place. In this\
 room you can\"accuse <name> for <crime>\". If your accusation was true,\
 you get a nice reward in gold. Wrong accusations are treason. Trust no one.\
 Traitors are everywhere.");
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set(PREVENT_TELEPORT);
    set_commands(([
	"accuse" : "accuse_cmd"
      ]));

    (ob = clone_object(DOOR_FILE))->add_door(
      "Wow, what a great door." ,
      "north", CITY_DIR+"lobby", "huge iron",
      "judges_key", 0, 0, 1, 200,
      "That is a lock of finest quality."
    );
    if (!foobar) {
	foobar = 1;
	(CITY_DIR+"lobby")->load_me_now();
	foobar = 0;
    }

    add_monster(NPC_DIR + "judge", "High Judge arrives.", 1);
    add_monster(NPC_DIR + "guard", "A cityguard arrives.", 1);
    add_monster(NPC_DIR + "guard", "A cityguard arrives.", 1);
    add_monster(NPC_DIR + "guard_sergeant", "A guard sergeant arrives.", 1);
}

void
extra_add_monster(object ob)
{
    if (ob)
	ob->set_wander(0);
}

status
accuse_cmd(string arg)
{
    string who, what;
    int cr;

    if (!arg || sscanf(lower_case(arg), "%s for %s", who, what) != 2)
	return notify_fail(sprintf("%-=75s\n",
	    "Try: \"accuse <name> for <crime>\", where crime is one of: " +
	    implode((string *)CRIME_D->query_crime_names(), ", ", " or ") + ".")), 0;

    if (!present("judge", this_object())) {
	this_player() -> tell_me("Judge is not present.");
	return 1;
    }

    this_player()->tell_me("Ok.");

    /* TODO: Do it! */

    return 1;
}
