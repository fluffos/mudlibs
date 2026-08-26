/*
**  File: necrobolt.c (Necromantic Bolt)
**  Purpose: Single target damage spell.
**  Cost: 7 SP (3rd lvl evocation)
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    21 Sep 97  Cyanide edited to be just "bolt"
**     6 Dec 98  Nightmask edited original bolt.c file for this.
*/

#define ROLL random(6)+1
#define COST 7
#define SYNTAX "Syntax: cast necrobolt at target\n"  

#include <m_spells.h>
#include <mudlib.h>

// Prototypes:
void do_lightning (object, int);

object caster, room;

inherit SPELL;

varargs int cast_necrobolt (string str, int obj) {   
    object target;

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

	write("You begin casting Necromantic Bolt...\n"+
	  "Your hands fill with negative energy.\n");
	say(TPN+" begins uttering arcane words...\n"+
	  "a thick blackness engulfs "+
	  possessive(TP->query("gender"))+" hands!\n");

	tell_room(environment(TP), TPN+" hurls a black beam of light at "+
	  target->query("cap_name")+"!\n", ({ caster, target }) );
	write("You hurl a necromantic bolt at "+target->query("cap_name")+".\n");
	tell_object(target, TPN+" hurls a black beam of light at you!\n");
    }

    caster = TP;
    room = environment(TP);

    do_lightning(target, obj);
    return 1;
}

void do_lightning (object victim, int lvl) {
    int dam=0, x, tmp=lvl;
    string name;

#ifdef MAX_TO_SPELLS
    if (tmp>12) tmp = 12;
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


    dam = victim->receive_damage(dam, "necromancy", caster);
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
	tell_room(room, name+" manages to evade most of the bolt.\n", victim);
	tell_object(victim, "The bolt just barely brushes you.\n");
	break;
    case 11..21 :
	tell_room(room, name+" sutmbles back as the bolt hits "+
	  possessive(victim->query("gender"))+" in the chest.\n", victim);
	tell_object(victim, "You get hit in the chest with the beam.\n"); 
	break;
    case 22..31 :
	tell_room(room, name+" holds "+possessive(victim->query("gender"))+
	  " chest as the beam shoots through them.\n", victim);
	tell_object(victim, "You hold you chest and cry in agony as the beam"+
	  " rips through your chest!\n");
	break;
    case 32..41 :
	tell_room(room, "The screams of "+name+"'s torment echo through"+
	  " your ears, as the bolt slams into their head!\n", victim);
	tell_object(victim, "The bolt slams into your head, causeing you"+
	  " to scream in pain!\n");
	break;
    default :
	tell_room(room, wrap(name+" screams in pain and torrment"+
	    " as "+possessive(victim->query("gender"))+" flesh practically"+
	    " melts from "+possessive(victim->query("gender"))+" face!"),
	  victim);
	tell_object(victim, wrap("You scream in pain and torrment"+
	    " as your flesh practically melts from your face!"));
	break;
    }
    victim->set("last_attacker", TP);
    return;
}


string spellcraft() {
    return (@EndHelp
Necromantic Bolt (Level III Wizard Spell - Necromancy)

Category: Offensive               Cost: 7 SP
Area of Effect: 1 Target

	Upon casting this spell, the wizard releases a powerful 
bolt of necromantic energy that inflicts damage proportional
to the level of the wizard who cast it. 
EndHelp
    );
}

/* EOF */
