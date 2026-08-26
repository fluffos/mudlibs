// A ring of fire resistance.
// Ilzarion coded this, but he left am ancient header on it...
// Cyanide added this header and cleaned up the code a bit 23 Jul 97

#include <mudlib.h>

inherit ARMOR ;

void create() {
       set ("id", ({ "ring", "ring of fire resistance" }) ) ;
        set ("short", "a ring of fire resistance") ;
        set ("long", "this helps you sustain fire damage.\n") ;
        set ("mass", 1) ;
        set_armor_type("ring") ;
        set("enchantment", 3);
set("size", -1); 
set("value",   500);
	set("equip_func", "equip_func");
		set("unequip_func", "unequip_func");
}

	int equip_func() {
	
	this_player()->resistance("fire", 50);
	return 1;
	}
	int unequip_func() {
	
	this_player()->resistance("fire", 200);
	return 1;
	}

