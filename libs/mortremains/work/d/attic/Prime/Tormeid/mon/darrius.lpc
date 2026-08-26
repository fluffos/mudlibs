#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "Darrius") ;
  set("long", @ENDLONG
Darrius is a strong young man who was taken in by the royal family
as a small child.  He has grown into quite the young warrior.
ENDLONG
  );
  set("id", ({ "darrius" }) ) ;
  set("gender", "male");
  set("race", "human");
  set_name("Darrius") ;
  credit(random(100)+ 102) ;
  set_level(30) ;
  set_alignment("ng") ;
  set_skill("Long Blades", 2, "strength") ;
  set("damage", ({ 2, 4 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  wear(ARM(fine_chainmail), "chainmail") ;
  arm(WEP(darrius_sw), "sword") ;
}
