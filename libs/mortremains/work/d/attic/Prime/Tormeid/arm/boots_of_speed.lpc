// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create() {
  set("id", ({ "boots", "speedboots" }));
  set("short", "boots of speed");
  set("long", "These will help you dodge some attacks.\n") ;
  set("equip_func", "up_dex") ;
  set("unequip_func", "lower_dex") ;
  set_armor_type("boots") ;
  set("size", -1 ) ;
  set("bonus", 2);
  set("value",   5000);
}

int up_dex() {
  write("You feel very light on your feet.\n");
  TP->add("stat/dexterity", 1) ;
  return 1;
}

int lower_dex() {
  write("You feel very slow, suddenly.\n");
  TP->add("stat/dexterity", -1) ;
  return 1;
}
