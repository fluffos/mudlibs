#include "priest_room.h"

void create_room(){
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);
    set_short("The Nave of the Cathedral");
    set_long("This is the Nave of the mighty Cathedral of Boccob. It is \
the heart of the Holy Order. The rich tapestries and rugs are overwhelming \
to the unaccustomed eye, and the cold marble of the floor is daunting. A \
soaring mohaganey stair wends its way up into the vault as well as sinks into \
the depths. To the northeast, there is a staircase leading down.");

    set_items(([
	({"tapestry", "tapestries"}): "The tapestries are hanged on the walls and \
they make the room colourful. They reperesent events "GOD_NAME" the Allmighty \
has contacted the world, and the Order. There are pictures from the Old, \
Brothers and Sisters from the past.",
	"rugs": "The rugs look soft and they are made of colourful strings in \
patterns comfortable to the eye.",
	"marble": "The marble is smooth and it has no cracks. It looks like the \
floor is made from only one stone, or the joints are concealed by selecting \
carefully the stone so that the veins in the marble continue",
	({"stair", "stairs"}): "It looks massive, The stair has oil lamps placed \
on its side helping you place your feet on the steps. The steps are large and \
made from polished mahoganey. The stair seems to continue endlessly up and \
down to the down to the depths",
	"depths": "The massive stair leads down there. Although you know you are \
going down, the are dones't get nad, and it doesn't feel uncomfortable to \
descend the stairs.",
	"staircase": "It is too far away to the northeast. Go there and look at it \
again",
      ]));

    set_exits(([
	"up" : PRIEST_ROOM_DIR "relaxation",
	"down" : PRIEST_ROOM_DIR "basement",
	"north" : PRIEST_ROOM_DIR "armoury",
	"northwest" : PRIEST_ROOM_DIR "staff_room",
	"northeast" : PRIEST_ROOM_DIR "wine_stairway",
	"west" : PRIEST_ROOM_DIR "quartermasters",
	"east" : PRIEST_ROOM_DIR "artificer",
	"southwest" : PRIEST_ROOM_DIR "alchemy_chamber",
	"southeast" : PRIEST_ROOM_DIR "temp_storage",
	"south" : PRIEST_ROOM_DIR "guild_room"
      ]));

    add_monster(PRIEST_MON_DIR "wandering_guard",
      "Templar returns to duty.",1);
    add_monster(PRIEST_MON_DIR "wandering_guard",
      "Templar comes back from his break.",1);
    add_monster(PRIEST_MON_DIR "wandering_guard",
      "Templar says: Well, I'm back now.",1);
    add_monster(PRIEST_MON_DIR "wandering_guard",
      "Templar says: Our breaks are way too short.",1);
    add_monster(PRIEST_MON_DIR "wandering_guard",
      "Templar says: I'm the new replacement.",1);
    add_monster(PRIEST_MON_DIR "templar",
      "Templar returns to his post.",1);
    add_monster(PRIEST_MON_DIR "templar",
      "Templar salutes you.",1);
    replace_program(ROOM_FILE);
}
