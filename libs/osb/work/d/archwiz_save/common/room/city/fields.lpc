#include  "path.h"
inherit "std/room";

create() {
  ::create();
  SetIntShort("Intersection between cornfields");
  SetIntLong(
"This is an intersection, where a west road joins the north-south "
"road. Rich cornfields are all around. To the northwest and southwest you "
"can see Nightfall City, the capital of this world. You have a nice view "
"on the biggest town of this world. To the east you see a huge castle.\n");
    
  /* The details is in fact the old default description of a 2.4.5 wizard
   * castle.
   */
  AddDetail(({"castle","huge castle"}),
"This is the Castle of Firestone.\n"
"Firestone is a rather old wizard, but it is an amazing castle. "
"The gates are open.\n");
  AddExit("north", "./woodbridge");
  AddExit("west",  "./farmland");
  AddExit("south", "./field");
  AddExit("east",FIRESTONE("entr"));
  SetIndoors(0);
}
