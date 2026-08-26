
// Cyanide
// 3/3/00 11:19:00 AM 

inherit WEAPON;

void create() {
    set("short", "MS Gluon Force Rifle");
    set("long", @EndText
This highly advanced experimental anti-demon heavy rifle fires beams of
coherant, multiphasic anti-gluons which could theoretically crush even 
out-of-phase material, despite most forms of weapon resistance.
EndText
    );
    set("id", ({ "rifle", "gluon rifle", "force rifle", "gun" }) );
    set_weapon_type("gun/heavy");
    set_bonus(2,0,5);
    set("ammo_type", "E-clip");
    set("name", "MS Gluon Force Rifle");
    set("damage_type", "force");
    set("ammo_used", 7);
    set("dest_at_sell", 1);
    set_verbs( ({ "blast at" }) ); 
    set("damage", ({ 4, 20 }) );
    set("value", 7000);
}                   

int wield_func() {
    if (TP->query("stat/strength")<14) {
	write("That weapon is too heavy for you to wield.\n");
	return 0;
    } else {
	return 1;
    }
}              

/* EOF */
