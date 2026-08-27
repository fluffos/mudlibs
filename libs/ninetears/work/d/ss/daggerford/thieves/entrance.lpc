/* source file -- Entrance to guild */
#include "path.h"

inherit "/std/room";

void setup()
{
  set_short("Entrance");
  set_long("Within the dimness and silence of this vestibule, an urgent "+
    "feeling of aprehension pierces the very core of your soul.  Across "+
    "the chamber from the way, a gigantic statue stands astride an oval "+
  "portal "+
    "to the inner chambers.  The walls appear as molten rock and are "+
    "scored with undecipherable sigils and glyphs.  The ceiling drips of "+ 
  "icicles of stone, seemingly in mockery of the comfort from "+
    "the world above.\n");
  set_light(20);
  set_zone("guild");

  add_item( ({ "sigils", "sigil", "glyphs", "glyph" }),
    "Although you can't understand the exact "+
    "translation, their meaning is evident: they are symbols of "+
    "warning.");
  add_item("statue", "The statue stands sixteen feet tall and represents "+
    "a darksome thief.  He is cloaked and masked.\n");
  add_item( ({"portal", "door"}), "There are multi-colored sparks moving "+
    "within the glossy black mineral and not without purpose.\n");

  add_exit("up", "/d/ss/daggerford/thieves/thief", "ladder");
  add_exit("in", "/w/vhaeraun/nexus/guild/hall1", "door");

}

