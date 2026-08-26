/*
**  File: bolt.c (Lightning Bolt)
**  Purpose: Single target damage spell.
**  Cost: 7 SP (3rd lvl evocation)
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    21 Sep 97  Cyanide edited to be just "bolt"
**    11 Jul 00  Cyanide converted the priest version.
*/

#define ROLL random(6)+1
#define COST 7
#define SYNTAX "Syntax: invoke bolt at target\n"

#include <p_spells.h>
#include <mudlib.h>

// Prototypes:
void do_lightning (object, int);

object caster, room;

inherit SPELL;

varargs int invoke_bolt (string str, int obj) {
    object target;

    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write(SYNTAX);
	return 0;
    }     

    if (!check_valid_targ(TP, target)) return 0;

    caster = TP;

    if (!obj) {
	obj = query_caster_level(TP, "priest");
	if (!invoke_spell(TP, COST)) return 0;

	room = environment(TP);

	write("You begin casting Lightning Bolt...\n"+
	  "Electricity begins crackling between your fingers.\n");
	say(TPN+" begins uttering arcane prayers...\n"+
	  "Electricity begins crackling between "+
	  possessive(TP->query("gender"))+" fingers!\n");

	tell_room(room, TPN+" hurls a lightning bolt at "+
	  target->query("cap_name")+"!\n", ({ caster, target }) );
	write("You hurl a lightning bolt at "+target->query("cap_name")+".\n");
	tell_object(target, TPN+" hurls a lightning bolt at you!\n");
    }

    do_lightning(target, obj);
    return 1;
}

void do_lightning (object victim, int lvl) {
    int dam=0, x, tmp=lvl;
    string name;

#ifdef MAX_TO_SPELLS
    if (tmp>12) tmp=12;
#endif

    for (x=0; x<tmp; x++)  dam+=ROLL;
    dam = spell_mult(dam);
    if (!victim) return;

    name = victim->query("cap_name");
    if (!check_magic_resist(lvl,victim,COST,dam)) return;
    x = 0;
    // x = query_save_mod(caster,victim, ({"evocation"}) );
    // x = victim->save_throw(x);

    if (x) {
	dam/=2;
	if (victim->query_skill("Evasion")) {
	    tell_room(environment(victim), victim->query("cap_name")+
	      " dodges the bolt!\n", ({ caster, victim }) );
	    tell_object(victim, "You manage to dodge the bolt!\n");
	    write(victim->query("cap_name")+" nimbly dodges your bolt!\n");
	    return;
	}
    }

    dam = victim->receive_damage(dam, "electricity", caster);
    victim->kill_ob(caster);

    switch(dam) {
    case -1000..-1 :
	tell_room(room, "The raw energy actually heals "+name+"!\n",
	  victim);
	tell_object(victim, "The raw energy actually heals you!\n");
	break;
    case 0 : 
	tell_room(room, name+" just laughs at the spell's puny energies.\n",
	  victim);
	tell_object(victim, "The spell leaves you unscathed.\n"+
	  "You just laugh.\n");
	break;
    case 1..10 :
	tell_room(room, name+" gets shocked slightly.\n", victim);
	tell_object(victim, "You get a small but painful shock.\n");
	break;
    case 11..21 :
	tell_room(room, name+" jerks as the electricity courses through "+
	  possessive(victim->query("gender"))+" body.\n", victim);
	tell_object(victim, "Your body jerks as the electricity "+
	  "courses through you.\n");
	break;
    case 22..31 :
	tell_room(room, name+" grits "+possessive(victim->query("gender"))+
	  " teeth against the pain of the lightning.\n", victim);
	tell_object(victim, "You grit your teeth against the excruciating"+
	  " pain!\n");
	break;
    case 32..41 :
	tell_room(room, "The stench of "+name+"'s burnt hair and charred"+
	  " flesh fills the room!\n", victim);
	tell_object(victim, "The stench of your burnt hair and charred"+
	  " flesh fills the room!\n");
	break;
    default :
	tell_room(room, wrap(name+" screams in mortal pain and outrage"+
	    " as "+possessive(victim->query("gender"))+" flesh practically"+
	    " melts from "+possessive(victim->query("gender"))+" bones!"),
	  victim);
	tell_object(victim, wrap("You scream in mortal pain and outrage"+
	    " as your flesh practically melts from your bones!"));
	break;
    }
    victim->set("last_attacker", TP);
    return;
}


string spellcraft() {
    return (@EndHelp
Lightning Bolt (Level III Wizard Spell - Evocation)

Category: Offensive               Cost: 7 SP
Area of Effect: 1 Target

	Upon casting this spell, the priest releases a powerful 
stroke of electrical energy that inflicts damage proportional
to the level of the priest who cast it. 
EndHelp
    );
}

/* EOF */
