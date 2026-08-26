#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "a lady-in-waiting") ;
  set("long", @ENDLONG
This is one of the Queen's ladies-in-waiting.
She is *very* pretty.
ENDLONG
  );
  set("id", ({ "girl", "lady", "lady in waiting", "lady-in-waiting" }) ) ;
  set("gender", "female" ) ;
  set("race", "human");
  set_name("lady-in-waiting") ;
  credit(random(75)) ;
  set_align("ln") ;
  set_level(5);
  set("CLASS", "warrior") ;
  set("natt", 1);
  set("damage", ({ 2, 4 }) );
  set_size( 6);
  set("weapon_name", "fists");
  set("smell", "The lady smells very clean.") ;
  set_verbs( ({ "swing at", "attack" }) );
   set("chat_chance", 5) ;
   set("chat_output", ({
   "The lady-in-waiting folds some clothes.\n",
   "The lady-in-waiting cleans something.\n",
   "The lady-in-waiting sighs wistfully.\n",
  }) ) ;
  set("att_chat_output", ({
  "The lady-in-waiting throws a vase at you!\n",
  "The lady-in-waiting screams loudly!\n",
   "The lady-in-waiting cusses you out!\n",
  }) ) ;
  if (!random(10)) clone_object(OBJ(servant_key))->move(TO) ;


}
