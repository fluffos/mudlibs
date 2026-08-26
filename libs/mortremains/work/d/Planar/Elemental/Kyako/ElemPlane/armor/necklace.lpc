#include <mudlib.h>
#include "plane.h"

inherit ARMOR;

void create () {
   set ("id", ({ "necklace" , "water", "water necklace" }) );
   set ("short",  "water necklace" );
   set ("long", @EndText
This is a crystalline necklace.
It seems to be made out of pure water, yet
It stays uniform, and does not collapse.
Every once in a while,
you see some characters form in the water.
The best you can make out is (* means you can't make it out):
a***v*t*
EndText
 );
   set_armor_type("amulet");
   set ("mass", -1);
   set ("bulk", -1);
   set ("prevent_sell", 1);
}

void init() {
  add_action("activate", "activate");
}

int activate() {
  object elemental;
  elemental = present("master water elemental", environment(TP));
  if (!elemental) {
    write("You can't activate this here.");
    return 0;
  } else {
    write("You feel that the force preventing you from attacking\n");
    write("the elemental has been lifted.\n");
    write("The energy supporting the necklace has been expended,\n");
    write("and the necklace falls apart in your hands.\n");
    elemental -> set("no_attack", 0);
    ::remove();
    return 1;
  }
  return 1;
}
