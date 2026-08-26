#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "Ice Whip");
    set("long", @Endtext
As you grip this weapon in your hand it nearly freezes. multiple prisms of
light reflect through the whip, creating a rainbow effect as you ready the
weapon.
Endtext
    );
    set("id", ({ "whip", "ice whip" }) );
    set_weapon_type("whip");

    // This needs to be set AFTER set_weapon_type()
    set("damage_type", "cold");

    set("name", "whip");
    set_verbs( ({ "attack" , "snap at" , "whip" }) );
    set("nosecond",0);
    set_bonus(2);
    set("value", 600);

} 
