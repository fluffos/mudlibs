#include <std.h>
#include <pastarlon.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
  set_first_sentence("%^BOLD%^%^BLACK%^Dark storm clouds cover the sky.\n %^RESET%^%^BOLD%^The roads of Arlon are made of broken stones.%^RESET%^");
  set_day_sentances( ({
      "Dead insects litter the side of the road.",
      "Dead flowers are planted on the side of the road.",
      "There is a broken lamp post here, made of scratched up steel.",
      "There are a few unbroken stones on the road below.",
      "Dry blood is splattered among the stones, both fresh and old.",
      "Broken shards of glass litter the road, adding to the filth.",
      "Horse manure is scattered on the road from the stable horses.",
      "Rain seems to have cleared away some of the blood from the road here.",
      "Some of the stones underfoot have been faded by sunlight.",
      "Dead grass surrounds the sides of the road.",
      "Weeds stick out along the road, spreading throughout the path.",
      "A dead willow tree provides a home to ravens and crows on the side of the road.",
      "A random smooth stone sits in the place of a broken brick here.",
      
      }) );
  set_night_sentances( ({
      "Dead insects litter the side of the road.",
      "Dead flowers are scattered on the side of the road.",
      "There is a broken lamp post here, made of scratched up steel.",
      "There are a few unbroken stones on the road below.",
      "Dry blood is splattered among the stones, both fresh and old.",
      "Broken shards of glass litter the road, adding to the filth.",
      "Horse manure is scattered on the road from the stable horses.",
      "Rain seems to have cleared away some of the blood from the road here.",
      "Some of the stones underfoot have been faded by sunlight.",
      "Dead grass surrounds the sides of the road.",
      "Weeds stick out along the road, spreading throughout the path.",
      "A dead willow tree provides a home to ravens and crows on the side of the road.",
      "A random smooth stone sits in the place of a broken brick here.",
      
  }) ); 
  set_item_list( ([
      ({"brick", "bricks"}) : "The bricks covering the road are mostly destroyed, they are more rubble than brick.",
      ({"insects", "dead insects"}) : "There are dead ants and flies on the sides of the road.",
      ({"flower", "flowers"}) : "There are withered and dead lilacs and roses scattered along the side of the road.",
      ({"lamp", "lamppost"}) : "The lamp post would be useful with all these clouds if it wasn't broken.",
      ({"stones"}) : "There are a few rare stones that are not broken along the path.",
      ({"road"}) : "The road is more of a path of rubble.",
      ({"weeds", "weed"}) : "Weeds are moving through the street, taking over the road.",
      ({"glass", "shards", "shards of glass"}) : "Shards of glass litter the street, probably a result of off-duty drows not giving a damn.",
      ({"manure", "horse manure"}) : "This manure looks like it's been sitting here for quite a while, and is starting to mold and decay.",
      ({"water", "rain"}) : "Rain seems to have provided a shower here, washing the blood from some of the stones.",
      ({"stone", "smooth stone"}) : "A red stone rests randomly along the path.",
      ({"tree", "dead tree", "dead willow tree", "willow tree"}) : "A dead willow tree provides branches for many crows and ravens to squaw from.", 
      ({"grass", "dead grass"}) : "The grass on the side of the road is dead, with no traces of green to be found.",
  ]) );
  set_smell("The metallic smell of blood is very strongly present.");
  set_listen("Fighting and crying can be heard all around.");
  set_reset_list( ({
   MOB"drowinvader", MOB"drowinvader2" }) );
  set_properties( ([ "light" : 1,
                     "night light" : 1,
                     "town" : 1,
                     "road" : 1
                   ]) );
  set_short("The streets of Arlon.");
  set_mob_cap(4);
}
