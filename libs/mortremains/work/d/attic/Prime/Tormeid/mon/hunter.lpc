#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
 set("short", "a noble hunter") ;
  set_skill("Two Weapon Style", 2, "strength") ;
  set("long", @ENDLONG
This man appears to be getting ready for a hunting expedition.
He looks like an experienced outdoorsman.  He is armed to the teeth,
and looks like he knows use each weapon very effectively.
ENDLONG
  );
  set("id", ({ "hunter" }) );
  set("gender", "male");
  set("race", "human");
  set_name("hunter");
  credit(random(50));
  set_level(22) ;
  set("natt", 3) ;
  set_skill("Long Blades", 2, "strength") ;
  set_skill("Short Blades", 2, "strength") ;
  set_alignment("ng");
  set("damage", ({ 2, 4 }) );
  set_size( 6);
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  arm(WEP(broadswd), "sword");
  wear(ARM(cloak), "cloak" ) ;
  arm(WEP(hunting_knife), "knife");
  wear(ARM(leather_armor), "armor");
  wear(ARM(lgloves), "gloves");
  wear(ARM(slboots), "boots");
}


