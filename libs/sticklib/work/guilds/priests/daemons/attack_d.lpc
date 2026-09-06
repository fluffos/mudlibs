/*
 * ATTACK DAEMON
 * 
 * Still quite unfinished... no messages for players for example
 */

// stupid things in this object that should be fixed:
// - players can train when they're idle.
// - when this object is compiled, all priests have to remove & rewield
//    their weapons

#include <guild.h>
#include <tell_me.h>
#include <weapon_defs.h>
#include "../priest.h"
#include "../skills.h"

inherit GEN_SK_OBJ;

#define FP_COST 5

#define WEAPON 0
#define CL_QUERY_WC 1
#define CL_HIT_FUNC 2
#define CL_EXTRA_HIT_FUNC 3


mapping players;

create() {
    players = ([ ]);
    dif = 40; // very difficult -> trains very fast, so we have to
    // make get_train function return a relatively small number
    skills_used = ({ SK_STAFF, SK_LIFE });
    skill_p = ({ 90, 10 });
}


int get_train(object me, object sym, object target) {
    int my_lvl, t_lvl, d;

    if(!me || !target) return 0;

    my_lvl = me->query_level();
    t_lvl = target->query_level();

    d = 100 + 100*(t_lvl - my_lvl)/(my_lvl + t_lvl);
    d += target->query_ac()/10 + target->query_wc()/10;
    d = d / 2; // still too fast?
    sym->inform_debugger(sprintf("SP train: %d\n", d));
    return d;
}


// This function is not used (not yet at least). I will have to invite
// messages for staff fighting before I can put it to the game
void
do_attack(int hit_amount, object wp, object who, object enemy)
{
    int hit_class, dmg_type;
    string enemy_n, how, what, what2, txt;
    int tmp, x;

    if(!enemy) return;
    enemy_n = enemy->query_name(0, who);
    hit_class = wp->query_hc();
    dmg_type = wp->query(WP_DAMAGE_TYPE);

    tmp = (int) enemy->hit_player(random(hit_amount +1),
      dmg_type, hit_class, who);

    if(tmp<0) {
	if(!enemy) return;

	if(random(300) < 3) {
	    FUMBLE_D->fumble(who, enemy, wp);
	    return;
	}

	// Almost a direct copy from /basic/player/attack.c
	// I think this happens so seldom, that I left most of those
	// messages out

	switch(random(3)) {
	case 0:
	    txt = "You take your best hit"; break;
	case 1:
	    txt = "You attack valiantly"; break;
	case 2:
	    txt = "You swing wildly"; break;
	}
	txt = sprintf(" with your staff %s, but %s ", txt, enemy_n);
	switch(random(3)) {
	case 0:
	    txt += "steps aside."; break;
	case 1:
	    txt += "dances back."; break;
	case 2:
	    txt += "dodges."; break;
	}
	who->tell_me(txt, TELL_TYPE_MISSING);
	if(environment(who)) 
	    environment(who)->tell_here(":%<me.capname>% missed \
%<him.name>%.",0,0,who,who,enemy,0);
	return;
    }

    // some exp from hits:
    else who->add_exp(tmp - random(tmp/2));

    if(enemy && !enemy->query_ghost()) {
    }
    // Urgh. Too much writing. Doing that later... :)
}


int
weapon_strike(object who, object target, object wp, object dummy) {
    int tmp, t, skill;
    object sym, ob;
    closure query_wc, hit_func, extra_hit_func;

    if(!mapping_contains(&ob, &query_wc, &hit_func, &extra_hit_func,
	players, who)) {
	// This shouldn't happen
	who->set_guild_hook(G_HOOK_PRIMARY_ATTACK, 0);
	return 0;
    }
    if((!wp) || (ob != wp) || (who->query_guild() != GN_PRIEST)) {
	who->set_guild_hook(G_HOOK_PRIMARY_ATTACK, 0);
	players -= ([who]);
	return 0;
    }

    if(who->query_fp() < FP_COST)
	return 0; // Could give some message here, but on the other hand
    // that would sometimes be quite annoying

    who->add_fp(-FP_COST);

    if (query_wc && !to_object(query_wc)) {
	query_wc = hit_func = 0;
	// if query_wc is 0, there's not much point in having running hook
	who->set_guild_hook(G_HOOK_PRIMARY_ATTACK, 0);
	return 0;
    }
    if (hit_func && !to_object(hit_func))
    {
	hit_func = 0;
	who->set_guild_hook(G_HOOK_PRIMARY_ATTACK, 0);
	return 0;
    }
    tmp = funcall(query_wc) + funcall(hit_func, target);
    if(!target) return -1;
    if (extra_hit_func && !to_object(extra_hit_func))
	extra_hit_func = 0;
    funcall(extra_hit_func, target);
    if(!target) return -1;

    sym = who->query_guild_object();
    skill = get_skill(sym);
    tmp += skill*tmp/1000;

    sym->inform_debugger("wc with bonuses: " + tmp);

    inc_skills(who, sym, get_train(who, sym, target));
    return tmp;
}


status wield_weapon(object who, object weapon, closure query_wc,
  closure hit_func, closure extra_hit_func)
{
    string err;

    if(weapon->query(WP_TYPE) == "staff") {
	who->set_guild_hook(G_HOOK_PRIMARY_ATTACK,#'weapon_strike);
	if(member(players, who)) players-=([who]);
	players += ([who: weapon; query_wc; hit_func; extra_hit_func]);
    }
    else {
	// just to be sure:
	who->set_guild_hook(G_HOOK_PRIMARY_ATTACK, 0);
    }
    return 1;
}


status remove_weapon(object who, object weapon, int silent)
{
    // It doesn't hurt to do these even if the player is not in "players"
    // mapping
    who->set_guild_hook(G_HOOK_PRIMARY_ATTACK, 0);
    players -= ([ who ]);
}

void debug() {
    printf("%O\n", players);
}
