/*
**  File: wilting.c (Abi-Dalzim's Horrid Wilting)
**  Purpose: Single target damage spell.
**  Cost: 30 SP (8th lvl evocation/necromancy)
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    22 Nov 97  Cyanide edited to be just "wilting"
*/

#define ROLL random(8)+1
#define COST 30
#define SYNTAX "Syntax: cast wilting at target\n"  

#include "/u/c/cyanide/debug.h"
#include <m_spells.h>
#include <mudlib.h>
#include <magic.h>

// Prototypes:
int do_wilting (object, int);

int lvl;
object caster;

inherit SPELL;

varargs int cast_wilting (string str, int obj) {   
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
	write("You begin casting Abi-Dalzim's Horrid Wilting at "+
	  target->query("cap_name")+"\n");
	say(TPN+" begins uttering arcane words...\n");

	tell_room(environment(TP), TPN+" points at "+
	  target->query("cap_name")+"!\n", ({ caster, target }) );
	tell_object(target, TPN+" points at you!\n");
    } else {
	lvl = obj;
    }

    caster = TP;

    return do_wilting(target, lvl);
}

int do_wilting (object victim, int level) {
    int dam=0, x;
    string name, poss;
    object room;

#ifdef MAX_TO_SPELLS
    if (lvl > 18) lvl = 18;
#endif

    for (x=0; x<lvl; x++)  dam+=ROLL;

    dam = spell_mult(dam);

    if (!victim) return;
    room = environment(victim);
    name = victim->query("cap_name");
    poss = possessive(victim->query("gender"));

    if (!check_magic_resist(level,victim,COST,dam)) return MAGIC_RESISTANCE;

    x=0;
    // x = query_save_mod(caster,victim, ({ "necromancy", "evocation"}) );
    // x = victim->save_throw(x); 

    //if (x) dam/=2;

    dam = victim->receive_damage(dam, "dehydration", caster);
    victim->kill_ob(caster);

    switch((dam*3)/2) {
    case -10000..-1 :
	tell_room(room, "The dehydration actually heals "+name+"!\n",
	  victim);
	tell_object(victim, "The dehydration actually heals you!\n");
	break;
    case 0 : 
	tell_room(room, name+" is completely unaffected.\n",
	  victim);
	tell_object(victim, "You are completely unaffected.\n"+
	  "You just laugh.\n");
	break;
    case 1..29 :
	tell_room(room, name+" ignores the spell.\n", victim);
	tell_object(victim, "You simply ignore the spell.\n");
	break;
    case 30..58 :
	tell_room(room, name+" seems only slightly hurt.\n", victim);
	tell_object(victim, "You are suddenly stuck with a terrible headache.\n");
	break;
    case 59..87 :
	tell_room(room, iwrap(name+" is greatly dehydrated, making "+
	    possessive(victim->query("gender"))+" skin wrinkled and cracked."),
	  victim);
	tell_object(victim, iwrap("You are greatly dehydrated, making "+
	    " your skin wrinkled and cracked."));
	break;
    case 88..116 :
	tell_room(room, iwrap("The moisture is sucked from "+name+"'s body, and much"+
	    " of "+possessive(victim->query("gender"))+
	    " skin falls away as dust!"), victim);
	tell_object(victim, iwrap("The moisture is sucked from your body, and much of"+
	    " your skin falls away as dust!"));
	break;
    case 117..145 :
	tell_room(room, iwrap(name+" howls in agony as huge amounts of "+
	    possessive(victim->query("gender"))+" flesh fall away"+
	    " as black dust!"), victim);
	tell_object(victim, iwrap("You howl in agony as huge amount of your flesh falls"+
	    " away as black dust!"));
	break;
    default :
	tell_room(room, iwrap(name+" looks on in fear as huge chucks of flesh "+
	    "are turned to dust, exposing bones and vital organs!"), ({ victim }) );
	tell_object(victim, iwrap("You look on in fear as huge chucks of flesh "+
	    "are turned to dust, exposing bones and vital organs!"));
	break;
    }
    victim->set("last_attacker", TP);
    return SPELL_CAST;
}



string spellcraft() {
    return (@EndHelp
Abi-Dalzim's Horrid Wilting (Level VIII Wizard Spell - 
                              Alteration, Necromancy)

Area of Effect: 1 Target		Cost: 30 SP

This spell evaporates moisture from the body of its living 
target, inflicting terrible damage per level of the caster.
Affected creatures are reduced to a dessicated corpse.
	
EndHelp
    );
}

/* EOF */
