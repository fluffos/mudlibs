// A ring of slashing  resist..

#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());
    set ("id", ({ "talisman", "talisman of the void" }) ) ;
    set ("short", "A talisman of the void") ;
    set ("long", "silvery script carefully etched to form symbols of 
        power make this talisman a thing of beauty.\n") ;
        set ("mass", 1) ;
        set_armor_type("ring") ;
        set("enchantment", 3);
set("size", -1); 
set("value",   1500);
	set("equip_func", "equip_func");
set("unequip_func", "unequip_func");
}

	int equip_func() {
TP->add("magic_resist", 150);
TP->add("prevent_attack", 1);
	return 1;
	}

int unequip_func() {
TP->add("magic_resist", -150);
TP->add("prevent_attack", -1);
return 1;
}

/* EOF */
