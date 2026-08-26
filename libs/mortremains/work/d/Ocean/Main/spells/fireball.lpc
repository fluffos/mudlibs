/*
**  File: bolt.c (Lightning Bolt)
**  Purpose: Single target damage spell.
**  Cost: 7 SP (3rd lvl evocation)
**  Note: PLEASE don't steal the damage messages from my spells.
**		Make up you own!
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    21 Sep 97  Cyanide edited to be just "bolt"
*/

#define ROLL random(6)+1
#define COST 7
#define SYNTAX "Syntax: cast fireball at target\n"  

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

// Prototypes:
void do_fireball (object, int);

int lvl;
object room, caster, *targs;

varargs int cast_fireball (string str, int obj) {   
    object target;
    int x;

    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write(SYNTAX);
	return 0;
    }     

    if (!check_valid_targ(TP, target)) return 0;
    if (!obj) {
	if (!cast_spell(TP, COST)) return 0;

	lvl = query_caster_level(TP, "wizard");
	obj = lvl;
	write("You begin casting Fireball...\n");
	say(TPN+" begins uttering arcane words...\n");

	tell_room(environment(TP), TPN+" hurls a huge ball of fire at "+
	  target->query("cap_name")+"!\n", ({ caster, target }) );
	write("You hurl a ball of fire at "+target->query("cap_name")+".\n");
	tell_object(target, TPN+" hurls a huge ball of fire at you!\n");
    } else {
	lvl = obj;
    }

#ifdef MAX_TO_SPELLS
    if (lvl>10) lvl=10;
#endif

    room = environment(target);

    targs = TP->query_current_attackers(this_object());
    if (!targs || !sizeof(targs)) targs = ({});

    if (member_array(target, targs)==-1) targs += ({ target });
    targs = filter_array(targs, "filter_targs", this_object());
    caster = TP;

    do_fireball(target, lvl);
    targs-=({ target });

    for (x = 0; x<sizeof(targs); x++)
	do_fireball(targs[obj], lvl);

    return 1;
}

void do_fireball (object victim, int level) {
    int dam=0, x;
    string name;

    for (x=0; x<level; x++)  dam+=ROLL;

    dam = spell_mult(dam);

    if (!victim) return;
    name = victim->query("cap_name");
    if (!check_magic_resist(level,victim,COST,dam)) return;

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
	    return;
	}
    }

    dam = victim->receive_damage(dam, "fire", caster);
    victim->kill_ob(caster);

    switch(dam) {
    case -10000..-1 :
	tell_room(room, "The naked flame actually heals "+name+"!\n",
	  victim);
	tell_object(victim, "The naked flame actually heals you!\n");
	break;
    case 0 : 
	tell_room(room, name+" stands unaffected by the inferno.\n",
	  victim);
	tell_object(victim, "You stand unaffected by the inferno.\n"+
	  "You just laugh.\n");
	break;
    case 1..12 :
	tell_room(room, name+"'s hair gets singed a bit.\n", victim);
	tell_object(victim, "Your hair gets singed a bit.\n");
	break;
    case 13..26 :
	tell_room(room, name+"'s body gets blistered.\n", victim);
	tell_object(victim, "Your body gets blistered.\n");
	break;
    case 27..42 :
	tell_room(room, wrap("Painfuls burns cover "+name+
	    "'s chest and arms."), victim);
	tell_object(victim, "Painful burns cover your chect and arms.\n");
	break;
    default :
	tell_room(room, wrap(name+"'s skin peels away and "+
	    possessive(victim->query("gender"))+" hair burns in the "+
	    "flames!"), victim);
	tell_object(victim, "Your skin peels away and your hair burns "+
	  "in the flames!\n");
	break;
    }
    victim->set("last_attacker", TP);
    return;
}

int filter_targs (object ob) {
    if (wizardp(ob) && ob->query("invisible")) return 0;
    if (ob->query("no_attack")) return 0;
    if (!random(3)) return 0;

    return 1;
}


string spellcraft() {
    return (@EndHelp
Fireball (Level III Wizard Spell - Evocation)

Category: Offensive               Cost: 7 SP

	A fireball is an explosive burst of flame, which detonates
with a low roar and delivers damage proportional to the level
of the wizard who cast it. This spell peaks at the tenth level
spell caster ability.
EndHelp
    );
}

/* EOF */
