/*
ilz coded this
*/

#define ROLL random(8)+random(8)+random(8)+3
#define COST 8
#define SYNTAX "Syntax: invoke causelt at target\n"  

#include <p_spells.h>
#include <mudlib.h>

// Prototypes:
void do_lightning (object);

int lvl;
object room, caster, last_hit, *targs;

inherit SPELL;

varargs int invoke_causelt (string str) {   
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
    write("You begin casting cause light wounds...\n"+
      "Dark energies coalesce around your fingers.\n");
    say(TPN+" begins a prayer...\n"+
      "Dark energies coalesce around "+
      possessive(TP->query("gender"))+" fingers!\n");
    if (!TP->query_hit(target)) {
	write("You fail to hit your target with the dark energies.\n");
	say(TPN+" fails to hit!\n");
	return 1;
    }

    if (!check_magic_resist((TP->query_level("priest")), target, COST, ROLL)) 
	return;

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
Cause Light Wounds (Priest - Level I - Necromantic)

Duration: instant 		Area of Effect: 1 Target
Cost: 8 TP

	This spell drains the life from a target struck.
EndSpellcraft
    );
}


