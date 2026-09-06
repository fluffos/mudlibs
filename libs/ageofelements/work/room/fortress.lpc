#include <global.h>

inherit LIB_ROOM;

void
create_room()
{
    set_lumens(1);

    set_brief("An Orc Fortress");

    set_description(
	"This is the local strong point of the orcs. There is an entrance "
	"to a small room to the north."
      );

    add_exit("south", "/room/orc_vall");

    add_command("north", "north");

    mixed *weapon_data = ({
	([
	    "name": "knife"
	    , "class": 5
	    , "value": 8
	    , "weight": 1
	    , "alt_name": "knife"
	])
	, ([
	    "name": "curved knife"
	    , "class": 7
	    , "value": 15
	    , "weight": 1
	    , "alt_name": "knife"
	])
	, ([
	    "name": "hand axe"
	    , "class": 9
	    , "value": 25
	    , "weight": 2
	    , "alt_name": "axe"
	])
      });

    string *orc_adjectives = ({
	"dirty"
	, "smelly"
	, "stinky"
	, "stupid"
	, "tall"
	, "short"
	, "fat"
	, "thin"
      });

    for (int i = 0; i < 8; i++) {
	mapping selected_weapon = copy(
	    weapon_data[random(sizeof(weapon_data))]
	  );

	mixed *weapon_info = ({ "/obj/weapon"
	    , ({ "set_name", selected_weapon["name"] })
	    , ({ "set_class", selected_weapon["class"] })
	    , ({ "set_value", selected_weapon["value"] })
	    , ({ "set_weight", selected_weapon["weight"] })
	    , ({ "set_alt_name", selected_weapon["alt_name"] })
	  });

	string orc_adjective = orc_adjectives[random(sizeof(orc_adjectives))];

	mixed *orc_info = ({ "/obj/monster"
	    , ({ "set_name", sprintf("%s orc", orc_adjective) })
	    , ({ "set_alias", "orc" })
	    , ({ "set_race", "orc" })
	    , ({ "set_short", sprintf("%s orc", capitalize(orc_adjective)) })
	    , ({ "set_level", (random(2) + 1) })
	    , ({ "set_hp", 30 })
	    , ({ "set_ep", 1014 })
	    , ({ "set_al", -60 })
	    , ({ "set_ac", 0 })
	    , ({ "set_aggressive", 1 })
	    , ({ "load_a_chat", "room/orc_vall"->get_chats() })
	    , ({ "add_transient_object", weapon_info })
	  });

	add_transient_object(orc_info, "Orc arrives.");
    }
}

int
north()
{
    object orc;

    if ((orc = present("orc")) && orc->is_npc()) {
	write("An orc bars your way.\n");
	return 1;
    }

    this_player()->move_player("north#room/orc_treasure");
    return 1;
}
