// This is the server file where you set up how all of your rooms are going to look.  follow this syntax, they should be self-explanitory.  set_how_long() should be set to three if you have enough sentances set...  if your descriptions are ending up too short, make it a larger number.  the set_reset_list are the monsters that will pop up during reset randomly.  try to make your mobs with a random gender to increase variety.

#include <std.h>

inherit VIRTUALSERVER;

void create() {
  ::create();
  set_how_long(3);
  set_day_sentances( ({
      "This is the first sentance.",
      "This is the second sentance.",
      "This is the third sentance."
  }) );
  set_night_sentances( ({
      "This is the first night sentance.",
      "This is the second night sentance.",
      "This is the third night sentance."
  }) );
  set_item_list( ([
      "item1" : "This is item 1.",
      ({"item2", "bah"}) : "This is item 2."
  ]) );
  set_smell("This smells funky.");
  set_listen("This sounds quiet.");
  set_reset_list( ({
      "/wizards/nightshade/mob/fox", "/wizards/nightshade/mob/dog", "/wizards/nightshade/mob/cat"
  }) );
  set_properties( ([ "light" : 1,
                     "indoors" : 1,
                     "no teleport" : 1
                   ]) );
  set_short("ROOM!");
}
