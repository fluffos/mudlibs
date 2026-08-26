// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create() {
       set ("id", ({ "armor","plate", "suit" }) ) ;
        set ("short", "grey waste full plate") ;
        set ("long", "Bulky plate mail made of heavy grey metal.\n") ;
        set ("bulk", 6) ;
        set ("mass", 50) ;
        set ("type", "suit") ;
        	set("armor_object", 1);
        	set("enchantment", 2);
	set("armor", 9);
	set("value", 6000);
	set("equip_func", "equip_func");
		set("unequip_func", "unequip_func");
}
	int equip_func() {

	this_player()->resistance("necromancy", 50);
	return 1;
	}
	int unequip_func() {

	this_player()->resistance("necromancy", 200);
	return 1;
	}
