// chainmail.c
// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());

    set ("id", ({ "chain", "chainmail" }) ) ;
    set ("short", "a suit of chainmail") ;
    set ("long", "The mail mesh would cover your torso and upper arms.\n") ;

    // All armor objects need to set a "type", ie suit, shield, helmet, boots,
    // whatever. The player can wear only one of each type of armor.
    set_armor_type("chain");
}
