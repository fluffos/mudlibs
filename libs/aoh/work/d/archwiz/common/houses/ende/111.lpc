/* A room in the house of ende */

#include <rooms.h>
inherit "/p/houses/common/room/room";

create() {
  ::create();
  SetIntShort("Hallway");
  SetIntLong("Through the door at the eastern end of this hallway you can catch a glimpse\ninto the garden, while the doors to the north and south lead into a kitchen\nand a nice living room.\n");
  AddExit("north","/d/archwiz/common/houses/ende/011");
  AddExit("south","/d/archwiz/common/houses/ende/211");
  AddExit("west","/d/archwiz/common/houses/ende/101");
  AddExit("east","/d/archwiz/common/houses/ende/121");
}
