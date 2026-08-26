
// Cyanide
// 8/25/99 9:24:13 AM

inherit WEAPON;

void create() {
    set("short", "Magnum Opus Heavy Gravity Gun"); 
    set("long", @EndText
Magnum Opus' is known for their super-heavy weaponry, and this unusual 
weapon is a notable example. It functions by firing blasts of gravitons
to crush an enemy under its own weight. It is also particularly useful
because the nonphasic nature of gravitons allow the weapon to hit even
weapon resistnat creatures.
EndText
    );
    set("id", ({ "gun", "gravity gun" }) );
    set_weapon_type("gun/heavy");
    set("ammo_type", "E-clip");
    set("damage_type", "crushing");
    set("ammo_used", 3);
    set("dest_at_sell", 1);
    set("name", "Gravity Gun");
    set_verbs( ({ "crush" }) ); 
    set("damage", ({ 3, 20 }) );
    set_bonus(0, 0, 3);
    set("value", 5000);
}                   

int hit_func (object attacker, int damage) {
    damage *= (int)attacker->query("size");
    damage /= (int)attacker->query("SIZE");

    return damage;
}    

int wield_func() {
    if (TP->query("stat/strength")<15) {
	write("That weapon is too heavy for you to wield.\n");
	return 0;
    } else {
	return 1;
    }
}              

/* EOF */
