
#include "defs.h"

inherit TERRAIN_OUTSIDE;

void setup() {
   set_terrain("tutorial_desert");
   set_short("outside a tent");

   set_long("This is just outside the front flap of a canvas tent, set "
       "in the middle of a huge desert waste.  Nothing but sand as far "
       "as the eye can see.\n");

   add_item("sand", "It's sand.  There isn't much to say about it.");
   add_item("tent", "This is a plain, white canvas tent, that reflects the "
       "harsh glare of the sun harmlessly away from its occupants.");

   add_exit("tent", TERRAINTUTOR "foyer", "corridor");

   add_property( "climate", ({ 40, -100, -100 }) );

} /* setup() */
