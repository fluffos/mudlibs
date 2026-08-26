#include <mudlib.h>

inherit OBJECT ;

int X = 1 ;
void create() {
  seteuid(getuid())  ;
  set("short", "a ticket dispenser") ;
  set("prevent_get", 1 ) ;
  set("prevent_insert", 1) ;
  set("id", ({ "dispenser", "machine", "ticket dispenser" }) ) ;
   set("long", "@@query_long") ;
}

string query_long() {
  return "The next ticket is number "+X+".\n  You could \"take ticket\" if you want.\n" ;
}

void init() {
  if (living(environment())) TO->move(environment(environment())) ; 
   add_action("take", "take") ;
}

int take(string str) {
  object ob ;
  if (!str || str != "ticket") {
     return 0 ;
  }
   write("You grab ticket number "+X+".\n") ;
   say(TPN+" grabs ticket number "+X+" from the dispenser.\n") ;
  ob = clone_object("/u/c/chronos/toys/ticket") ;
   ob->set_number(X) ;
   X++ ;
  ob->move(TP) ;
  return 1; 
}
