// A ring of invisibility..

#include <mudlib.h>

inherit ARMOR ;

void create() {
       set ("id", ({ "ring", "ring of invisibility" }) ) ;
        set ("short", "a ring of invisibility") ;
        set ("long", "this ring was made from a single strand of steel.
        the magical symbols engraved were enhansed as the souls of the
        sprites of parlm were used.\n") ;
        set ("mass", 1) ;
        set_armor_type("ring") ;
        set("enchantment", 3);
set("size", -1); 
set("value",   1500);
	set("equip_func", "equip_func");
		set("unequip_func", "unequip_func");
}

	int equip_func() {
	
        this_player()->set("invisible", 1);
       tell_object(this_player(), "Your form fades from view!.\n");
        say(this_player()->query("cap_name")+"'s form fades from view!\n");
       return 1;
	}
	int unequip_func() {
	
        this_player()->set("invisible", 0);
        write("Your form fades back into view!\n");
        say(this_player()->query("cap_name")+ " fades in from the shadows!\n");
        return 1;
	}

