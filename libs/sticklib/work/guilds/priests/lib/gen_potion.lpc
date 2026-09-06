/*
 * GENERAL POTION OBJECT
 *
 * This isn't really the potion object, but contains the functions
 * what are needed when player mixes a potion or drinks it.
 */

#include <player_defs.h>
#include <living_defs.h>
#include <guild.h>
#include <daemons.h>
#include <conditions.h>
#include <room_defs.h>
#include "../skills.h"
#include "../priest.h"

#define HERE environment(who)
#define ENV(x) environment(x)
#define TO this_object()

inherit GEN_SK_OBJ;

// These variables should be set in create_potion function. There's
// no separate set_* functions for them, since this file is only ment
// to be inherited, not cloned.
string pot_name;
string color, drinker_mess, *ingredients;
int strength;
mixed smash_funs;


/**** PROTOTYPES ****/

object clone_potion(object who, int t);
void begin_smash(object who, mixed data);
void end_smash(object who, mixed data);


/*
 * Create
 */

create() {
    dif = lvl = cost = 0;
    skills_used = ({SK_SERENITY, SK_ALCHEMY});
    skill_p = ({10,90});
    strength = 2;
    funs = ({});
    smash_funs = ({ #'begin_smash, #'end_smash });
    pot_name = "testing";
    color = "TEST";
    ingredients = ({});
    drinker_mess = "You drank a test potion!";
    this_object()->create_potion();
}


status
mix(object who, object sym)
{
    int i, j, foo, dist_lvl;
    object ob,*ings;
    mixed temp;

    if(who->query_level()<lvl)
	return notify_fail("You lack the knowledge for that potion.\n"),0;

    if(who->query_sp()<cost)
	return notify_fail("You can't concentrate hard enough.\n"),0;

    if(!who->query_can_move())
	return notify_fail("You can't move to do that!\n"),0;

    if(sym->query_banned())
	return notify_fail("You wouldn't dare to break the traditional \
prohabition against a new priest using spells and powers of the Order. \
You must first talk to the Vicegerant.\n"),0;

    if(sym->query_mixing())
	return notify_fail("Only one potion can be mixed at a time.\n"),0;

    foo = 0;
    ings = ({});
    for(i=sizeof(ingredients);--i>=0;) {
	if(stringp(temp = ingredients[i]))
	    ob = present(temp, who);
	else for(j=sizeof(temp);--j>=0;) {
		if(ob = present(temp[j],who)) break;
	    }
	if(ob)
	    ings += ({ ob });
	else {
	    foo = 1; break;
	}
    }
    if(foo)
	return notify_fail("You don't have all the ingredients!\n"),0;

    who->tell_me("You add the ingredients and start mixing...");
    HERE->tell_here(({
	":%<me.capname>% starts mixing a potion.",
	"You hear someone pouring something from bottle to another.",
      }), ({LIV_CAN_SEE, LIV_CAN_HEAR}),
      0,who,who,0,0);

    who->add_sp(-cost);
    temp = foo = 0;
    for(i=sizeof(ings);--i>=0;) {
	dist_lvl = ings[i]->query_dist_level();
	if(dist_lvl>0) {
	    temp += dist_lvl;
	    foo++;
	}
	destruct(ings[i]);
    }
    if(foo) temp /= foo;
    sym->set_mixing(1);
    call_out("mix_it", 4+random(3), who, sym, temp);
    return 1;
}


void
log_mixing(object who, status success) {
    if(who->query_coder_level()) return;
    write_file(PRIEST_DIR "log/MIXED", sprintf("%s %s %s %s\n",
	ctime(time()), who->query_real_name(), success ? "succeeded in" :
	"failed in", pot_name));
}


void
mix_it(object who, object sym, int ing_levels)
{
    object pot;
    int skill, temp;

    sym->set_mixing(0);
    inc_skills(who, sym, 100, 3); // let's advance 3 points at a time
    // hope it's fast enough now
    // maybe mixing should be harder, if you use bad ingredients
    // with high skills.

    skill = get_skill(sym);
    // when mixing outside the lab, making potions is a bit harder. This
    // affects newbies more that more advanced players, but even with almost
    // perfect skill, you get a 10% penalty outside the lab. Notice that
    // both probability of success and potion's "strength" are reduced
    // -- Chopin
    if(!HERE->is_priest_lab()) {
	skill -= 100;
	if(skill<0) skill = 0; // newbies can't mix outside lab
    }
    if(skill_roll(sym, skill)<0) {
	who->tell_me("You failed in the mixing.");
	HERE->tell_here(({
	    ":%<me.capname>% looks like %<me.pronoun>% failed in the mixing.",
	  }), ({LIV_CAN_SEE}),
	  0,who,who,0,0);
	log_mixing(who, 0);
	return;
    }
    log_mixing(who, 1);
    if(critical_success) {
	temp += random(temp);
	who->tell_me("You succeeded in the mixing exceptionally well!");
    }
    else
	who->tell_me("You succeeded in the mixing.");
    HERE->tell_here(({
	":%<me.capname>% succeeded in the mixing.",
      }), ({LIV_CAN_SEE}),
      0,who,who,0,0);
    temp = (2*skill/10 + 2*ing_levels)/3;
    pot = clone_potion(who,temp);
    if(!pot)
	return;
    if(transfer(pot,who)) {
	move_object(pot,HERE);
	who->tell_me("You drop the potion, because you can't carry anything more.");
    }
}

object
clone_potion(object who, int t)
{
    object ob;

    ob = clone_object(PRIEST_OBJ_DIR "priest_bottle");
    if(ob)
	ob->make_potion(pot_name, color, t, drinker_mess, strength, funs, smash_funs);
    else
	who->tell_me("*ERROR* Can't clone the potion object.");
    return ob;
}


void
begin_smash(object who, mixed data) {
    object potion;
    int l;

    potion = data[0];
    if(!potion) {
	data = 0;
	return;
    }
    l = data[1];
    destruct(potion);
    environment(who)->tell_here(":%<me.capname>% smash%<me.ending_es>% \
a potion on the ground, leaving just some liquid and a couple of shards of \
glass.",0,0,0,who,0,0);
    data = ({ environment(who), l });
}

status
end_smash(object who, mixed data) {
    if(!data) return 0;
    data[0]->tell_here("The liquid evaporates quickly.");
    return 1;
}
