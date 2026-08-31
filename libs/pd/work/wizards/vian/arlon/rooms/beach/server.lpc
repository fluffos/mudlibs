#include <std.h>
#include <arlonbeach.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
  set_first_sentence("%^BOLD%^The beach is covered in bright, white sand which glistens as light is reflected off of it.%^RESET%^");
  set_day_sentances( ({
      "The ocean waves wash random sea life up onto the shore.",
      "A strong wind blows a mist of salty water inland toward the city.",
      "Shattered bottles from alcoholic beverages makes it a bit scary to navigate the beach.",
      "Massive ships can be seen in the nearby ocean, a few bearing colorful flags.",
      "There are broken bits of shells littering the otherwise flawless sand.",
      "Abandoned scraps of cloth lay out on the sand, remnants of clothes destroyed by a sea creature.",
      "Beach toys are scattered about, partially covered in sand.",
      "A small bonfire has been left here, still burning and billowing out clouds of smoke.",
      "The bright sunlight reflects off of the ocean's surface and on to the sand, having a nearly blinding effect.",
      "Tiny bugs jump around on the sand, bothering anyone that walks through."
  }) );
  set_night_sentances( ({
      "The ocean waves wash random sea life up onto the shore.",
      "A strong wind blows a mist of salty water inland toward the city.",
      "Shattered bottles from alcoholic beverages makes it a bit scary to navigate the beach.",
      "Massive ships can be seen in the nearby ocean, a few bearing colorful flags.",
      "There are broken bits of shells littering the otherwise flawless sand.",
      "Abandoned scraps of cloth lay out on the sand, remnants of clothes destroyed by a sea creature.",
      "Beach toys are scattered about, partially covered in sand.",
      "A small bonfire has been left here, still burning and billowing out clouds of smoke.",
      "The moonlight reflects off of the ocean's surface, creating an eerie glow.",
      "Tiny bugs jump around on the sand, bothering anyone that walks through."

      
  }) ); 
  set_item_list( ([
      ({"sand", "beach"}) : "The beach is covered in a base of sand with a top layer of litter, ranging from shattered glass to scraps of destroyed armour.",
      ({"waves", "ocean"}) : "The ocean waves swell up and crash toward the beach.",
      ({"water", "mist"}) : "A mist of salty water is constantly blowing through the air.",
      ({"shattered bottles", "bottle", "bottles"}) : "Shattered glass from firebreathers and the like are littered throughout the area.",
      ({"ship", "ships"}) : "MASSIVE ships move toward and away from the Port of Arlon.",
      ({"flags", "colorful flags"}) : "The flags on the ships range from black flags with the Jolly Rodger to multicolored flags of all types.",
      ({"shells", "broken shells"}) : "Both seashells and remnants of crab shells litter the beach, some bloody from barefoot travelers.",
      ({"scraps", "cloth", "scraps of cloth", "clothes"}) : "Scraps of cloth armour, bloodied from fights, can be seen on the ground.",
      ({"toys", "beach toys"}) : "Buckets, shovels, beach balls and other such toys litter the beaches of Arlon.",
      ({"bonfire", "small bonfire"}) : "A bonfire is an overstatement, there is simply a burning pile of driftwood here.",
      ({"smoke"}) : "Gray smoke billows through the air.",
      ({"sunlight", "moonlight"}) : "The light bounces off of the oceans surface, making it much more visible out here.",
      ({"bugs", "tiny bugs"}) : "The tiny bugs look harmless enough, although they do tear apart dead crabs quite quickly.",

  ]) );
  set_smell("The salty smell of ocean air is everywhere.");
  set_listen("The sound of waves crashing on the sand can be heard.");
  set_reset_list( ({
      MOB"angrycrab", MOB"floppingfish", MOB"pelican", MOB"rocklobster",
MOB"sandpiper", MOB"seagull", MOB"sealion", MOB"seaturtle", MOB"sluggishsnail",
MOB"starfish", MOB"tanninggirl", MOB"hunkydude"
  }) );
  set_properties( ([ "light" : 1,
                     "night light" : 1,
                     "beach" : 1
                   ]) );
  set_short("The beaches of Arlon.");
  set_mob_cap(4);
}

