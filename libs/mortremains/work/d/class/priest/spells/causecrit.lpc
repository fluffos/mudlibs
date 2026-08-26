/*
**  File: bolt.c (Lightning Bolt)
**  Purpose: Single target damage spell.
**  Cost: 7 SP (3rd lvl evocation)
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    21 Sep 97  Cyanide edited to be just "bolt"
*/

#define ROLL random(8)+random(8)+random(8)+random(8)+ \
             random(8)+random(8)+random(8)+random(8)+random(8)+9
#define COST 50
#define SYNTAX "Syntax: invoke causecrit at target\n"  

#include <p_spells.h>
#include <mudlib.h>

int lvl;
object room, caster, last_hit, *targs;

inherit SPELL;

varargs int invoke_causecrit (string str) {   
    object target;

    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write(SYNTAX);
	return 0;
    }     

    if (!check_valid_targ(TP, target)) return 0;

    if (!invoke_spell(TP, COST)) return 0;

    target->kill_ob(TP);

    lvl = TP->query_level("priest");
    write("You begin invoking Cause Critical Wounds...\n"+
      "Dark energies coalesce around your fingers.\n");
    say(TPN+" begins a prayer...\n"+
      "Dark energies coalesce around "+
      possessive(TP->query("gender"))+" fingers!\n");
    if (!TP->query_hit(target)) {
	write("You fail to hit your target with the dark energies.\n");
	say(TPN+" fails to hit!\n");
	return 1;
    }

    if (!check_magic_resist((TP->query_level("priest")), 
          target, COST, ROLL)) return;

    tell_room(environment(TP), TPN+" drains the life from "+
      target->query("cap_name")+"!\n", ({ TP, target }) );
    write("You drain the life from "+target->query("cap_name")+".\n");
    tell_object(target, TPN+" drains the life from you!\n");

    target->receive_damage(ROLL, "necromancy", TP);
    target->set("last_attacker", TP);
    return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Cause Critical Wounds (Priest - Level V - Necromantic)

Duration: instant 		Area of Effect: 1 Target
Cost: 50 TP

	This spell drains the life from a target struck.
EndSpellcraft
    );
}
