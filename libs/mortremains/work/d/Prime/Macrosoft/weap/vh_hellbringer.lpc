// Cyanide
// 8/24/99 4:32:24 PM 

inherit WEAPON;

void create() {
    set("short", "Hellbringer Cyborg Heavy Pistol");
    set("long", wrap(
	"Magnum Opus' massive double-action revolver holds only "+
	"three rounds in its solid titanium-steel cylinder, but "+
	"each one is a 13mm UltraMax man-killer. Its a break-action "+
	"design, engaged by a left-side thumb button. The entire "+
	"handgun is composed of ultrastrong hybrid alloys and the "+
	"ported barrel has a heavy full-length underlug for "+
	"balance."
      ) );
    set("id", ({"gun","pistol","hellbringer"}) );
    set_weapon_type("gun/pistol");
    set("name", "Hellbringer Pistol");
    set_verbs( ({ "blast", "shoot at" }) );
    set("ammo_type", "13mm UMX");
    set("dest_at_sell", 1);
    set("damage", ({ 10, 29 }) );
    set("value", 2000);
}

int wield_func() {
    if (TP->query("stat/strength")<18) {
	write("That weapon is too heavy for you to wield.\n");
	return 0;
    } else {
	return 1;
    }
}
