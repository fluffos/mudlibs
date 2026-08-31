#include <std.h>
#include <pastarlon.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
    set_first_sentence("%^BOLD%^%^BLACK%^Dark storm clouds cover the sky.\n %^RESET%^%^BOLD%^The planks of the docks, although a bit untended to, seem fairly preserved.%^RESET%^");
	  set_day_sentances( ({
      "The planks are wet in spots from waves crashing against the dock.",
      "There are wooden poles every few feet, holding the dock in place.",
      "There are the remains of a small canopy here, nothing more than a pile of bamboo and tall grass.",
      "Land can be seen in the ocean quite far in the distance.",
      "The sun reflects off the wet planks, making it difficult to see.",
      "Blood-stained sand fills the gaps in the planks, and little bugs crawl through it.",
      "There are white stains here from pelicans and seagulls leaving their mark.",
      "A rope seems is tied to a piece of wood in the sea, probably the remains of a small ship.",
      "A dead fish sits on the side of the dock.",
      "Blood stains the planks of the dock, some fresh and some dry.",
  }) );
  set_night_sentances( ({
      "The planks are wet in spots from waves crashing against the dock.",
      "There are wooden poles every few feet, holding the dock in place.",
      "There are the remains of a small canopy here, nothing more than a pile of bamboo and tall grass.",
      "Land can be seen in the ocean quite far in the distance.",
      "The moon reflects off the wet planks, causing an eery glow.",
      "Blood-stained sand fills the gaps in the planks, and little bugs crawl through it.",
      "There are white stains here from pelicans and seagulls leaving their mark.",
      "A rope seems is tied to a piece of wood in the sea, probably the remains of a small ship.",
      "A dead fish sits on the side of the dock.",
      "Blood stains the planks of the dock, some fresh and some dry.",
      
  }) ); 
  set_item_list( ([
      ({"planks", "dock"}) : "The dock is made up of dark wooden planks, mostly flawless.",
      ({"poles", "wooden poles"}) : "Used to regulate the height of the dock, these poles are also very fashionable.",
      ({"canopy"}) : "A small canopy used to sit here to provide shade, but it seems to have been destroyed in a battle of some sort.",
      ({"land", "distance"}) : "Some future adventure waits across the ocean!",
      ({"sun"}) : "The sunlight seems extra bright out on the dock, surrounded by water.",
      ({"moon"}) : "Without much surrounding you, the moon creates even more of a glow.",
      ({"wet planks"}) : "Some planks seem to have been made wet by splashing waves.",
      ({"sand" "gaps", "bugs", "little bugs"}) : "Dark, blood soaked sand fills the gaps between planks.  It seems to be the home to tons of little bugs.",
      ({"white stains", "stains", "poop"}) : "It should be fairly obvious what these stains are.",
      ({"wood", "piece of wood"}) : "A piece of wood is tied to a rope, probably the remains of a ship that was destroyed.",
      ({"rope"}) : "The rope stretches from a pole to the piece of wood, and it looks like it is very worn.",
      ({"fish"}) : "It is molding over and smells quite bad.",
      ({"blood", "blood stains"}) : "Some of the blood is wet and some of it is dry, but there is sure an abundance of it.",
      
  ]) );
  set_smell("The salty smell of ocean air mixes with the metallic smell of blood here.");
  set_listen("The sound of waves crashing and the caw of sick birds can be heard.");
  set_reset_list( ({
     MOB"drowinvader", MOB"drowinvader2", MOB"drowinvader3", MOB"drowinvader4" 
      }) );
  set_properties( ([ "light" : 1,
                     "night light" : 1,
                     "no fly" : 1,
                     "dock" : 1
                   ]) );
  set_short("The docks of Arlon.");
  set_mob_cap(4);
}
