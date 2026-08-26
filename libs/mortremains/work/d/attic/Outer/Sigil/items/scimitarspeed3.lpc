// Ilzarion's scimitar of speed.
// Cyanide put a limit on the number that exist, 3 Jul 98

#define NUMBER_ALLOWED 3

#include <mudlib.h>

inherit WEAPON;

void create() {
    int num; 

    set_weapon_type("sword/long");
    set("id", ({ "scimitar", "sword" }) );
    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
    set("prevent_sig", 1);

    // This is the important bit.
    num = NUMBER_ALLOWED + 1;

    if (sizeof(children(base_name(TO))) <= num && random(3)) {
	set_bonus(3);
	set("value", 5600);
	set("dest_at_sell", 1);
	set("short", "scimitar of speed");
	set("long", @LONG
This weapon is used mostly by experienced swordmasters.
It is unusually light and fast.
LONG
	);
	set("name", "scimitar of speed");
	set("natt_bonus", 1);

    } else {

	set_bonus(2);
	set_weapon_type("sword/long");
	set("value",   1100);
	set("short", "enchanted scimitar");
	set("long", @LONG
This is a magically enhanced scimitar.
LONG
	);
	set("name", "scimitar");
    }
}
