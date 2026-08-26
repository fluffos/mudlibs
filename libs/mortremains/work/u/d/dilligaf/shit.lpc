// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create() {
      set ("id" , ({ "boots" }) );
    set("short" , "chaos boots") ;
    set("long" , @EndLong
  Chaos boots that will increase your constitution 10 fold.
EndLong
);
        set("size", -1);
        set ("bulk", 1) ;
        set ("mass", 2) ;
    set_armor_type("boots");
    set("armor" , 5);
		set("enchantment", 3);
set("value",   1500);
			set("armor_object", 1);		
	set("equip_func", "equip_func");
		set("unequip_func", "unequip_func");

}
string equip_func() {
    if (this_player()->query("stat/constitution") > 20) {
			return "the gloves seem to be doing nothing for you." ;
			}
      this_player()->set("stat/constitution" , 30);
	return "you feel more powerful already" ;
	}
string unequip_func() {
    this_player()->set("stat/constitution",(this_player()->query("base_stat/constitution")) );
	return "you feel weaker, somehow.";
	}
