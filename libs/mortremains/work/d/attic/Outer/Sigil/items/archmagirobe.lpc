// Ilzarion.

#include <mudlib.h>

inherit ARMOR ;

void create() {
    set ("id", ({ "armor","robe", "robes" }) ) ;
    set ("short", "robes of the archmagi") ;
    set ("long", "Dark flowing magical robes.\n") ;
    set_armor_type("robes");
    set("armor_object", 1);
    set("bonus", 5);
    set("value",   5000);
    set("equip_func", "equip_func");
    set("unequip_func", "unequip_func");
    set("dest_at_sell", 1);
}

int equip_func() {

    this_player()->set("magic_resist", (this_player()->query("magic_resist") + 5) );
    return 1;
}
int unequip_func() {

    this_player()->set("magic_resist", (this_player()->query("magic_resist") - 5) );
    return 1;
}


