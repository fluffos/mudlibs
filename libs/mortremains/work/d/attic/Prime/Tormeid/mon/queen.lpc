#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
   seteuid(getuid()) ;
  set("short", "Queen Priscilla") ;
  set("long", @ENDLONG
This is the wife of the Kind of Tormeid.  She is absolutely radiant.
ENDLONG
  );
  set("id", ({ "queen", "priscilla", "queen priscilla" }) ) ;
 set("gender", "female") ;
  set("race", "human");
  set_name("queen") ;
  credit(random(1234) * random(5)) ;
  set_level(40) ;
  set_alignment("tn") ;
  set("damage", ({ 1, 4 }) ) ;
  set_size( 5) ;
  set("weapon_name", "fists");
  set("stat", ([
    "strength" : 14, "dexterity" : 19, "intelligence" : 15,
   "wisdom" : 17, "constitution" : 18, "charisma" : 19 ]) ) ;
  set_verbs( ({ "swing at", "punche at" }) ) ;
  wear(ARM(fabulous_dress), "dress") ;
  wear(ARM(diamond_ring), "ring") ;
  wear(ARM(royal_panties),"panties") ;
  wear(ARM(protring5), "ring") ;
  wear(ARM(earring1), "earring") ;
  wear(OBJ(chest_key), "key") ;
  set("special", 1 ) ;
}

void special_attack() {
  if (!random(5)) {
      write("You cast a simple healing spell.\n");
      say("The queen casts a simple spell.\n");
      TO->receive_healing(10 + random(50) ) ;
       return ;
   }
  if (random(3)) {
  write("You call for help!\n");
  say("The Queen screams for help!\n") ;
  if (!present("guard", environment(TO))) {
   say(
        "A royal guard rushes into the room to save the Queen!\n");
     clone_object(MON(guard2))->move(environment(TO));
    }
  }
 return ;
}

// Guards won't attack her now. ;)
int query_king() { return 1 ; }
