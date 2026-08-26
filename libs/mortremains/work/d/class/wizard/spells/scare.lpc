/*
** File: scare.c  (Level 2 wizard charm spell)
** Cost: 12 SP's
** Credits:
**   09 Feb 98   Cyanide created the spell.
*/

#define COST 12
#define SYNTAX "Syntax: cast scare <at target>\n"

inherit SPELL;

int cast_scare (string str, int obj) {
    object target;
    int save;

    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();
    else target = present(str, environment(TP));
    if (!target) {
	write(SYNTAX);
	return 0;
    }

    seteuid(getuid());

if (!check_valid_targ(TP, target)) return 0;

    if (!obj) {
	obj = query_caster_level(TP, "wizard");
	if (cast_spell(TP, COST)) return 0;
    }

    save = target->save_throw();
    if (target->query_level() >= 6) save = 1;

    if (!save) {
	tell_object(target, "You are filled with a sudden sense of dread!\n");
	tell_room(environment(TP), target->query("cap_name")+
	  " suddenly shrieks in fear!\n");
	target->run_away();
	target->set("wimpy", 100);
    } else {
	tell_object(target, "You are filled with a sudden sense of dread!\n");
	write(target->query("cap_name")+" is unaffected.\n");
    }

    return 1;
}


string spellcraft() {
    return (@EndCraft
Scare (Level II | Wizard | Enchantment/Charm)

Range: 1 creature		Saving Throw: Negates

	This spell causes creatures with fewer than 6 levels of experience to fall 
into fits of trembling and shaking. The frightened creatures try to flee and 
may drop items held if encumbered. If cornered, they fight, but with penalties
to combat.
	Note that this spell has no effect on the undead (skeletons, zombies, ghouls,
and so on).
EndCraft
);
}

/* EOF */
