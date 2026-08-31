#include <std.h>
#include <hermes.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
  set_day_sentances( ({
     "%^CYAN%^%^BOLD%^The mist is choking. Strange animals move everywhere.",
     "%^CYAN%^%^BOLD%^A howl is quickly cut off, a small fight breaking out over the body.",
     "%^CYAN%^%^BOLD%^The mist feels soothing against the skin but it does not brush away fear.",
     "%^CYAN%^%^BOLD%^Dark %^RED%^red%^CYAN%^ eyes peak out of a tree, then vanish.",
     "%^CYAN%^%^BOLD%^The animals do not seem to be alive. They fade in and out.",
     "%^CYAN%^%^BOLD%^It's hard looking at the animals, they are transparent and hurt the eyes.",
     "%^CYAN%^%^BOLD%^A yelp ends in a blood curdling snap.",
     "%^CYAN%^%^BOLD%^The roots of trees seem to grab at the legs."
  }) );
  set_night_sentances( ({
       "%^CYAN%^%^BOLD%^The moon light can not make it through the trees.",
       "%^CYAN%^%^BOLD%^It is quiet...",
       "%^CYAN%^%^BOLD%^A wailing cry drifts through the night and down the spine.",
       "%^CYAN%^%^BOLD%^Lights flicker all around.",
       "%^CYAN%^%^BOLD%^A shape snorts then vanishes.",
       "%^CYAN%^%^BOLD%^There is no way out...",
       "%^CYAN%^%^BOLD%^Bones litter the area. Licked clean."
         }) );
  set_item_list( ([
      "mist" : "The thick mist makes seeing more then a few meters impossible.",
      "body" : "It lies with it's throat torn open.",
      ({"tree", "trees"}) : "They almost seem...alive...",
      "animals" : "They fade in and out of the mist.",
     ]) );
  set_smell("The mist carries no scent.");
  set_listen("Guttaral sounds from every direction.");
  set_reset_list( ({
 		MOB "lbear", MOB"lant", MOB"lbull", MOB"lelk", MOB"lhedgehog",MOB"lsnake",MOB"ltree",MOB"lwisp",MOB"lwolf"}) 
   );
  set_properties( ([ "light" : 1,
                     "forest" : 1,
                     
                   ]) );
  set_short("The lost woods.");
}
