/*
**  File: lightning.c (Chain Lightning)
**  Purpose: Mass damage spell. Affects up to "level" number of people with
**    a lightning bolt.
**  Cost: 25 SP (6th level evocation)
**  Credits:
**    11 Aug 97  Cyanide created the file.
*/

#define ROLL random(6)+1
#define COST 75
#define SYNTAX "Syntax: cast lightning at target\n"

#include <m_spells.h>
#include <mudlib.h>

// Prototypes:
void do_lightning (object, int);
void begin_hell (object, int);

int lvl;
object room, caster, last_hit, *targs;

inherit SPELL;

varargs int cast_lightning (string str, int obj) {
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
	if (!cast_spell(TP, COST)) return 0;
	obj = query_caster_level(TP, "wizard");
	lvl = obj;
	write("You begin casting Chain Lightning...\n"+
	  "Electricity begins crackling between your fingers.\n");
	say(TPN+" begins uttering arcane words...\n"+
	  "Electricity begins crackling between "+
	  possessive(TP->query("gender"))+" fingers!\n");

	tell_room(environment(TP), TPN+" hurls a lightning bolt at "+
	  target->query("cap_name")+"!\n", ({ caster, target }) );
	write("You hurl a lightning bolt at "+
	  target->query("cap_name")+".\n");
	tell_object(target, TPN+" hurls a lightning bolt at you!\n");
    } else {
	lvl = obj;
    }

#ifdef MAX_TO_SPELLS
    if (lvl > 16) lvl = 16;
#endif

    room = environment(target);
    targs = filter_array(all_inventory(room), "filter_targs", 
      this_object());
    caster = TP;

    do_lightning(target, obj);
    targs-=({ target });
    begin_hell(room, obj);
    return 1;
}

void do_lightning (object victim, int level) {
    int dam=0, x;
    string name;

    for (x=0; x<lvl; x++)  dam+=ROLL;
    lvl--;

    if (!victim) return;
    if (living(victim)) {
	name = victim->query("cap_name");
	x = 0;
	if (!check_magic_resist(level,victim,COST,dam)) return;
	//    x = query_save_mod(caster,victim, ({"evocation"}) );
	x = victim->save_throw(x);

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

	if (x) dam/=2;

	dam = spell_mult(dam);
	dam = victim->receive_damage(dam, "electricity", caster);
	victim->set("last_attacker", caster);
	victim->kill_ob(caster);

	switch(dam) {
	case -1000..-1 :
	    tell_room(room, "The raw energy actually heals "+name+"!\n",
	      victim);
	    tell_object(victim, "The raw energy actually heals you!\n");
	    break;
	case 0 : 
	    tell_room(room, name+" just laughs at the spell's puny "+
	      "energies.\n", victim);
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
	    tell_room(room, "The stench of "+name+"'s burnt hair and "+
	      "charred flesh fills the room!\n", victim);
	    tell_object(victim, "The stench of your burnt hair and charred"+
	      " flesh fills the room!\n");
	    break;
	default :
	    tell_room(room, wrap(name+" screams in mortal pain and outrage"+
		" as "+possessive(victim->query("gender"))+" flesh practically"+
		" melts from "+possessive(victim->query("gender"))+
		" bones!"), ({ victim }) );
	    tell_object(victim, wrap("You scream in mortal pain and outrage"+
		" as your flesh practically melts from your bones!"));
	    break;
	}
    } else {
	name = victim->query("short");
	tell_room(room, "The lightning hits "+name+" and arcs again!\n");
    }
    return;
}

void begin_hell (object room, int level) {
    int ran, size;
    string name;

    while (lvl>0) {
	size = sizeof(targs);
	if (size<1) {
	    tell_room(room, "The bolt grounds out.\n");
	    lvl = 0;
	} else {
	    ran = random(size);
	    if (living(targs[ran]))
		name = targs[ran]->query("cap_name");
	    else
		name = targs[ran]->query("short");

	    tell_room(room, "The bolts arcs toward "+name+"!\n", ({ targs[ran] }));
	    tell_object(targs[ran], "The bolt arcs toward you!\n");
	    do_lightning(targs[ran], level);
	    targs -= ({ targs[ran] });
	}
    }
    return;
}

int filter_targs (object ob) {
    if (ob == TP) return 0;
    if (wizardp(ob) && ob->query("invisible")) return 0;
    if (!living(ob) && ((int)ob->query("size")<3)) return 0;
    if (ob->query("no_attack")) return 0;
    if (ob==last_hit) return 0;

    return 1;
}
string spellcraft() {
    return (@EndSpell
Chain Lightning (Level VI Wizard Spell - Evocation)

Cost: 75 Spell Points

This spell unleashes lightning, hitting all creatures
and objects in a room.
EndSpell
    );
}
