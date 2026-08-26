/* File: mask.c
** Purpose: To protect user from different war gasses.
** Date: Jan 21, 2000
** Random Note: NAZI hell layer (World War II)
** Credits: Lady Nsd, Mistress of Darkness.
*/

#include <mudlib.h>
#include <magic.h>

inherit ARMOR;

void create() {
    //short is what you see w/o an examine
set("author", "nsd");
    set("short", "gas mask");

    //long is what is seen when the object is examined. the @SuckMe
    //statement allows you to write a long description without useing
    // n\"+ all the time
    set("long", @Suckme
Gas mask. This will protect you against those lethal and
poisonous gasses launched during a war.
Suckme
    );

    //this allows a player to exa the item in more ways than 1
    set("id", ({ "mask", "gas mask"}) );

    //armor_type makes it a type of armor, thew other types can be found
    //in /doc/properties
    set_armor_type("helmet");
    set("equip_func", "equip_func");
    set("unequip_func", "unequip_func");
}
int equip_func() {
    this_player()->resistance("poison", 50);
    return 1;
}
int unequip_func() {
    this_player()->resistance("poison", 200);
    return 1;
}
