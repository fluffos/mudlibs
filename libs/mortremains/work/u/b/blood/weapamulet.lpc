inherit ARMOR;

void create() {
    set("short", "Amulet of the Void");
    set("id", ({ "amulet", "#REFLEXIVE_SPELL#"}) );
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
