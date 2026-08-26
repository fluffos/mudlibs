#include <mudlib.h>

inherit WEAPON;

void create() {
seteuid(getuid());
set("name", "sword");
set_weapon_type("sword/long");
set_material_type("metal/iron");
set("id", ({ "pin", "sword" }) );
set("short", "Moltars Mighty Pin of God Slaying");
set("damage", ({ 10000,100000 }) );
set("long", @MOLTAR
A decorated long sword which is charged with the 
ability to destroy whomever Moltar chooses
MOLTAR
);
set_bonus(5,30,5);
set("nosecond", 0);
set_verbs( ({ "cut", "cleave", "swing at", "slice at" }) );
set_verbs2( ({ "cuts", "cleaves into", "swings at", "slices at"}) );
}
