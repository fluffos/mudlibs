// Ilz did this.   God knows when.
// A that is known aside from that is that it was stolen 
// from Cyanide.

#define COST 100
#define SYNTAX "Syntax: cast creepingdoom at target\n"  

#include <p_spells.h>
#include <mudlib.h>

// Prototypes:
void do_doom (object);

int lvl;
object room, caster, last_hit, *targs;

inherit SPELL;

varargs int invoke_creepingdoom (string str, int obj) {   
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
	if (!invoke_spell(TP, COST)) return 0;

	lvl = TP->query_level("priest");
	write("You begin casting Creeping Doom...\n"+
	  "Swarms of insects form around you.\n");
	say(TPN+" begins summoning the power of nature...\n"+
	  "Swarms of insects form around "+
	  objective(TP->query("gender"))+"!\n");

	tell_room(environment(TP), TPN+" summons a swarm of insects to attack "+
	  target->query("cap_name")+"!\n", ({ TP, target }) );
	write("You cause the swarm to attack "+target->query("cap_name")+".\n");
	tell_object(target, TPN+" directs the swarm of insects at you!\n");
    } else {
	lvl = obj;
    }

    target->kill_ob(TP);
    room = environment(target);
    caster = TP;

    do_doom( target );

    return 1;
}

void do_doom (object victim) {
    int dam=0, x;
    string name;

    if (!victim) return;

    if (!victim->query("weap_resist")) {
	dam = (50 * ((random(6)+5)));

	dam = (dam + (10 * (victim->query("armor_class") - 10)));
	dam = dam - (4 * victim->query("stat/dexterity"));
	if (dam < 0) dam = 0;
    }

    name = victim->query("cap_name");

    //if (!check_magic_resist(caster->query_level("priest"),victim,COST,dam))
    //    return;
    x = victim->save_throw(x);

    dam = victim->receive_damage(dam, "piercing", caster);

    switch(dam) {
    case -1000..-1 :
	tell_room(room, "The insects actually heal "+name+"!\n",
	  victim);
	tell_object(victim, "The insects actually heal you!\n");
	break;
    case 0 : 
	tell_room(room, name+" just laughs at the little bugs.\n",
	  victim);
	tell_object(victim, "You just laugh at the little bugs.\n");
	break;
    case 1..100 :
	tell_room(room, name+" escapes most of the bug's wrath.\n", victim);
	tell_object(victim, "You escape most of the bug's wrath.\n");
	break;
    default :
	tell_room(room, wrap(name+" shrieks in fear as the insects eat "+
	    possessive(victim->query("gender"))+" flesh from "+
	    possessive(victim->query("gender"))+" bones!"));
	tell_object(victim, wrap("You shriek in fear as the insects eat"+
	    " your flesh from your bones!"));
	break;
    }

    victim->set("last_attacker", TP);
    return;
}

string spellcraft() {
    return (@EndSpellcraft
Creeping Doom (Priest - Level VII - Animal, Summoning)

Duration: instant             Area of Effect: 1 (unfortunate) Target
Cost: 100 TP

	This powerful spell summons forth a mass of thousands of
biting, stinging, insects which devour their target. Unfortunately,
the insects are not themselves magical and are of limited use when
fighting creatures resistant to normal weapons.
EndSpellcraft
    );
}
