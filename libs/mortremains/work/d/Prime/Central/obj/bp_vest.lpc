#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());

    set ("id", ({ "bulletproof vest", "vest" }) ) ;
    set ("short", "a bulletproof vest") ;
    set ("long", @ENDLONG
This vest is made of Kevlar and is designed to absorb the impact from bullets.
ENDLONG
  ) ;

    // All armor objects need to set a "type", ie suit, shield, helmet, boots,
    // whatever. The player can wear only one of each type of armor.
   set("type", "suit" ) ;
   set("armor", 10) ;
   set("bonus", 1 ) ;
   set("mass", 15) ;
  set("material_type", "kevlar") ;
   set("value", 2500) ;
  set("armor_object", 1 ) ;

}                    
