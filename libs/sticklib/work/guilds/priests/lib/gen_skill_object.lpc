/*
 * A general object to be iherited by all objects that use skills. Mainly
 * this means gen_spell.c and gen_potion.c, but this makes it easy to create
 * other kinds of such objects.
 * 5/28/97 - Chopin
 *
 * Now difficulty affects player's chance to succeed, but it on the other
 * hand it means, there is always a possibility to fail, even if your
 * skill is 1000. I have to reconsider this someday.
 */

#define TP this_player()

#include "../priest.h"
#include "../skills.h"

inherit PSKILLS;

// is critical success of failure?
status critical_success, critical_failure;

// variables used by both potions and spells
int dif, cost, lvl;
int *skills_used, *skill_p;
mixed order_restriction; // null or array of ints
mixed funs; // most likely a closure

int query_difficulty() { return dif; }
int query_cost() { return cost; }
int query_level() { return lvl; }
int *query_skills_used() { return skills_used; }
int *query_skill_p() { return skill_p; }
mixed query_order_restriction() { return order_restriction; }


/*
 * SKILL ROLL
 * I don't like balance_daemon's version of this function, so I made
 * my own one.
 * - Chopin
 */

int
skill_roll(object sym, int skill_level)
{
    int r, cs, cf, s;

    critical_failure = critical_success = 0;

    r = random(1001);
    cf = cs = skill_level;

    // Critical failure chance?
    cf = 50 - cf/20;
    if (r <= cf)
	critical_failure = 1;
    else {
	// Critical success chance?
	// was happening too often
	// cs = 990 - 2*cs/(1010-cs);
	// cs = 995 - cs/(1010-cs); // too seldom now :)
	cs = 995 - 2*cs/(1010-cs);
	// cs chance increases dramatically when skill is > 990
	if (r >= cs) critical_success = 1;
    }
    s = skill_level - 1000 + r;
    sym->inform_debugger(sprintf("cs limit: %d, cf limit: %d, r: %d, \
success: %d.\n", cs, cf, r, s));
    return s;
}


/*
 * GET_SKILL
 */

int
get_skill(object sym) {
    int i,t;
    string str;
    float tmp;

    tmp = 0.0;
    i = sizeof(skills_used);
    while(--i>=0)
	tmp += skill_p[i]*pex2skill(sym->query_pex(skills_used[i]))/100.0;
    // difficulty affects skills "curve" now
    str = sprintf("Orig skill: %f ", tmp);
    if(t = sym->query_metam_penalty()) {
	tmp = (100-t)*tmp/100;
	str += sprintf("After metamorphosis penalty: %f ", tmp);
    }
    // Dif should range between -30 and 30, where -30 is very easy,
    // and 30 hard.
    t = 17*(dif - sym->query_faith() + PRIEST_TUNE);
    tmp = 1000.0*tmp/(1000.0 + t - tmp*t/1000.0);
    str += sprintf("Modified skill: %f.", tmp);
    sym->inform_debugger(str);
    return to_int(tmp);
}


/*
 * INC_SKILLS
 *
 * All variables but 'amount' must be given to this function. If amount is
 * omitted, skills will be advanced by 1 point. If amount is != 0, skills
 * will be advanced by (amount+1) points.
 */

varargs void
inc_skills(object who, object sym, int p, int amount) {
    int t,s,i,temp,order;
    string str;
    object debugger;

    debugger = sym->query_debugger();
    order = sym->query_order();
    amount ++;
    if(debugger)
	str = sprintf("Probabilities that skills are advanced (amount: %d):",
	  amount);

    // difficulty affects also player's ability to learn
    // hard spells/skills train faster
    temp = (100 + dif/2 + sym->query_faith() - 2*PRIEST_TUNE) * p / 100;
    i = sizeof(skills_used);
    while(--i>=0) {
	s = skills_used[i];
	t = temp * (100 + order * ORDER_BONUSES[s]) * skill_p[i]/10000;
	if(debugger)
	    str += sprintf("\n '%s': %d ", SKILL_NAMES[s], t);
	if(t>random(101)) {
	    if(debugger) str += "(was advanced)";
	    sym->inc_pex(s, amount);
	}
    }
    if(debugger)
	sym->inform_debugger(str);
}


int
clean_up(int clones) {
    return 0; // no cleaning up
}

