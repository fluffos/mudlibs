#include "priest_spell.h"

/* I left the satiation stuff out because it was already commented out by
 * Necros. If it looks like that playing is too easy, I can put it back 
 * though. *grin*
 *    // Chopin
 */

void begin_cremate(object who, mixed data);
status end_cremate(object who, mixed data);

void
create_spell() {
    dif = -10;
    lvl = 10;
    skills_used = ({ SK_SERENITY, SK_LIFE, SK_SPIRITS });
    skill_p = ({ 40, 30, 30 });
    funs = ({ #'begin_cremate, #'end_cremate });
}

int
calc_crem(int lvl)
{
    return (lvl*5)-(lvl*lvl/15)-random(lvl);
}


void
begin_cremate(object who, mixed data)
{
    string str;
    object corpse;

    str = data;
    data = 0;
    if(str == "")
	str = "corpse";
    if (str == "all" || str == "a") corpse = 0;
    else
    if (!(corpse = present(str, HERE))) {
	who->tell_me("There is no corpses to cremate here...");
	return;
    }
    if (corpse && !corpse->query_real_corpse()) {
	who->tell_me("That thing isn't suitable for cremation; \
" GOD_NAME " is only interested in real corpses.");
	return;
    }
    who->tell_me("You focus your mind, raise your hands to the heavens \
and begin chanting the ancient ritual prayer.");
    HERE->tell_here(":%<me.capname>% raises %<me.possessive>% hands to the \
heavens and begins chanting an ancient ritual prayer.",0,0,who,who,0,0);
    data = ({ corpse, HERE });
}


status
end_cremate(object who, mixed data)
{
    object x, prev_room, here, sym, corpse;
    closure cl;
    status do_all;
    object debugger;
    int lvl, tmp, skill;

    sym = who->query_guild_object();
    debugger = sym->query_debugger();
    corpse = data[0];
    prev_room = data[1];
    here = HERE;
    if (!corpse) {
	do_all = 1;
	x = first_inventory(prev_room);
	while (x) {
	    if (x->query_real_corpse())
		break;
	    x = next_inventory(x);
	}
	if (x) {
	    corpse = x;
	    x = next_inventory(x);
	} else {
	    who->tell_me("You can't see any corpses here...");
	    return 0;
	}
    }
    if (!corpse || prev_room!=here) {
	who->tell_me("The corpse you were about to cremate is no longer here!");
	return 0;
    }

    skill = get_skill(sym);
    while (corpse) {
	here->tell_here(sprintf("With a blinding flash of light, the %s \
is turned into ashes!", corpse->query_name() ));
	lvl = 2*(int)corpse->query_orig_level()/3;
	if(lvl > 50) lvl = 50;
	tmp = calc_crem(lvl);
	// with 100% skill you get 50% more than with 0% skill
	tmp += skill * tmp / 2000;
	if(debugger)
	    sym->inform_debugger(sprintf("Corpse level: %d, amount absorbed: \
%d", 3*lvl/2, tmp));
	who->add_sp(tmp);
	inc_skills(who, sym, 50);

	// Can anyone tell me a harder way to do this?
	cl = lambda(({'foo}),({#'move_object, 'foo, here}));
	filter_array(all_inventory(corpse),cl);

	destruct(corpse);
	if (!do_all)
	    break;
	while (x) {
	    if (x->query_real_corpse())
		break;
	    x = next_inventory(x);
	}
	if (x) {
	    corpse = x;
	    x = next_inventory(x);
	} else break;
    }
    return 1;
}
