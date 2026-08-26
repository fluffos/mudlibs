/*
**  File: bolt.c (Lightning Bolt)
**  Purpose: Single target damage spell.
**  Cost: 7 SP (3rd lvl evocation)
**  Note: PLEASE don't steal the damage messages from my spells.
**		Make up you own!
**  Credits:
**    11 Aug 97  Cyanide created the file.
**    21 Sep 97  Cyanide edited to be just "bolt"
**    10 Jun 99  Gasman modified for kung fu
**    10 Jun 99  Gasman Cost to be dependent on kunfu_level 
*/

#define ROLL random(6)+1
#define COST (int)this_player()->query("kungfu_level") * 3
#define SYNTAX "Syntax: kround target\n"  

#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;

// Prototypes:
void do_kround (object, int);

int lvl;
object room, caster, *targs;

varargs int cast_kround (string str, int obj) {   
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

	lvl = this_player()->query("kungfu_level");
	obj = lvl;
	write("You whip your leg out and roundhouse "+target->query("cap_name")+" in the face!\n");
	say(TPN+" delivers a powerful roundhouse kick to "+possessive(target->query("cap_name"))+" face!\n");

	tell_room(environment(TP), TPN+" delivers a powerful roundhouse kick to "+
	  possessive(target->query("cap_name"))+" head!\n", ({ caster, target }) );
	tell_object(target, TPN+" deilvers a powerful roundhouse kick to your head!\n");
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

    do_kround(target, lvl);
    targs-=({ target });

    for (x = 0; x<sizeof(targs); x++)
	do_kround(targs[obj], lvl);

    return 1;
}

void do_kround (object victim, int level) {
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
	      " blocks "+possessive(caster->query("cap_name"))+ "roundhouse!\n", ({ caster, victim }) );
	    tell_object(victim, "You skillfully block "+possessive(caster->query("cap_name"))+ "roundhouse!\n");
	    write(victim->query("cap_name")+" skillfully blocks "+possessive(caster->query("cap_name"))+ " roundhouse!\n");
	    return;
	}
    }

    dam = victim->receive_damage(dam, "force", caster);
    victim->kill_ob(caster);

        write("\n\nDebug: "+dam+"\n\n");
    switch(dam) {
    case -10000..-1 :
	tell_room(room, "The roundhouse has no effect "+name+" becomes enraged!\n",
	  victim);
	tell_object(victim, "The roundhouse has no effect on you. You feel invigorated!\n");
	break;
    case 0 : 
	tell_room(room, name+" is unscathed by the feeble attack.\n",
	  victim);
	tell_object(victim, "You stand unaffected by the feeble attack.\n"+
	  "You just laugh.\n");
	break;
    case 1..12 :
	tell_room(room, name+"'s staggers a bit.\n", victim);
	tell_object(victim, "Your stagger a bit from the blow.\n");
	break;
    case 13..26 :
	tell_room(room, name+" is rocked by the powerful roundhouse.\n", victim);
	tell_object(victim, "You are rocked by the powerful roundhouse.\n");
	break;
    case 27..42 :
	tell_room(room, wrap(name+" falls to the floor, devistaded by "+
	    "the powerful roundhouse kick."), victim);
	tell_object(victim, "You fall to the floor, devistaded by the powerful roundhouse kick!\n");
	break;
    default :
	tell_room(room, wrap(name+"'s head whips back and "+
	    possessive(victim->query("gender"))+" neck cracks from the force "+
	    "of the kick!"), victim);
	tell_object(victim, "Your head whips back and your neck cracks "+
	  "from the force of the kick!\n");
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
