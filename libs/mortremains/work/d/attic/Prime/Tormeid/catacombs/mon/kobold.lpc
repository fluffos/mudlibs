#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "a kobold") ;
  set("long", @ENDLONG
An ugly little kobold with a crude shortsword and wooden shield.
ENDLONG
  );
  set("id", ({ "kobold" }) ) ;
  set("gender", "male") ;
  set("race", "kobold") ;
  set_name("kobold") ;
  set_align("ne") ;
  set_level(6) ;
  set("CLASS", "warrior") ;
  set("natt", 1) ;
  set("damage", ({ 1, 4 }) ) ;
  set_size(5) ;
  set("weapon_name", "claws") ;
  set_verbs( ({ "swing at", "attack" }) );
  set("wealth", 30 + random(40) ) ;
  set("aggressive", 1 ) ;
  arm(WEP(crude_sword), "sword") ;
  wear(ARM(buckler), "buckler") ;
}


