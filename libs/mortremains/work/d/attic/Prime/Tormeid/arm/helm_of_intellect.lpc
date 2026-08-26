#include <mudlib.h>

inherit ARMOR ;

void create() {
  set("id", ({ "helm","helmet" }) ) ;
  set("short", "helm of intellect");
  set("size", -1 ) ;
  set("long", "This helmet is said to make the wearer a little brighter.\n") ;
  set("equip_func", "up_int") ;
  set("unequip_func", "lower_int") ;
  set_armor_type("helmet") ;
  set("bonus", 2);
  set("value",   5000);
}

int up_int() {
  write("You feel smarter somehow.\n");
  TP->add("stat/intelligence", 1) ;
  return 1;
}

int lower_int() {
  write("You feel quite a bit dumber.\n");
  TP->add("stat/intelligence", -1) ;
  return 1;
}
