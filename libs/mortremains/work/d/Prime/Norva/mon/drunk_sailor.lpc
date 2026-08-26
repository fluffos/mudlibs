#include <mudlib.h>
#include "../defs.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short",  "a drunken sailor");
    set ("long", @ENDLONG
This sailor has obviously had a few too many beers at the local club.
His white hat is cocked on the back of his head at a crazy angle
and various vomit stains spot his uniform.
ENDLONG
  );
    set ("id", ({"drunk", "sailor", "drunken sailor"}) );
    set_name("drunken sailor");
  set("smell", "He smells like vomit.") ;
    set ("gender", "male") ;
  set("chat_chance", 2) ;
  set("author", "Chronos") ;
  set("chat_output", ({
    "The drunken sailor hiccups.\n",
  "The drunken sailor staggers around, drunk.\n",
  "The drunken sailor trips and falls on his face.\n",
   "The drunken sailor looks at you for a moment.\n",
  "The drunken sailor says: I'll fight anyone! <hic>\n",
  }) ) ;
    set ("race", "human");
    enable_commands() ;
    set ("stat/constitution", 10);
    set ("stat/strength", 14);
    set ("base_ac", 8);
    set ("armor_class", 7);
    set ("damage", ({ 1, 4 }) ) ;      
   set ("weapon_name", "fists");
    set ("CLASS", "warrior");
    set_verbs( ({ "punche at", "swing at", "swipe at" }) ) ;
    set_size(5);
    set_level(8);
    set ("speed", 10);
   wear(ARM(whitehat)) ;
  set("prevent_summon", 1) ;
    set("wealth", random(20) ) ;
}                       
