
#include <std.h>
#include <h2k7.h>

inherit VIRTUALSERVER;

void create() {
  ::create();
  set_properties( ([ "light" : 1, "night light" : 1,
    "town": 1, "plain": 1, "indoors": 0 ]) );
  set_short("a pumpkin patch");
  set_how_long(3);
  set_mob_cap(2);
  set_smell("The scent of hay mingles with a slight pumpkin smell.");
  set_reset_list( ({
    H2K7MOBS"crow", H2K7MOBS"raven",
    H2K7MOBS"crow", H2K7MOBS"raven",
    H2K7MOBS"crow", H2K7MOBS"raven",
    H2K7MOBS"scarecrow", H2K7MOBS"jackolantern", H2K7MOBS"ghost"
  }) );
  set_day_sentances( ({
    "Hay bales are arranged in rows all around.",
    "Pumpkins sit on some hay bales.",
    "The ground underfoot is pebbly with lots of hay sprinkled over it.",
    "A cool breeze blows through.",
    "A few pumpkins are stacked on the ground.",
    "A small animal scurries away behind a bale of hay.",
    "Several green and yellow gourds have been set around as decoration."
  }) );
  set_item_list( ([
    ({ "hay", "bales", "hay bales", "bale of hay" }) :
      "Squarish blocks of hay with rope tied around them.",
    "pumpkins" : "Large, orange, squash-like vegetables.",
    "ground" : "It is rough and full of pebbles.",
    "animal" : "It's gone already.",
    "gourds" : "Long yellows and greens that make the area "
      "more festive."
  ]) );
}

