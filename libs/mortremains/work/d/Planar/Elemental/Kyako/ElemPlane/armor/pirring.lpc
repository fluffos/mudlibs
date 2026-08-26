// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create() {
        set ("id", ({ "armor", "ring", "glowing ring" }));
        set ("short", "glowing ring");
        set ("long", "This ring appears to be glowing in several different colors.\n");
        set ("bulk", -1) ;
        set ("mass", -1) ;
        set_armor_type("ring") ;
        set("equip_func", "equip_func");
        set("unequip_func", "unequip_func");
        set("bonus", 2);
        set("value", 5000);
	}

int equip_func() {
  TP -> resistance("force", 80);
  TP -> resistance("fire", 80);
  TP -> resistance("cold", 80);
  TP -> resistance("electricity", 80);
  TP -> resistance("acid", 80);
write("As you equip the armor, you feel yourself become better protected.\n");
  return 1;
}

int unequip_func() {
  TP -> resistance("force", 125);
  TP -> resistance("fire", 125);
  TP -> resistance("cold", 125);
  TP -> resistance("electricity", 125);
  TP -> resistance("acid", 125);
write("As you equip the armor, you feel the protection leave you.\n");
  return 1;
}
