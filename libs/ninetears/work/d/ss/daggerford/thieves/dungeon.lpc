/* source file for room -- Dungeon */
#include "path.h"
  /* macros */
#define SHRT_DESC "Dungeon"
#define LONG_DESC \
  "The stagnant air, encroaching walls, and faltering light are clear "+\
  "indications that this is the dungeon of the tower.  A lamentable chorus "+\
  "penetrates the deeper corridors that lead to the forgotten occupants of "+\
  "the isolated vaults of suffering.  The walls of the interrogation "+\
  "chamber are adorned with the accoutrements of an unpleasant purpose.  "+\
  "A place such as this always brings a nervous trepidation to all "+\
  "those in precarious situations.\n"
#define LIGHT_LEVEL 20
#define ZONE "guild"

  /* inheritance */
inherit "/std/room";

void setup()
{
          /* short description */
  set_short(SHRT_DESC);
          /* long description */
  set_long(LONG_DESC);
          /* light level */
  set_light(LIGHT_LEVEL);

          /* signs */
  add_sign("This sign is made of wood.\n", "This statement is false.\n", 0);
          /* items */
  add_item("accoutrements", "These horrid devices look more like forms of "+
    "execution than tools of torture.  You hastily drop the item when "+
    "picture its merciless grip on yourself.\n");
          /* exits */
  add_exit("up", ROOM + "guild_hall", "stair");
          /* zone */
  set_zone(ZONE);
}

