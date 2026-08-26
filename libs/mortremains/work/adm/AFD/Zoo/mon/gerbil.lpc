#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "a furry gerbil");
  set("long", "It's a furry little rodent.\n");
  set("id", ({ "#BLAH", "gerbil", "rodent" }) );
  set("race", "rodent");
  set_hide_race() ;
  set_name("gerbil");
  set_level(1) ;
  set_alignment(1);
  set("damage", ({ 1, 2 }) );
  set("weapon_name", "teeth");
  set("chat_chance", 2) ;
  set("chat_output", ({ 
   "The gerbil scurries around.\n",
   "The gerbil stand up on its hind legs.\n",
  }) );
  credit(random(30)) ;
  set_verbs( ({ "bite at", "attack" }) );
}

void init() {
  add_action("put", "put") ;
  add_action("put", "shove") ;
  add_action("put", "place") ;
}

int put(string str) {
  if (!str) return 0 ;
  if (sscanf(str, "%s in ass", str)!=1 && 
      sscanf(str, "%s up ass", str)!=1) return 0 ;
  if (str!="gerbil") return 0 ;
  if (TP->query("gerbil")) {
    write("You already have a gerbil stuck up your ass, why do you need another one?\n");
     return 1;
  }
  write("You shove the gerbil up your ass.\n") ;
  say(TPN+" shoves the gerbil up "+TP->query_possessive()+" ass.\n") ;
  TP->set("gerbil", 1) ;
  remove() ;
  return 1;
}
