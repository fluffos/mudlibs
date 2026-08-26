/*
**  File: tellblow.c
**  Tenser's Telling Blow
*/

#define ROLL random(10)+1
#define COST 120
#define SYNTAX "Syntax: cast tellblow at target\n"  

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

varargs int cast_tellblow (string str, int obj) {   
    object target;
    int x, dam = 0;
    string dam_type, color;

    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write(SYNTAX);
	return 0;
    }     

    if (!check_valid_targ(TP, target)) return 0;
    if (!obj) {
	obj = query_caster_level(TP, "wizard");
	if (!cast_spell(TP, COST)) return 0;
    }
    write("You begin casting Tenser's Telling Blow...\n");
    say(TPN+" raises"+possessive(TP->query("gender"))+
      " hands, and begins screaming in an ancient language!\n");

    if (!check_magic_resist(obj,target,COST,1000)) return;

    dam_type = "force";
    for (x=1; x<=obj; x++) dam+=ROLL;
    dam = spell_mult(dam);

    if (userp(target) && target->query_save(-6)) dam /= 2;

    message("spell", TPN+" calls down great wizardly magics!\n", ({ environment(TP) }) );
    message("spell", "You are shredded by pure force!\n",
      ({ target }) );
    dam = target->receive_damage(dam, dam_type, TP);
    target->set("last_attacker", TP);
    target->kill_ob(TP);

    return 1;
}

string spellcraft() {
    return (@EndSC
Tenser's Telling Blow (Invocation, 10th Level Mage Spell)

Cost: 120 Spell Points          Area of Effect: 1 attacker

	Tenser's most powerful spell calls down a pillar of force
upon a target attacking the caster, inflicting massive damage.
EndSC
    );
}
