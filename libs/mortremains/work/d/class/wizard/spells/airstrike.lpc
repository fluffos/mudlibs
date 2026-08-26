/*
**  File: airstrike.c
**  Purpose: Single target damage spell.
**  Cost: 300 SP (10th lvl evocation)
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    21 Sep 97  Cyanide edited to be just "bolt"
*/

#define ROLL random(20)+1
#define COST 300
#define SYNTAX "Syntax: cast airstrike at target\n"  

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

// Prototypes:
void do_airstrike (object, int);

int lvl;
object room, caster, *targs;

varargs int cast_airstrike (string str, int obj) {   
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
	if (!cast_spell(TP, COST, 1)) return 0;

	lvl = query_caster_level(TP, "wizard");
	obj = lvl;
	write("You pull a radio and request an air strike!\n");
	say(TPN+" pulls out a radio and requests an air strike!\n");

	tell_room(environment(TP), "A sqadron of fighters swarm down at "+
	  target->query("cap_name")+"!\n", ({ caster, target }) );
	tell_object(target, TPN+" calls a tactical strike on your ass!\n");
    } else {
	lvl = obj;
    }

#ifdef MAX_TO_SPELLS
    if (lvl > 30) lvl = 30;
#endif

    room = environment(target);

    targs = TP->query_current_attackers(this_object());
    if (!targs || !sizeof(targs)) targs = ({});

    if (member_array(target, targs)==-1) targs += ({ target });
    targs = filter_array(targs, "filter_targs", this_object());
    caster = TP;

    do_airstrike(target, lvl);
    targs-=({ target });

    for (x = 0; x<sizeof(targs); x++)
	do_airstrike(targs[obj], lvl);

    return 1;
}

void do_airstrike (object victim, int level) {
    int dam=0, x;
    string name, type;

    for (x=0; x<level; x++)  dam+=ROLL;

    dam = spell_mult(dam) / 2;

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

    x = victim->receive_damage(dam, "crushing", caster);
    x += victim->receive_damage(dam, "fire", caster); 
    victim->kill_ob(caster);

    switch(x) {
    case -10000..-1 :
	tell_room(room, "The furious attack actually heals "+name+"!\n",
	  victim);
	tell_object(victim, "The naked flame actually heals you!\n");
	break;
    case 0 : 
	tell_room(room, name+" stands unaffected by the attack!\n",
	  victim);
	tell_object(victim, "You stand unaffected by the attack!\n"+
	  "You just laugh.\n");
	break;
    default :
	tell_room(room, name+" is assaulted by a massive airstrike!\n", 
	  victim);
	tell_object(victim, "You are assaulted by a massive airstrike!\n");
	break;
    }
    victim->set("last_attacker", TP);
    return;
}

int filter_targs (object ob) {
    if (wizardp(ob) && ob->query("invisible")) return 0;
    if (ob->query("no_attack")) return 0;
    if (ob->query("summoner") == TP) return 0;
    if (!random(3)) return 0;

    return 1;
}


string spellcraft() {
    return (@EndHelp
Fireball (Level X Wizard Spell - Evocation)

Category: Offensive               Cost: 300 SP

This spell, research by the legendary Hoss, creates a squadon of spectral
fighters which unleash all their firepower at one target, and has the 
potiential to damage every other creature in the room. It's potential for
carnage is unrivaled.	
EndHelp
    );
}

/* EOF */
