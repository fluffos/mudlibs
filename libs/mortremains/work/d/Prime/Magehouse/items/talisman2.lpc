inherit ARMOR;

void create() {
    set("short", "Talisman of the Void");
    set("long", @EndLong
Silvery script carefully etched to form symbols of
power make this talisman a thing of beauty.
EndLong
);
    set("id", ({ "amulet", "talisman",  "#REFLEXIVE_SPELL#"}) );
    set_armor_type("amulet");
}

int reflex (
  int damage,   // damage that would be taken
  string type, // Damage type
  object attacker,   // WHo did the damage
  int weap  // if this == 1, was done by a hand help weapon
) {

    if (type=="slashing" || type=="piercing" ||
      type=="bludgeoning" ) {
	return 0;
    }
    return damage;
}

/* EOF */
