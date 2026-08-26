#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "Lord Vargas") ;
  set("long", @ENDLONG
Lord Vargas is one of the resident lords in the castle.  He spends most
of his time in this room, smoking and reading.
ENDLONG
  );
  set("id", ({ "lord", "man", "vargas", "lord vargas" }) ) ;
  set("gender", "male");
  set("race", "human");
  set_name("Lord Vargas") ;
 set_level(13) ;
  set_alignment("lg") ;
  set("damage", ({ 2, 4 }) );
  set("weapon_name", "fists");
  credit(1500) ;
  set_verbs( ({ "swing at", "attack" }) );
  clone_object(OBJ(tobacco_pipe))->move(TO) ;
  set("chat_chance", 3) ;
  set("chat_output",({
  "Lord Vargas flips through a book casually.\n",
  "Lord Vargas glances up at you momentarily.\n",
   "Lord Vargas coughs politely.\n",
  "Lord Vargas puffs on his pipe.\n",
  }) ) ;
}
