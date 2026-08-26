// Cyanide
// 3/12/2000

inherit WEAPON;

void create() {
    set("short", "Webley 20mm autocannon");
    set("long", @EndLong
A standard light automatic cannon, designed for use with HEAP ammo 
30-round drums. It is known for its devastating effects, but cannot be
used in most cases without strength enhancement do to its excessive bulk.
EndLong
    );
    set("id", ({"gun", "autocannon", "webley"}) );
    set_weapon_type("gun/heavy");
    set("name", "Webley 20mm autocannon");
    set_verbs( ({ "blast", "shoot at" }) );
    set("natt_bonus", 2);
    set("ammo_used", 3);
    set("dest_at_sell", 1);
    set("ammo_type", "HEAP");
    set("damage", ({ 15, 25 }) );
    set("value", 5000);
}

int wield_func() {
    if (TP->query("stat/strength")<20) {
	write("That weapon is too heavy for you to wield.\n");
	return 0;
    } else {
	return 1;
    }
}
