/* File: ruby.c
// Purpose: A gem or somthing.
// Date: May something.
*/

#include <mudlib.h>
#include "plane.h"

inherit OBJECT;

void create() {
   seteuid(getuid());
   set("id", ({ "ruby", "gem" }) );
   set("short", "a ruby");
   set("long", @Gem
This is a rather large ruby. It looks like it may bring a good
price at the local store.
Gem
  );
   set("value", 300);
 }

void init() {
  add_action("fire", "use");
}

int fire(string str) {
  object target;
  target = present(str, environment(TP));
  if (!target) {
    write("That object isn't here.\n");
    return 1;
  } else {
    write("The ruby begins to glow as you throw the ruby at "+str+".\n"); 
    write("As the ruby hits "+str+", it erupts in flames.\n");
    target->receive_damage((random(10)+5), "fire");
    target->kill_ob(TP);
    ::remove();
    return 1;
  }
  return 1;
}
