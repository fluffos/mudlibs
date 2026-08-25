inherit "std/room";
#include "path.h"

void setup()
{
    //ef13.c
    set_light(70);
    set_short("Gnarlwood Forest");
    set_long("Gnarlwood Forest\n"
      "The forest thickens here, as oak trees and maples "
      "fill your space and bend as they hit the roof ceiling above.  "
      "Vines of never-opened morning glories wrap around the "
      "trunks, as the blooms rot into foul liquid.  You brush "
      "against a tree, and startle as you feel the bark - instead "
      "of rough and textured, it is smooth and slick, like a reptile's "
      "scales. Something to the west attracts your attention, and you see a giant "
      "weeping willow, as black as the surrounding trees "
      "are white, rise above all else. "
      "Perhaps it weeps for this forest's fate.\n");
    add_item(({"oak","oaks","maple","maples","tree","trees"}),
      "The anemic trees here are larger and older than many of the "
      "trees on the outskirts.  The strong trunks now have kinks "
      "and cricks as the branches meet the ceiling and try to find "
      "a new direction to grow.\n");

    add_item(({"vine","vines","morning glories","bloom","blooms","liquid"}),
      "The morning glories wait for a sign of dew or sunlight to "
      "signal the beginning of a new day.  This sign shall never come.\n");

    add_item(({"willow"}),
      "Wider than twice the length of your outstreched arms, "
      "the willow, although its black bark and leaves make it "
      "ugly and full of death, still is admired by you.\n");
    add_item(({"bark","scales"}),
      "Colorless bark lays atop itself like the scales on a serpent.  "
      "The evil that feed these trees can replicate growth, but it cannot "
      "hide these outwardly signs as the life of the forest mutates.\n");
   add_property("no_undead",1);
    add_exit("south", HERE+"ef10", "path");
    add_exit("east", HERE+"ef1", "path");
   add_clone(NPCS+"bear",1);

}

