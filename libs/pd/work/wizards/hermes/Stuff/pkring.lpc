#include <std.h>
inherit ARMOUR;
int reading(string str);
void create() {
  ::create();
  set_name("golden ring");
  set("id", ({ "ring", "golden ring" }) );
  set("short", "Golden ring");
  set("long", "The ring shines with a golden tone as brilliant as the sun"
    " But there is an evil feeling about it... something dark and twisted.  Words can be made out on the band");
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
 
  write("First kill of the new Player Killing season!");
  write("R.I.P. Kenjiru");
  }
 int query_auto_load() {
  if(this_player()->query_cap_name() == "Galdur") return 1;
  return 0;
}
