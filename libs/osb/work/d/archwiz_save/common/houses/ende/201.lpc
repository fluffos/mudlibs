/* A room in the house of ende */

#include <rooms.h>
inherit "/p/houses/common/room/room";

create() {
  ::create();
  SetIntShort("Garden, lawn.");
  SetIntLong("If you want to lay down a bit in the sun this is the right place for it. It's\nincredibly hot here, but you can cool yourself in the pool to the north after\nyour sunbath.\n");
  AddExit("north","/d/archwiz/common/houses/ende/101");
  AddItem("/obj/sunglasses",REFRESH_NONE);
}
