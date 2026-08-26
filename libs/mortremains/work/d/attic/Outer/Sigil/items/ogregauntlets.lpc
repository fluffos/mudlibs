// Created by Ilzarion. Edited by Cyanide.

#include <mudlib.h>

inherit ARMOR ;

int change;

void create() {
    set ("id", ({ "gloves","gauntlets" }) ) ;
    set ("short", "gauntlets of ogre power") ;
    set ("long", "The will enhance your strength if it isnt already high.\n") ;
    set("size", -1);
    set_armor_type("gauntlets");
    set ("armor", 0);
    set("enchantment", 3);
    set("value",   1500);
    set("armor_object", 1);		
    set("equip_func", "equip_func");
    set("unequip_func", "unequip_func");

}

// 06 Nov 98 - Cyanide limited to a +2 strength addition.
string equip_func() {
    change = (19 - (this_player()->query("base_stat/strength")));
    if (change > 2) change = 2;
    if (change < 0 ) change = 0;
    this_player()->add("stat/strength", change);
    if (change < 1) {
	return "the gloves seem to be doing nothing for you." ;
    }else{
	return "you feel more powerful already" ;
    }

}
string unequip_func() {
    this_player()->add("stat/strength", (-1 * change));
    return "you feel weaker, somehow.";
}
