// Dispater's Staff
// It has a special, and give 10% mr when wielded.

inherit WEAPON;

object owner;

#include "/u/c/cyanide/debug.h"

void create() {
    set("short", "Dispater's Staff");
    set("long", wrap("This is a single, solid forged staff of what "+
	"appears to be aluminum, etched over its entire surface with "+
	"strange runes and sigils.") );
    set("id", ({ "staff", "dispaters staff" }) );
    set("name", "Dispater's Staff");
    set_verbs(({ "beat" }) );
    set("nosecond", 1);
    set_weapon_type("quarterstaff");
    set_bonus(3);
    set("dest_at_sell", 1);
    set("value", 10000);
}

int hit_func ( object targ, int dmg ) {
    if (!random(5)) {
	object env = environment(environment(TO));
	if (env)
	    message("combat", "Dispater's Staff glows brightly for a moment!\n",
	      all_inventory(env));
	dmg = random(21) + 4;
    }

    return dmg;
}

int wield_func() {
    owner = TP;

    tell_object(owner, "You feel a field of protection against "+
      "magic encircle you.\n");
    owner->add("magic_resist", 10);
    return 1;
}

int unwield( int silent ) {
    if (owner) {
	tell_object(owner, "You feel the protection leave you as you "+
	  "unwield Dispater's Staff.\n");
	owner->add("magic_resist", -10);
    }

    return ::unwield(silent);
}

