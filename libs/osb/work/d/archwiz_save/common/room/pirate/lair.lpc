#include "path.h"
#include <moving.h>
#include <combat.h>
#include <rooms.h>
#include <properties.h>

inherit "/std/room";

int potion;

hay() {
  if (!this_player()) return 0;
  if (potion) {
    write("You examine the hay, but you see nothing special about it.\n");
    return "";
    }
  write("You discover a well known sort of potion: A healing potion! "
"Eagerly you drink it.\nThat feels good!\n");
  show(this_player()->QueryName()+" finds a potion in the hay.\n");
  this_player()->Heal(40);
  potion=1;
  return "";
}

int down() {
  if (!this_player()) return 0;
  if (present("thisdragon",this_object())) {
    write("The dragon sits on the hole.\n");
    return 1;
    }
  this_player()->move(PIRATE("sew1"),M_GO,"down");
  return 1;
}

create() {
  ::create();
  SetIntShort("dragon lair");
  SetIntLong(
"You're in the dragon's lair which is apparently the living room "
"of a very nice dragon. A pile of hay lies in a corner of the room.\n");
  SetIndoors(1);
  SetBright(1);
  AddDetail(({"hay","pile","pile of hay"}),#'hay);
  AddDetail(({"lair","dragon's lair"}),QueryIntLong());
  AddDetail(({"ground","floor"}),
"There seems to be a hole in the floor where the dragon sits on.\n");
  AddDetail(({"walls","ceiling","wall"}),
"You see nothing special.\n");
  AddExit("down",#'down);
  AddItem("/std/npc",REFRESH_HOME,
    ([P_NAME:"dragon",
      P_IDS:({"dragon","thisdragon"}),
      P_RACE:"dragon",
      P_SHORT:"dungeonmaster's red dragon",
      P_LONG:"This is a huge red dragon.\n",
      P_LEVEL:30,
      P_HP:500,
      P_AC:10,
      P_SIZE:PSIZE_LARGE,
      P_XP:720000,
      P_ALIGN:-300,
      P_AGGRESSIVE:0,
      P_HANDS:({ ({"its claws",0,19}),({"firebreathing",0,25}) }),
      P_ITEMS_REFRESH:({
	({"/std/armour",REFRESH_REMOVE|REFRESH_FUNC,
	  ([P_SHORT:"mystic ring",
	    P_LONG:"The ring seems to emit a magic defense shield.\n",
	    P_AC:1,
	    P_SIZE:PSIZE_LARGE,
	    P_RESET_QUALITY: 99,
	    P_ARMOUR_TYPE:AT_RING,
	    P_VALUE:1500,
	    P_WEIGHT:30,
	    P_MAGIC:1,
	    P_LIGHT:2,
	    P_IDS:({"ring"}),
	    P_ADS:({"mystic","a"})]),"wearme",0}),
	({"/std/weapon",REFRESH_REMOVE,
	  ([P_SHORT:"diamond blade",
	    P_LONG:"It shines bright and looks very sharp.\n",
	    P_WC:17,
	    P_NUMBER_HANDS:2,
	    P_SIZE:PSIZE_LARGE,
	    P_RESET_QUALITY:90,
	    P_WEAPON_TYPE:WT_SWORD,
	    P_DAM_TYPE:DT_SLASH,
	    P_WEIGHT:20000,
	    P_VALUE:10000,
	    P_IDS:({"blade","sword"}),
	    P_ADS:({"diamond"})]),0}),
        /* This bullet was for a Western miniquest. 
	 * See also .../mx.c and .../nearsea.c 
	 */
	({"/std/thing",REFRESH_REMOVE,
	  ([P_SHORT:"a bullet",
	    P_LONG:"This is a deadly looking metal bullet. An inscription "
"is made on it.\n",
	    P_VALUE:2,
	    P_WEIGHT:20,
	    P_IDS:({"bullet"}),
	    P_ADS:({"metal","small","deadly looking"}),
	    P_READ_MSG:"1879\n"]),0}) })
      ]));
}

reset() {
  ::reset();
  potion=0;
}
