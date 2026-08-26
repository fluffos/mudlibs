// coins.c
// The basic money object.
// Written by Chronos.

#include <move.h>
#include <mudlib.h>

inherit OBJECT ;

void set_descs();
int number ;

void create() {
        number = 1 ;
  set("money", 1);
        set_descs();
}

void set_descs() {
  if (number == 1) {
    set("short", "1 coin");
  set("long", "A single coin, all by itself.\n");
  set("id", ({ "coin", "coins" }) );
  }
  else {
  set("short", number + " coins");
  set("long", "A pile of " + number + " coins.\n");
  set("id", ({ "coin", "coins" }) );
  }
  return ;
}

void set_number (int num) {
        if (num<1) remove() ;
        number = num ;
        set_descs() ;
}

int query_number() { return number ; }

int move(mixed dest) {
        int i ;
        object ob ;

        if (living(dest)) {
                dest->credit(number) ;
                remove() ;
                return MOVE_OK ;
        }
        ob = present("coins",dest) ;
        if (!ob) {
                i = ::move(dest) ;
                return i ;
        }
        i = ob->query_number() ;
        ob->set_number(i+number) ;
        remove() ;
        return MOVE_OK ;
}
