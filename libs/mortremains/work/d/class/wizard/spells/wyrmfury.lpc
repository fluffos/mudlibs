/*
**  File: wyrmfury.c (Fury of the Wyrms)
**  Purpose: Single target damage spell.
**           Originally coded as the signature spell for Yazatu.
**  Cost:  SP (3rd lvl evocation)
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    22 Apr 98  Cyanide created the file.
*/

#define ROLL random(12)+1
#define COST 300
#define SYNTAX "Syntax: cast wyrmfury at target\n"  

#include <m_spells.h>
#include <mudlib.h>

mapping DRAGONS = ([
"black" : "acid",
"blue" : "electricity",
"green" : "poison",
"red" : "fire",
"white" : "cold"
]);


inherit SPELL;

varargs int cast_wyrmfury (string str, int obj) {   
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

	write("You begin casting Fury of the Wyrm...\n");
	say(TPN+" raises"+possessive(TP->query("gender"))+
	  " hands, and begins screaming in an ancient language!\n");

	TP->set("power_delay", 2);

    }

    x = random(sizeof(DRAGONS));
    color = (keys(DRAGONS))[x];
    dam_type = (values(DRAGONS))[x];
    for(x=1; x<=obj; x++) dam += ROLL;

    if (userp(target) && target->query_save(-6)) dam /= 2;

    message("spell", "In a sudden blast of wind, a great "+
      color+" dragon appears!\n", ({ environment(TP) }) );
    message("spell", "You are paralyzed in terror!\n",
      ({ target }) );
    message("spell", "It breathes deadly "+dam_type+
      " upon "+target->query("cap_name")+", and flies off!\n",
      ({ environment(TP) }), ({ target }) );
    message("spell", "It breathes deadly "+dam_type+
      " upon you, and flies off!\n", ({ target }) );

    target->block_attack(1);
    target->set("no_move", 1);
    target->kill_ob(TP);

    dam = spell_mult(dam);
    dam = target->receive_damage(dam, dam_type, TP);
    target->set("last_attacker", TP);
    target->kill_ob(TP);

    return 1;
}

string spellcraft() {
    return (@EndSC
Fury of the Wyrms (Conjuration, 10th Level Mage Spell)

Cost: 300 Spell Points           Area of Effect: 1 attacker

	This massive spell, researched by the Great Yazatu, was 
the first spell above 9th level known to mortals.
    It conjures an ancient dragon of a random type from somewhere
else in the multiverse, and convinces it to attack the caster's
enemies. It inflicts massive damage and paralyses its victims in
fear (briefly) without regard to magic resistance or other normal
abilities. The only drawback is that the caster never is quite 
sure what dragon he/she will summon.
EndSC
    );
}
