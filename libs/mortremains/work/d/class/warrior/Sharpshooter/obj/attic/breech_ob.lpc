// This object makes the weapon revert to normal when unwielded. ;)
#include <mudlib.h>

inherit OBJECT ;

int level, bonus; 
object weapon;
string long ;

void create() {
   seteuid(getuid()) ;
   set("prevent_drop", 1) ;
   set("prevent_sell", 1) ;
   set("prevent_insert", 1) ;
   set("prevent_clean", 1) ;
 }

void init() {
   add_action("unwield", "unwield") ;
}

int activate(object wep, int lvl, int bns) {
   if (!wep) return 0 ;
   weapon = wep ;
   level = lvl ;
   bonus = bns ;
   long = weapon->query("long") ;
    weapon->set("long", long+
    "This weapon has been imbued with your life force.\n"+
    "It is surrounded by an unearthly glow, and is providing light.\n"+
    "If you unwield this weapon, the power will be lost, so be warned, Warrior.\n") ;
}

int unwield(string str) {
  if (!str) return 0 ;
  if (!weapon) call_out("remove", 5) ;
  if (weapon->id(str)) {
    write("As you unwield "+weapon->query("short")+
           ", it stops glowing.\n") ;
    message("combat", "As "+TPN+" unwields "+weapon->query("short")+
         ", it ceases to glow.\n", environment(TP), ({ TP }) ) ;
   weapon->set_bonus(0,0,0) ;
    weapon->add("light", -1 ) ;
    weapon->set("long", long+
                    "This weapon was once infused with a powerful lifeforce.\n") ;
    call_out("remove", 10) ;
  }
  return 0 ;
}
