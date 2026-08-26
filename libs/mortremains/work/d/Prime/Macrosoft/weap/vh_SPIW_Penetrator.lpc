
// Cyanide
// 8/25/99 9:24:13 AM

inherit WEAPON;

void create() {
    set("short", "SPIW Penetrator");
    set("long", @EndText
This massive rifle is chambered for the 15mm cannon round. The Penetrator
is fired from an over-the-shoulder position, where a large recoil-absorbing
rod absorbs a great deal of the recoil energy. Popular with many ESWAT 
teams the world over for its kinetic penetrating power.
EndText
    );
    set("id", ({ "gun", "penetrator", "spiw" }) );
    set_weapon_type("gun/heavy");
    set("ammo_type", "15mm");
    set("ammo_used", 2);
    set("name", "SPIW Penetrator");
    set_verbs( ({ "shoot at" }) ); 
    set("damage_type", "piercing");
    set("damage", ({ 4, 40 }) );
    set("dest_at_sell", 1);
    set("value", 5000);
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
