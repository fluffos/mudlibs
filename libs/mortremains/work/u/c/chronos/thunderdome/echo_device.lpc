#include <mudlib.h>
#include "td.h"

inherit MONSTER ;

void create() {
  ::create() ;
  seteuid(getuid()) ;
  set("prevent_attack", 1) ;
  set("prevent_clean", 1) ;
  set("gender", "neuter") ;
  set("race", "blah") ;
  set_name("echo device") ;
  set("invisible", 2) ;
  set("immortal",1 ) ;
  set_level(99) ;
}

void kill_ob(object ob) {
   return ;
}

int receive_damage(string type, int damage) {
   return 0;
}

void receive_message(string Class, string message) {
  message("echo", message,
   find_object_or_load(TD+"ob")) ;
}
