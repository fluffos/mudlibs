
// Cyanide
// 8/25/99 9:24:13 AM

inherit WEAPON;

void create() {
    set("short", "Macrosoft Lightning Blaster");
    set("long", @EndText
This experimental weapon is the product of Macrosoft's recent exploration
of technowizardy in offensive applications.
EndText
    );
    set("id", ({ "gun", "blaster", "lightning blaster" }) );
    set_weapon_type("gun/heavy");
    set("dest_at_sell", 1);
    set("ammo_type", "E-clip");
    set("ammo_used", 4);
    set("name", "Macrosoft Lightning Blaster");
    set_verbs( ({ "blast at" }) ); 
    set("damage_type", "electricity");
    set("damage", ({ 4, 29 }) );
    set("damage", 4500);
}                   

int wield_func() {
    if (TP->query("stat/strength") < 14) {
	write("That weapon is too heavy for you to wield.\n");
	return 0;
    } else {
	return 1;
    }
}              

/* EOF */
