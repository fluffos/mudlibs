#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "Reynold the Scholar") ;
  set("long", @ENDLONG
Reynold is a bespectacled young man who looks quite studious
and knowledgable.  The only interesting thing about him is the fact
that he has a nice pair of boots.
ENDLONG
  );
  set("id", ({ "scholar", "reynold" }) ) ;
  set("gender", "male");
  set("race", "human");
  set_name("reynold the scholar") ;
  credit(random(100)+ 102) ;
  set_level(11) ;
  set_alignment("lg") ;
  set("damage", ({ 2, 4 }) );
  set_size( 6);
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  wear(ARM(nice_boots), "boots") ;
}

