// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create() {
       set ("id", ({ "gloves","gauntlets" }) ) ;
        set ("short", "gauntlets of ogre power") ;
        set ("long", "The will enhance your strength if it isnt already high.\n") ;
        set("size", -1);
        set ("bulk", 1) ;
        set ("mass", 2) ;
        set ("type", "gloves") ;
		set ("armor", 0);
		set("enchantment", 3);
set("value",   1500);
			set("armor_object", 1);		
	set("equip_func", "equip_func");
		set("unequip_func", "unequip_func");

}
string equip_func() {
	if (this_player()->query("stat/strength") > 19) {
			return "the gloves seem to be doing nothing for you." ;
			}
	this_player()->set("stat/strength", 19);
	return "you feel more powerful already" ;
	}
string unequip_func() {
	this_player()->set("stat/strength", (this_player()->query("base_stat/strength")) );
	return "you feel weaker, somehow.";
	}
