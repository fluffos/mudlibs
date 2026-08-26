/*
**  File: coldcone.c (Cone of Cold)
**  Purpose: Single target damage spell.
**  Cost: 16 SP (5th lvl evocation)
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    21 Nov 97  Cyanide edited to be just "coldcone"
*/

#define ROLL random(4)+2
#define COST 16
#define SYNTAX "Syntax: cast coldcone at target\n"  

#include <m_spells.h>
#include <mudlib.h>
#include <magic.h>

// Prototypes:
int do_coldcone (object, int);

int lvl;
object room, caster, *targs;

inherit SPELL;

varargs int cast_coldcone (string str, int obj) {   
    object target;
    int x;

    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write(SYNTAX);
	return 0;
    }     

    if (!check_valid_targ(TP, target)) return INVALID_TARGET;
    if (!obj) {
	if (!cast_spell(TP, COST)) return NO_STRENGTH;
	TP->set("power_delay", 1);

	lvl = query_caster_level(TP, "wizard");
	obj = lvl;
	write("You begin casting Cone of Cold...\n");
	say(TPN+" begins uttering arcane words...\n");

	tell_room(environment(TP), TPN+" blasts a cone of freezing cold at "+
	  target->query("cap_name")+"!\n", ({ caster, target }) );
	write("You blast a cone of freezing cold at "+
	  target->query("cap_name")+".\n");
	tell_object(target, TPN+" blasts you with a cone"+
	  " of freezing cold!!\n");
    } else {
	lvl = obj;
    }

    room = environment(TP);
    caster = TP;

    return do_coldcone(target, obj);
}

int do_coldcone (object victim, int level) {
    int dam=0, x;
    string name;

#ifdef MAX_TO_SPELLS
    if (level > 15) level = 15;
#endif

    for (x=0; x<level; x++)  dam+=ROLL;

    if (!victim) return 0;
    dam = spell_mult(dam);
    name = victim->query("cap_name");
    if (!check_magic_resist(level,victim,COST,dam)) 
	return MAGIC_RESISTANCE;

    x=0;
    // x = query_save_mod(caster,victim, ({"evocation"}) );
    // x = victim->save_throw(x);

    if (x) {
	dam/=2;
	if (victim->query_skill("Evasion")) {
	    tell_room(environment(victim), victim->query("cap_name")+
	      " manages to find cover!\n", ({ caster, victim }) );
	    tell_object(victim, "You manage to find cover!\n");
	    write(victim->query("cap_name")+" jumps aside and finds cover!\n");
	    return SAVED;
	}
    }

    dam = victim->receive_damage(dam, "cold", caster);
    victim->kill_ob(caster);

    switch(dam) {
    case -10000..-1 :
	tell_room(room, "The elemental cold actually heals "+name+"!\n",
	  victim);
	tell_object(victim, "The elemental cold actually heals you!\n");
	break;
    case 0 : 
	tell_room(room, name+" stands unaffected by the chill.\n",
	  victim);
	tell_object(victim, "You stand unaffected by the chill.\n"+
	  "You just laugh.\n");
	break;
    case 1..15 :
	tell_room(room, name+" is only slightly frozen.\n", victim);
	tell_object(victim, "You are slightly frozen.\n");
	break;
    case 16..30 :
	tell_room(room, name+"'s extremities are slightly numbed.\n", victim);
	tell_object(victim, "Your extremities feel numb from the cold.\n");
	break;
    case 31..45 :
	tell_room(room, wrap(name+" is affected with terrible frostbite!"),
	  victim);
	tell_object(victim, "You are affected with terrible frostbite!\n");
	break;
    case 46..60 :
	tell_room(room, wrap(name+"'s skin cracks and bleeds from the cold!"),
	  ({ victim }) );
	tell_object(victim, "Your skin cracks and bleeds from the cold!\n");
	break;
    case 61..75 :
	tell_room(room, wrap(name+" is frozen to the very core!"), victim);
	tell_object(victim, "You are frozen to your very core!\n");
	break;
    default :
	tell_room(room, wrap(name+"'s skin freezes solid in the cold!"),
	  victim);
	tell_object(victim, "Your skin freezes solid in the cold!\n");
	break;
    }
    victim->set("last_attacker", TP);
    return SPELL_CAST;
}


string spellcraft() {
    return (@EndHelp
Cone of Cold (Level V Wizard Spell - Evocation)

Area of Effect: 1 Target		Cost: 16 SP

	When this spell is cast, it causes a cone-shaped area of
extreme cold, originating at the wizard's hand and extending 
outward towards the target. It drains heat and causes damage 
proportional to the level of the wizard who cast it. 
EndHelp
    );
}

/* EOF */
