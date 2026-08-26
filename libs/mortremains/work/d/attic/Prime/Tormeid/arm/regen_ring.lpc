// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create() {
       set ("id", ({ "ring", "ring of regeneration" }) ) ;
        set ("short", "ring of regeneration") ;
        set ("long", "A powerful item of healing.\n") ;
        set ("bulk", 1) ;
        set ("mass", 1) ;
        set_armor_type("ring") ;
        set ("enchantment", 5);
set("size", -1); 
  set("value", 6000 ) ;
	set("equip_func", "equip_func");
		set("unequip_func", "unequip_func");

}
string equip_func() {
	this_player()->add("regeneration", (this_player()->query_level()));
return ("Your wounds begin to close faster.");
	}
string unequip_func() {
this_player()->add("regeneration", (-1 * (this_player()->query_level())));
return ("You feel less healthy.");
	}
