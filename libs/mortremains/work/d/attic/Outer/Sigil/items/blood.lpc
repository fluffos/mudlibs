/*
** blood.c - for the severed arm, or whatever.
**   Coded 26 Sep 97
*/

#define DELAY 10

#include <mudlib.h>

inherit OBJECT;

void create() {
  set("id", ({ "blood", "pool", "pool of blood" }) );
  set("short", "a pool of fresh blood");
  set("long", "It is still warm, but quickly soaking into the "+
    "ground.\n");
  set("prevent_get", 1);
}


void begin_evaporate (object ob) {
  if (living(ob)) {
    tell_object(ob, "Blood drips from the severed arm, pooling "+
      "at your feet.\n");
    tell_room(environment(ob), "Blood drips from the arm "+
      ob->query("cap_name")+" carries, pooling at "+
      possessive(ob->query("gender"))+" feet.\n", ({ ob }) );  
    } else {
      tell_room(environment(this_object()), "Blood drips from "+
        "the severed arm, pooling around it.\n");
    }
    call_out("soak", 11);
  }

void soak() {
  tell_room(environment(TO), "The pool of blood soaks into the"+
    " ground.\n");
  remove();
}

/* EOF */
