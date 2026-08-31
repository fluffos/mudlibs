#include <std.h>
#include <pastarlon.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
  set_first_sentence("%^BOLD%^%^BLACK%^Dark storm clouds cover the sky.\n %^RESET%^%^BOLD%^The beach is covered in %^RED%^blood stained %^WHITE%^sand which glistens as light is reflected off of it.%^RESET%^");
  set_day_sentances( ({
      "The ocean waves wash random debris and dead fish up onto the shore.",
      "A strong wind blows a mist of salty water inland toward the city.",
      "Shattered bottles from alcoholic beverages makes it a bit scary to navigate the beach.",
      "Massive ships can be seen in the nearby ocean, a few bearing pirate flags.",
      "There are broken bits of shells littering the otherwise flawless sand.",
      "Abandoned scraps of cloth lay out on the sand, remnants of clothes destroyed by battle.",
      "Broken weapons are scattered about, partially covered in sand.",
      "A small bonfire has been left here, still burning and billowing out clouds of smoke.",
      "The bright sunlight reflects off of the ocean's surface and on to the sand, having a nearly blinding effect.",
      "Tiny bugs jump around on the sand, bothering anyone that walks through."
  }) );
  set_night_sentances( ({
      "The ocean waves wash random debris and dead fish up onto the shore.",
      "A strong wind blows a mist of salty water inland toward the city.",
      "Shattered bottles from alcoholic beverages makes it a bit scary to navigate the beach.",
      "Massive ships can be seen in the nearby ocean, a few bearing pirate flags.",
      "There are broken bits of shells littering the otherwise flawless sand.",
      "Abandoned scraps of cloth lay out on the sand, remnants of clothes destroyed by battle.",
      "Broken weapons are scattered about, partially covered in sand.",
      "A small bonfire has been left here, still burning and billowing out clouds of smoke.",
      "The moonlight reflects off of the ocean's surface, creating an eerie glow.",
      "Tiny bugs jump around on the sand, bothering anyone that walks through."

      
  }) ); 
  set_item_list( ([
      ({"sand", "beach"}) : "The beach is covered in a base of sand with a top layer of blood and litter, ranging from shattered glass to scraps of destroyed armour and weapons.",
      ({"waves", "ocean"}) : "The ocean waves swell up and crash toward the beach.",
      ({"water", "mist"}) : "A mist of salty water is constantly blowing through the air.",
      ({"shattered bottles", "bottle", "bottles"}) : "Shattered glass from firebreathers and the like are littered throughout the area.",
      ({"ship", "ships"}) : "MASSIVE ships move toward and away from the Port of Arlon.",
      ({"flags", "pirate flags"}) : "Some ships carry pirate flags, from the Jolly Rodger to the flags of other, less known pirate clans.",
      ({"shells", "broken shells"}) : "Both seashells and remnants of crab shells litter the beach, some bloody from barefoot travelers.",
      ({"scraps", "cloth", "scraps of cloth", "clothes"}) : "Scraps of cloth armour, bloodied from fights, can be seen on the ground.",
      ({"weapons", "broken weapons"}) : "Hilts from swords and knives, broken staves, and other random weapons litter the beach.",
      ({"bonfire", "small bonfire"}) : "A bonfire is an overstatement, there is simply a burning pile of driftwood here.",
      ({"smoke"}) : "Gray smoke billows through the air.",
      ({"sunlight", "moonlight"}) : "The light bounces off of the oceans surface, making it much more visible out here.",
      ({"bugs", "tiny bugs"}) : "The tiny bugs look harmless enough, although they do tear apart dead crabs quite quickly.",

  ]) );
  set_smell("The salty smell of ocean air is everywhere.");
  set_listen("The sound of waves crashing on the sand can be heard.");
  set_reset_list( ({
     MOB"drowinvader", MOB"drowinvader2", MOB"drowinvader3", MOB"drowinvader4" 
  }) );
  set_properties( ([ "light" : 1,
                     "night light" : 1,
                     "no fly" : 1,
                     "beach" : 1
                   ]) );
  set_short("The beaches of Arlon.");
  set_mob_cap(4);
}

