#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "mischievious youth" ) ;
  set("long", @ENDLONG
This kid looks like trouble.  He wears a fine leather cap.
ENDLONG
  );
  set("id", ({ "brat", "kid", "youth" }) ) ;
  set("gender", "male") ;
  set("race", "human");
  set_name("youth") ;
  set("chat_chance", 6) ;
  set("chat_output", ({
  "The youth makes a face at you.\n",
  "The youth calls you a name.\n",
  "The youth whines at you.\n",
  }) ) ;
  credit(random(20) + 10 ) ;
 set_level(3) ;
  set_alignment("ng") ;
  set("damage", ({ 1, 4 }) ) ;
  set_size(5) ;
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  wear(ARM(leather_cap), "cap") ;
  arm(WEP(dagger), "dagger") ;
  wear(ARM(brass_ring), "ring") ;
}
