
#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());
    set ("id", ({ "ring", "ring of acid resistance" }) ) ;
    set ("short", "a ring of acid resistance") ;
    set ("long", "this ring is made of a thick clear glass, which is
    surrounded by a bright red light glowing from within a smallish
    green stone..\n") ;
        set ("mass", 1) ;
        set_armor_type("ring") ;
        set("enchantment", 3);
set("size", -1); 
set("value",   1500);
	set("equip_func", "equip_func");
		set("unequip_func", "unequip_func");
}

	int equip_func() {
	
        this_player()->resistance("acid", 50);
	return 1;
	}
	int unequip_func() {
	
        this_player()->resistance("acid", 200);
	return 1;
	}

