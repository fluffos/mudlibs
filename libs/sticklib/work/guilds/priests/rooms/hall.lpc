#include "priest_room.h"

#define GUILD_ENTRANCE PRIEST_ROOM_DIR "entrance"
#define GARDEN_ENTRY PRIEST_ROOM_DIR "garden_entry"
// garden_entry will handle closing the gates on the gardens' side too

int gates_shut;

string query_gate_desc() {
    if(gates_shut) return
	"The heavy brass gates, which were used to protect the \
cathedral's wealth in times of war, are shut. You see a magical \
shimmering around them.";
    else return
	"There are heavy brass gates here, thrown wide open.";
}

void create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);
    set(IN_CITY);
    set_short("The main hall of the cathedral");
    set_long(
      "You stand in awe in the main hall of " LONG_GOD_NAME "'s cathedral. "
      "The ceiling here is seemingly hundreds of feet tall.   Huge arches "
      "support the heavy gray and black granite that makes up the entirety "
      "of this structure.  There are deep recesses in the walls, where "
      "there are stained glass artworks.  To the north, you see the inner "
      "sanctum of the cathedral. There are heavy brass gates here, that shimmer "
      "with some sort of holy aura. "
    );
    set_exits(([
	"south" : PRIEST_ROOM_DIR "entrance",
	"west" : PRIEST_ROOM_DIR "confess",
	"east" : PRIEST_ROOM_DIR "registration",
	"north" : PRIEST_ROOM_DIR "hallway"
      ]));
    add_item("gates", #'query_gate_desc);
    add_item("ceiling", "The ceiling here is almost a hundred and fifty feet "
      "tall. The graceful arches and vaults are patterned over with a "
      "strangely hypnotic repeating pattern of gray, black, and white.");
    add_item("arches","The skill in making arches of this magnitude is "
      "largely lost from the world in this age.");
    add_item("granite", "At first you thought that there was only the colors "
      "of gray and black in this marble, but a fine white vein runs through "
      "it, accenting and heightening it's beauty. ");
    add_item("recesses", "These dark recesses hide many things.");
    add_item(({"artwork", "glass", "artworks"}), "Some of these stained glass "
      "works depict the Fall of Saint Skerret, the Boredom of Saint Kelgath, "
      "and the search of Sirrus the Lion.");
    add_item("aura", "The magical aura around these gates seems to make them "
      "virutally unbreakable.");
    add_command("south", "south_cmd");
    add_monster(PRIEST_MON_DIR "priest","Priest arrives.",1);
}

int south_cmd() { 
    if(gates_shut) {
	this_player()->tell_me("The gates are shut. You cannot go that way.");
	return 1;
    }
    return 0;
}

int query_shut() { 
    return gates_shut; 
}

void shut_gates(int shut_em) {
    if(gates_shut == shut_em) return;

    GUILD_ENTRANCE->shut_gates(shut_em);
    GARDEN_ENTRY->shut_gates(shut_em);
    gates_shut = shut_em;
    if(shut_em) tell_here("The gates swing shut with a bang!");
    else tell_here("The gates creak open.");
}

