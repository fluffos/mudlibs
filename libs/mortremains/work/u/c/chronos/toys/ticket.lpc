#include <mudlib.h>

inherit OBJECT ;

void create() {
   seteuid(getuid()) ;
  set("short", "a ticket") ;
  set("id", ({ "ticket" }) ) ;
   set("long", "A ticket.\n") ;
}

void set_number(int x) {
    set("short", "a ticket (#"+x+")") ;
    set("long", "You have the number "+x+" ticket.\n") ;
  return ;
}
