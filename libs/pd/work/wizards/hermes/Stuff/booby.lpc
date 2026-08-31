#include <std.h>
inherit ARMOUR;
int reading(string str);
void create() {
  ::create();
  set_name("bronze ring");
  set("id", ({ "ring", "bronze ring" }) );
  set("short", "Bronze ring");
  set("long", "The ring is made out of a dented plate of bronze"
    " it looks sad, worn, but hopeful and destained to be great.");
  set_type("ring");
  set_ac(0);
  set_limbs( ({ "right hand" }) );
  set("read",(: reading :));
  set_weight(5);
  set("value", 0);
}
int bury() {
  write("You dare not destroy such a thing!");
  return 1;
}
int reading(string str) {
 
  write("Revenge is a dish best served cold.");
  write("R.I.P. Kenjiru");
  }
 int query_auto_load() {
  if(this_player()->query_cap_name() == "Kenjiru") return 1;
  return 0;
}
