//towel.c
// A towel you can wear to be inside the sauna.
//Created by Nsd  march 9, 2000

#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());

    set ("id", ({ "towel" }) ) ;
    set ("short", "a clean white towel") ;
    set ("long", "A clean white towel ready for your use. You can wear it.\n");

    // All armor objects need to set a "type", ie suit, shield, helmet, boots,
    // whatever. The player can wear only one of each type of armor.
    set_armor_type("robes");
}
