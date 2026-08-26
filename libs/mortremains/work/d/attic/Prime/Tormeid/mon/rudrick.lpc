#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "Rudrick") ;
  set("long", @ENDLONG
Rudrick is an elderly gentleman with a perchant for smoking tobacco and
playing chess.  He is currently ill, and bed-ridden.
ENDLONG
  );
 set("id", ({ "rudrick", "man" }) );
  set("gender", "male");
  set("race", "human");
  set_name("Rudrick") ;
   set_level(4) ;
  set_alignment("lg") ;
  set("damage", ({ 2, 4 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  clone_object(OBJ(tobacco_pipe))->move(TO) ;
  set("chat_chance", 3) ;
  set("chat_output",({
   "Rudrick coughs violently.\n",
   "Rudrick shivers.\n",
  }) ) ;
}
