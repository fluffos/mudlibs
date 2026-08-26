#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "Stone Dagger");
    set("long", @Endtext
This dagger has a hilt made of granite, and the edge of the blade has been
sharpened with diamond dust. It also has been engraved with magical sigils
to aid its user in combat.
Endtext
    );
    set("id", ({ "dagger", "stone dagger" }) );
    set_weapon_type("knife");
    set("name", "dagger");
    set_verbs( ({ "attack" , "slice at" , "thrust at" }) );
    set("nosecond",0);
    set_bonus(1);
    set("value", 800);

}
