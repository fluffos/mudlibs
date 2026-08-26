/*
**  File: swarm.c (Meteor Swarm)
**  Purpose: Mass damage spell. The target takes full damage (15d4 * 4),
**    others may take *4 damage, some *2, some *1.
**  Cost: 60 SP (9th level evocation)
**  Credits:
**    04 Nov 97  Cyanide created the file.
**     14 Mar 98  Cyanide fixed up a bit.  Fixed a few bugs.
**     18 Mat 98  Cyanide repeated the process.
**  Notes:
**    So far, all the upper damage messages are the same, and will need to
**    be updated, I just ran out of ideas for now...   -Cyanide 
*/

#define ROLL random(4)+1
#define COST 40
#define SYNTAX "Syntax: cast swarm at target\n"

#include <m_spells.h>
#include <mudlib.h>

// Prototypes:
void do_swarm (object, int);
void begin_hell (object, int);

int dam;
object target;
object room, caster, *targs;

inherit SPELL;

varargs int cast_swarm (string str, int obj) {
    int x;
    target = 0;

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
	TP->set("power_delay", 1);

	write("You begin casting Meteor Swarm...\n");
	say(TPN+" begins uttering arcane words...\n");

	tell_room(environment(TP), wrap(TPN+" hurls eight fiery missiles at "+
	    target->query("cap_name")+"!"), ({ target, TP }) );
	write("You hurl a meteor swarm at "+target->query("cap_name")+".\n");
	tell_object(target, TPN+" hurls eight large, fiery globes at you!\n");
	obj = query_caster_level(TP, "wizard");
    }

    room = environment(target);
    targs = filter_array(all_inventory(room), "filter_targs", this_object());

    caster = TP;

    dam = 0;
    for(x=1; x<=15; x++) dam+=ROLL;
    do_swarm(target, obj);
    begin_hell(room, obj);
    return 1;
}

void do_swarm (object victim, int lvl) {
    int tmp_dam, tmp_dam2, x, flag;
    string name;

    if (!victim) return;
    name = victim->query("cap_name");
    if (!visible(caster, victim)) name = "Somebody";
    if (!check_magic_resist(lvl,victim,COST,dam)) return;

    x=0;
    // x = query_save_mod(caster,victim, ({"evocation"}) );
    // x = victim->save_throw(x);

    flag = random(6);
    if (victim==target) {
	x = 0;
	flag = 0;
    }

    // Here we figure out this poor soul's fate.
    tmp_dam = dam;
    switch (flag) {
    case 0 : tmp_dam*=4; break;
    case 1 : tmp_dam*=2; break;
    default : break;
    }

    if (x) {
	tmp_dam/=2;
	if (victim->query_skill("Evasion")) {
	    tell_room(environment(victim), victim->query("cap_name")+
	      " dodges all the meteors!\n", ({ caster, victim }) );
	    tell_object(victim, "You manage to jump aside!!\n");
	    write(victim->query("cap_name")+" jumps aside and takes cover!\n");
	    return;
	}
    }

    tmp_dam = spell_mult(tmp_dam);
    tmp_dam2 = victim->receive_damage((tmp_dam/2), "fire", caster);
    tmp_dam2 += victim->receive_damage((tmp_dam/2), "crushing", caster);

    victim->set("last_attacker", caster);
    victim->kill_ob(caster);

    switch(tmp_dam2) {
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
	tell_room(room, "Painfuls burns cover "+name+
	  "'s chest and arms.\n", victim);
	tell_object(victim, "Painful burns cover your chect and arms.\n");
	break;
    case 43..60 :
	tell_room(room, wrap(name+"'s skin peels away and "+
	    possessive(victim->query("gender"))+" hair burns in the "+
	    "flames!"), victim);
	tell_object(victim, "Your skin peels away and your hair burns "+
	  "in the flames!\n");
	break;
    case 61..80 :
	tell_room(room, "The stench of "+name+"'s cooking"+
	  " flesh fills the room!\n", victim);
	tell_object(victim, "The stench of your cooking"+
	  " flesh fills the room!\n");
	break;
    case 81..102 :
	tell_room(room, wrap(name+" screams in mortal pain and outrage"+
	    " as "+possessive(victim->query("gender"))+" flesh practically"+
	    " melts from "+possessive(victim->query("gender"))+" bones!"),
	  ({ victim }) );
	tell_object(victim, wrap("You scream in mortal pain and outrage"+
	    " as your flesh practically melts from your bones!"));
	break;
    case 103..126:
	tell_room(room, wrap(name+" screams in mortal pain and outrage"+
	    " as "+possessive(victim->query("gender"))+" flesh practically"+
	    " melts from "+possessive(victim->query("gender"))+" bones!"),
	  ({ victim }) );
	tell_object(victim, wrap("You scream in mortal pain and outrage"+
	    " as your flesh practically melts from your bones!"));
	break;
    case 127..152:
	tell_room(room, wrap(name+" screams in mortal pain and outrage"+
	    " as "+possessive(victim->query("gender"))+" flesh practically"+
	    " melts from "+possessive(victim->query("gender"))+" bones!"),
	  ({ victim }) );
	tell_object(victim, wrap("You scream in mortal pain and outrage"+
	    " as your flesh practically melts from your bones!"));
	break;
    case 153..180:
	tell_room(room, wrap(name+" screams in mortal pain and outrage"+
	    " as "+possessive(victim->query("gender"))+" flesh practically"+
	    " melts from "+possessive(victim->query("gender"))+" bones!"),
	  ({ victim }) );
	tell_object(victim, wrap("You scream in mortal pain and outrage"+
	    " as your flesh practically melts from your bones!"));
	break;
    case 181..210:
	tell_room(room, wrap(name+" screams in mortal pain and outrage"+
	    " as "+possessive(victim->query("gender"))+" flesh practically"+
	    " melts from "+possessive(victim->query("gender"))+" bones!"),
	  ({ victim }) );
	tell_object(victim, wrap("You scream in mortal pain and outrage"+
	    " as your flesh practically melts from your bones!"));
	break;
    case 211..242:
	tell_room(room, wrap(name+" screams in mortal pain and outrage"+
	    " as "+possessive(victim->query("gender"))+" flesh practically"+
	    " melts from "+possessive(victim->query("gender"))+" bones!"),
	  ({ victim }) );
	tell_object(victim, wrap("You scream in mortal pain and outrage"+
	    " as your flesh practically melts from your bones!"));
	break;
    default:
	tell_room(room, wrap(name+" screams in mortal pain and outrage"+
	    " as "+possessive(victim->query("gender"))+" flesh practically"+
	    " melts from "+possessive(victim->query("gender"))+" bones!"),
	  ({ victim }) );
	tell_object(victim, wrap("You scream in mortal pain and outrage"+
	    " as your flesh practically melts from your bones!"));
	break;
    }
    return;
}

void begin_hell (object room, int lvl) {
    int ran, x;
    string name;

    for (x=0;x<sizeof(targs);x++) {
	if (living(targs[x]))
	    name = targs[x]->query("cap_name");
	else
	    name = targs[x]->query("short");
	do_swarm(targs[x], lvl);
    }
    return;
}

int filter_targs (object ob) {
    object *obs;

    if (target==ob) return 0;
    if (TP==ob) return 0;
    if (wizardp(ob) && ob->query("invisible")) return 0;
    if (!living(ob)) return 0;
    if (ob->query("no_attack")) return 0;

    // Now, it may be of interest.
    // We only hit users if they are attacking us at the moment.
    obs = ob->query_attackers();
    if ((obs) && (member_array(TP, obs)!=-1)) return 1;
    if (userp(ob)) return 0;

    return 1;
}

string spellcraft() {
    string str = (@ENDSPELL

Meteor Swarm 
(Evocation)

Duration: Instantaneous                 Cost: 40 SP
Area of Effect: Special                 Saving Throw: 1/2

        A meteor swarm is a very powerful and spectacular spell which is 
similar to the fireball spell in many aspects. When it is cast eight 
spheres of 1-foot diameter spring from the outstretched hand of the wizard
and streak in a straight line to the distance demanded by the spellcaster.
Any creature in the straight-line path of these missiles (i.e., the target)
receives the full effect, without benefit of a saving throw. The meteor 
missiles leave a fiery trail of sparks, and each bursts as a fireball,
doing massive fire and impact damage.
ENDSPELL
    );

    return str;
}

/* EOF */

