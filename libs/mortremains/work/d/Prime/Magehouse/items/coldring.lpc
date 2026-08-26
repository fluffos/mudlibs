// A ring of slashing  resistance..

#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());
    set ("id", ({ "ring", "ring of cold resistance" }) ) ;
    set ("short", "a ring of cold resistance") ;
    set ("long", "a single ice blue ruby set into a round base.\n") ;
        set ("mass", 1) ;
        set_armor_type("ring") ;
        set("enchantment", 3);
set("size", -1); 
set("value",   1500);
   set("equip_func", "equip_func");
      set("unequip_func", "unequip_func");
}

   int equip_func() {
   
        this_player()->resistance("cold", 50);
   return 1;
   }
   int unequip_func() {
   
        this_player()->resistance("cold", 200);
   return 1;
   }

