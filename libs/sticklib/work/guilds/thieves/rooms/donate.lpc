
#include <npc_defs.h>
#include <room.h>
#include <guild.h>
#include "dirs.h"

mixed Store; /* string or object */

void
create_room()
{
#ifdef UIDS
    seteuid(getuid());
#endif
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_INDOORS);
    set(NO_CLEANUP);
    set_short("A rather large blackrock room");
    set_long(
      "You are in a rather large room, the walls of which are hewn of blackrock, \
a material known for it's ability to resist all known forms of magic. \
Sounds in the room are wierdly amplified, and some seem to be diminished, \
while others are increased in volume. There is also a small plaque on \
the wall.");
    set(PREVENT_TELEPORT);
    set_exits(([ "north" : GDIR+"rooms/guard_room" ]));
    Store = GDIR+"rooms/storage_room";
    add_item("plaque", "Small onyx plaque. It contains some writing.");
    add_item("writing","Try reading it.");

    add_command("i",    "inventory_cmd");
    add_command("read", "read_cmd");
    add_command("list", "cmd");
    add_command("borrow",  "cmd");
    add_command("donate", "cmd");
    add_monster( ({ ({ "set_name", "thief-mage" }),
	({ "set_level", 25 }),
	({ "set_hp", 2500 }),
	({ "set_id", ({ "thief-mage", "keeper", "thief", "mage" }) }),
	({ "set", LIV_UNDEAD })
	,({ "set_short", "A shadowy thief-mage" }),
	({ "set_long",
	  "You are looking at the last known living thief-mage - "
	  "a man so fearful of the being exterminated that he has "
	  "made an alliance with the thieves guild for sanctuary. "
	  "In return, he created this blackrock room and promised "
	  "to retain equipment for the thieves guild in some unknown "
	  "plane. The man is shrouded in a cloak, and none of his "
	  "physical features are visible. He is rather tall and lean, "
	  "from what you can see. " })
	,
      }), "Thief-mage arrives. ", 1);

}

/* Redefine when needed */

int
inventory_cmd(string str)
{
    object ob, *keeped;
    string name, *text;
    int i;


    if (str)
	ob = present(str, this_player());

    if (!(keeped = (object *) this_player()->query_keep_items()))
	keeped = ({ });

    ob = first_inventory( (ob ? ob : this_player()) );
    text = ({ "Item", "~~~~" });
    while(ob) {
	i = (member(keeped, ob) >= 0);
	if (name = (string)ob->short()) {
	    name += ".";
	    if (i) text += ({ sprintf("%-32s (keeping)", name) });
	    else text += ({ sprintf("%s", name) });
	}
	ob = next_inventory(ob);
    }
    this_player()->more(text);
    return 1;
}


int
cmd(string item)
{
    /* added thief check here ++skarda */

    if(!present("thief-mage")||(string)this_player()->query_guild()!="thief") {
	this_player()->tell_me("The thief-mage is not here to help you. ");
	return 1;
    }
    return (int)call_other(Store, query_verb()+"_item",item);
}


int
read_cmd(string arg)
{
    if (arg == "plaque" || arg == "writing") {
	this_player()->tell_me(
	  "There are following commands:\n\
\tlist [what]              -  list items [called what]. 'list weapons'\n\
\t                            and 'list armours' are special cases\n\
\tdonate <what>              -  donate items you are carrying\n\
\tdonate <what> from <where> -  donate items from a container\n\
\tborrow <what>               -  borrow an item\n\
Some examples:\n\
\t'i bag', 'list amulets', 'donate all from bag', 'donate bottle 2 from bag',\
'borrow short sword'"
	);
	return 1;
    }
}
