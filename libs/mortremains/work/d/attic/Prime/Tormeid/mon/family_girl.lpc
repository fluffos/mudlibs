#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create(){
  ::create();
  set("short", "a little girl") ;
  set("long", @ENDLONG
A cute little girl.
ENDLONG
  );
  set("id",({ "little girl", "girl" }) ) ;
  set("gender", "female");
  set("race", "human");
  set_name("little girl") ;
  credit( 3) ;
  set_level(1) ;
  set("stat", ([
   "strength" : 7, "dexterity" : 11, "intelligence" : 10,
   "wisdom" : 9, "charisma" : 15, "constitution" : 11
  ]) ) ;
  set_alignment("lg") ;
  set("damage", ({ 2, 6 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "punche at", "swing at", "attack" }) );
}
