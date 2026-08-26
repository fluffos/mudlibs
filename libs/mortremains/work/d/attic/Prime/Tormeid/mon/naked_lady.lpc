#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "a naked woman") ;
  set("long", @ENDLONG
A very beautiful, very naked young woman.
She seems not to notice that she is naked.
ENDLONG
  );
  set("id", ({ "lady", "woman", "naked lady", "naked woman" }) ) ;
  set("gender", "female" ) ;
  set("race", "human");
  set_name("naked lady") ;
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
  "The naked lady washes herself gently.\n",
  "The naked lady plays in the waters of the baths.\n",
  "The naked lady splashes you playfully.\n",
  "The naked lady washes her hair.\n",
  }) ) ;
  set("att_chat_output", ({
  "The naked lady screams!\n",  "The naked lady tries to scratch out your eyes!\n",
  "The naked lady pleads for her life!\n",
  }) ) ;


}
