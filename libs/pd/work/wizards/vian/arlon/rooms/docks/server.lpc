#include <std.h>
#include <arlondocks.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
    set_first_sentence("%^BOLD%^The planks of the docks seem to be very stable and preserved.%^RESET%^");
	  set_day_sentances( ({
      "The planks are wet in spots from waves crashing against the dock.",
      "There are wooden poles every few feet, holding the dock in place.",
      "There is a small canopy here, shaded by a roof made of long grass.",
      "Land can be seen in the ocean quite far in the distance.",
      "The sun reflects off the wet planks, making it difficult to see.",
      "Sand fills the gaps in the planks, and little bugs crawl through it.",
      "There are white stains here from pelicans and seagulls leaving their mark.",
      "A small dinghy is attached to a pole by rope, although it seems abandoned.",
      "A fish flops from the water onto the dock for a split second, before falling back in to the ocean.",
      "A warehouse worker's tools have been left here.",
  }) );
  set_night_sentances( ({
      "The planks are wet in spots from waves crashing against the dock.",
      "There are wooden poles every few feet, holding the dock in place.",
      "There is a small canopy here, shaded by a roof made of long grass.",
      "Land can be seen in the ocean quite far in the distance.",
      "The moon reflects off the wet planks, causing an eery glow.",
      "Sand fills the gaps in the planks, and little bugs crawl through it.",
      "There are white stains here from pelicans and seagulls leaving their mark.",
      "A small dinghy is attached to a pole by rope, although it seems abandoned.",
      "A fish flops from the water onto the dock for a split second, before falling back in to the ocean.",
      "A warehouse worker's tools have been left here.",
      
  }) ); 
  set_item_list( ([
      ({"planks", "dock"}) : "The dock is made up of dark wooden planks, nearly flawless.",
      ({"poles", "wooden poles"}) : "Used to regulate the height of the dock, these poles are also very fashionable.",
      ({"canopy"}) : "A small shaded canopy sits here, allowing for rest in the shade.",
      ({"land", "distance"}) : "Some future adventure waits across the ocean!",
      ({"sun"}) : "The sunlight seems extra bright out on the dock, surrounded by water.",
      ({"moon"}) : "Without much surrounding you, the moon creates even more of a glow.",
      ({"wet planks"}) : "Some planks seem to have been made wet by splashing waves.",
      ({"sand" "gaps", "bugs", "little bugs"}) : "Dark, wet sand fills the gaps between planks.  It seems to be the home to tons of little bugs.",
      ({"white stains", "stains", "poop"}) : "It should be fairly obvious what these stains are.",
      ({"dinghy", "small dinghy"}) : "An old rowboat sits in the ocean here, attached by rope.  It probably hasn't been used in quite some time.",
      ({"rope"}) : "The rope stretches from a pole to the dinghy, and it looks like it is very worn.",
      ({"fish"}) : "It flopped back into the water too quickly to get a good look.",
      ({"tool", "tools"}) : "Hammers and screwdrivers sit in a small heap, left by some warehouse worker.",
      
  ]) );
  set_smell("The salty smell of ocean air is everywhere.");
  set_listen("The sound of waves crashing and warehouse workers talking and hammering away can be heard.");
  set_reset_list( ({
      MOB"angrycrab", MOB"pelican", MOB"rocklobster", MOB"sandpiper", MOB"seagull", MOB"sluggishsnail", MOB"warehouseworker"
      }) );
  set_properties( ([ "light" : 1,
                     "night light" : 1,
                     "dock" : 1
                   ]) );
  set_short("The docks of Arlon.");
  set_mob_cap(4);
}
