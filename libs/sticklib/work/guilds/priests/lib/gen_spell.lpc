/*
 * A general spell file to be inherited by every spell. I made this
 * much like most general objects like /obj/bottle.c, so using this
 * should be pretty easy, but i'm not sure if this is very elegant
 * way to implement spells. Who knows :)
 * -- Chopin
 */

#include <invis_levels.h>
#include <guild.h>
#include <attack.h>
#include <player_defs.h>
#include <daemons.h>
#include <conditions.h>
#include <room_defs.h>
#include "../priest.h"
#include "../skills.h"

#define ENV environment
#define HERE environment(who)
#define LCALL this_object()
#define TOBJ this_object()

inherit GEN_SK_OBJ;

// These variables should be set in create_spell() function. There's
// no separate set_* functions for them, because this file is only ment
// to be inherited, not cloned.
int set_casting_flag, dam_p;
int cost_bonus; // Should be used only, if there's no other way to make
// the spell do enough damage. NOT IN USE ANYMORE

status acolyte_spell; // acolytes can use this spell even if they
// are not high enough otherwise
int spell_type; // SP_OFFENSIVE, SP_DEFENSIVE, SP_HEALING or SP_SPECIAL
status check_target; // should we check the target?
status testing; // if set, only coders and testchars can use this spell
string sp_name; // name of this spell (default: file name)
int finish_cost; // If spell uses some of it's required sps at first round,
// it should set this to the amount of sps it will use on the second round
int duration; // How many rounds it takes to cast this spell

float spell_damage_rate; // How much damage this spell should do

// Prototypes:
void gen_begin_spell(object who, mixed target);
status gen_end_spell(object who, mixed target);
void begin_casting(object who, mixed target);
status end_casting(object who, mixed target);
object attack_spell_target(object who, string str);
object healing_spell_target(object who, string str);


// Query funs:
status query_testing() { return testing; }
int query_spell_type() { return spell_type; }
float query_damage_rate() { return spell_damage_rate; }



// Let's set values for above variables, so that not all of them
// have to be set in create_spell
create() {
    dif = lvl = cost = set_casting_flag = 0;
    acolyte_spell = 0;
    order_restriction = 0;
    finish_cost = 0;
    dam_p = 0; // default is always max damage
    skills_used = ({SK_SERENITY});
    skill_p = ({100});
    // gen_end_casting function is pretty silly, but it is here
    // for testing purposes.
    spell_type = SP_SPECIAL;
    check_target = 0;
    funs = ({ #'gen_begin_spell, #'gen_end_spell });
    sp_name = object_name(this_object());
    LCALL->create_spell();
    // A kind of kludge:
    if(!finish_cost) finish_cost = cost;
}


// some spells may want to override this:
mixed
parse_target_string(string s) {
    string tmp;

    if(!s) return "";
    if(sscanf(s, "at %s", tmp) !=1)
	tmp = s;
    return tmp;
}


// Let's do some checks and put the spell functions in player's combat queue.
status
invoke(object who, object sym, string arg)
{
    mixed target;
    mixed x;

    target = parse_target_string(arg);
    if(intp(target)) return 0;

    if(testing && !who->query_coder_level() && !who->query_testplayer()) return
	notify_fail("That spell is not available for players yet.\n"),0;

    if(pointerp(order_restriction) &&
      member(order_restriction, sym->query_order())==-1)
	return notify_fail("You don't know how to use that spell.\n"),0;

    if(who->query_level()<lvl &&
      !(acolyte_spell && sym->query_rank() == AE_RANK))
	return notify_fail(GOD_NAME " has not blessed you with that spell yet.\n"),0;

    if(sym->query_banned())
	return notify_fail("You wouldn't dare break the traditional \
prohabition against a new priest using spells and powers of the Order. \
You must first talk to the Vicegerant.\n"),0;

    if((sym->query_casting() == 2) &&
      (sizeof(who->query(PLR_FULL_COMBAT_QUEUE))==0))
	sym->set_casting(0);

    // this should be used only by spells that take more than 1 round to cast
    if(sym->query_casting())
	return notify_fail("You can not concentrate on so much at once.\n"),0;

    if(set_casting_flag) sym->set_casting(2);

    x = ({ #'begin_casting, #'end_casting, target });
    if(duration) x += ({ duration });
    if((int) who->set(PLR_COMBAT_QUEUE, x) == 1)
	funcall(x[0],who,&(x[2]));
    return 1;
}


void
begin_casting(object who, mixed data) {
    object sym;

    sym = who->query_guild_object();
    //kludge:
    if(set_casting_flag) sym->set_casting(0);
    if(who->query_sp() < cost) {
	who->tell_me("You don't seem to be able to think clearly \
enough to invoke that spell.");
	data = 0; return;
    }
    if(who->query_sit() || who->query_rest()) {
	who->tell_me("Nah.. You feel too relaxed to do that.");
	data = 0; return;
    }
    if(who->query_hp()<0) {
	who->tell_me("You can't do that while unconscious.");
	data = 0; return;
    }
    if(!who->query_can_move()) {
	who->tell_me("You can't move to do that!");
	data = 0; return;
    }
#ifndef MILLER_TIME
    if(who->query_intoxication()>=1) {
	who->tell_me("Your God ignores your drunken mumblings.");
	data = 0; return;
    }
#endif /* MILLER_TIME */
    if(check_target) {
	switch(spell_type) {
	case SP_OFFENSIVE:
	    data = TARGET_D->find_target(who, data);
	    break;
	case SP_HEALING:
	    data = healing_spell_target(who, data);
	    break;
	}
	if(!data) return;
    }
    sym->inform_debugger("Spell: " + sp_name);
    funcall(funs[0],who,&data);
    if(data && set_casting_flag) sym->set_casting(1);
}


status
end_casting(object who, mixed data) {
    if(!data || !funs[1]) return 0;

    if(!who->query_can_move()) {
	who->tell_me("You become paralyzed, and are thus unable to finish \
the prayer.");
	HERE->tell_here(":%<me.capname>% abruptly ends %<me.possessive>% \
chanting, as if being stunned!",0,0,who,who,0,0); 
	return 0;
    }
    if(who->query_sp() < finish_cost) {
	who->tell_me("You don't seem to be able to think clearly \
enough to finish your spell.");
	HERE->tell_here(":%<me.capname>% finishes %<me.possessive>% \
chanting, and looks rather dissapointed.",0,0,who,who,0,0);
	return 0;
    }
    if(check_target && (!objectp(data) || !present(data, HERE))) {
	who->tell_me("You have lost your target!");
	HERE->tell_here(":%<me.capname>% seems to have lost \
%<me.possessive>% target, thus failing %<me.possessive>% prayer.",
	  0,0,who,who,0,0);
	return 0;
    }
    return funcall(funs[1],who,data);
}


object
attack_spell_target(object who, string str)
{
    object ob;
    object *inv;
    int i,n;

    // Change this so, that the player can use the spell even if he can't see,
    // but the probability that you would hit the target would depend on
    // your skill. (You could even hit wrong objects?)
    if(!who->query_can_see()) {
	who->tell_me("You can't see anything!");
	return 0;
    }
    if(str == "") {
	ob = who->query_attack();
	if(!ob) {
	    who->tell_me("You've got no target.");
	    return 0;
	}
    } else {
	str = lower_case(str);
	if(!(ob = present(str,HERE))) {
	    who->tell_me(sprintf("There's no '%s' here.", str));
	    return 0;
	}
	if(!living(ob)) {
	    who->tell_me("That doesn't seem to be alive.");
	    return 0;
	}
	if(ob->query_guild() == GN_PRIEST) {
	    inv = all_inventory(HERE);
	    n = sizeof(inv);
	    for(i=0;i<n;i++) {
		ob = inv[i];
		if(ob->id(str) && (ob->query_guild()!=GN_PRIEST))
		    break;
	    }
	    if(i==n) {
		who->tell_me("You shouldn't be attacking other priests!");
		// return 0;
	    }
	}
    }
    if(ob==who) {
	who->tell_me("OK. You kill yourself. C'Mon...");
	return 0;
    }
    if(!ob->attacked_by(who, -1)) {
	who->tell_me(sprintf("You feel " GOD_NAME " is very displeased \
because of your attempt to attack %s.", ob->query_objective()));
	// return 0;
    }
    return ob;
}


object
healing_spell_target(object who, string str)
{
    object ob;

    if(!who->query_can_see()) {
	who->tell_me("You can't see anything!");
	return 0;
    }
    if(str == "")
	return who;

    ob = present(lower_case(str),HERE);
    if(!ob) {
	who->tell_me(sprintf("You can't see any %s here.",str));
	return 0;
    }
    if (!ob->query(LIV_IS_PLAYER)) {
	who->tell_me("You hear the voice of " GOD_NAME
	  " in your ears: Only players...");
	return 0;
    }
    if(EXCOM_D->excomed(ob->query_real_name())) {
	who->tell_me("That player is excommunicated and thus does not deserve \
to be healed.");
	return 0;
    }
    if((ob!=who) && present4("pkflag",ob,who,IL_TOTALLY_INVISIBLE)) {
	who->tell_me(sprintf("That player is being punished, you can't \
heal %s.", ob->query_objective()));
	return 0;
    }
    if (ob->query_hp() < 0) {
	who->tell_me("That player is beyond help of this spell.");
	return 0;
    }
    return ob;
}


// This function is fairy stupid: the probability of critical success is
// not connected to how well you normally do damage. It also uses
// balance daemon, which was not designed for my skill system :(
int
get_damage(object who, object sym, status pk)
{
    int skill, s, dam;
    float damage_rate;
    string str;
    object debugger;

    debugger = sym->query_debugger();
    skill = get_skill(sym);
    s = skill_roll(sym, skill);

    damage_rate = (pk) ? PK_DAMAGE_RATE : MK_DAMAGE_RATE;
    dam = to_int(spell_damage_rate * (1.0 + damage_rate * skill / 1000.0));

    if(critical_success) {
	dam += random(dam);
	who->tell_me("You succeeded exceptionally well!");
    }
    if(debugger) str = sprintf("Max dam: %d ", dam);
    dam -= random(dam_p*dam/100);
    if(debugger) str += sprintf("dam: %d ", dam);

    sym->inform_debugger(str);
    return dam;
}


int
get_attack_spell_train(object me, object sym, object target) {
    int my_lvl, t_lvl;
    int d;

    if(!me || !target) return 0;
    my_lvl = me->query_level();
    t_lvl = target->query_level();

    d = 100 +100*(t_lvl - my_lvl)/(my_lvl + t_lvl);
    d += target->query_ac()/10 + target->query_wc()/10;
    d += target->query_spell_dmg() / 10 + target->query_breath_dmg()/5;
    sym->inform_debugger(sprintf("SP train: %d.", d));
    return d;
}


/* FILTERS */

// Filter out all players and guild monsters
status
mk_filter(object ob) {
    return living(ob) && (ob->query_guild() != GN_PRIEST) && ob->is_npc();
}

// Filter out all priests and coders 
status 
pk_filter(object ob) {
    return living(ob) && (ob->query_guild() != GN_PRIEST) &&
    !ob->query_coder_level();
}


/* Very general spell functions */

status
gen_begin_spell(object who, mixed target) {
    HERE->tell_here(":%<me.capname>% close%<me.ending_s>% %<me.possessive>% \
eyes and whisper%<me.ending_s>% a humble mantra to %<me.possessive>% God."
      ,0,0,0,who,0,0);
}

gen_end_spell(object who, mixed target) {
    HERE->tell_here(":%<me.capname>% finish%<me.ending_es>% chanting \
and open%<me.ending_s>% %<me.possessive>% eyes."
      ,0,0,0,who,0,0);
}
