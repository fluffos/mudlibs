// A ring of slashing  resistance..

#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());
    set ("id", ({ "ring", "ring of slashing resistance" }) ) ;
    set ("short", "a ring of slashing resistance") ;
    set ("long", "two precious stones, carved into the shapes of
        blades with there tips snapped off, gives this ring a definate purpose.\n") ;
        set ("mass", 1) ;
        set_armor_type("ring") ;
        set("enchantment", 3);
set("size", -1); 
set("value",   1500);
	set("equip_func", "equip_func");
		set("unequip_func", "unequip_func");
}

	int equip_func() {
	
        this_player()->resistance("slashing", 50);
	return 1;
	}
	int unequip_func() {
	
        this_player()->resistance("slashing", 200);
	return 1;
	}

