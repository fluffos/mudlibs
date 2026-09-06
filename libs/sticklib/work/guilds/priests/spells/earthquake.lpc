#include "priest_spell.h"

void begin_earthquake(object who, mixed data);
status end_earthquake(object who, mixed data);

void
create_spell() {
    spell_type = SP_OFFENSIVE;
    dif = 0;
    lvl = 10;
    cost = 30;
    spell_damage_rate = 30.0;
    skills_used = ({SK_SERENITY, SK_NATURE, SK_FORCES});
    skill_p = ({30,40,30});
    funs = ({ #'begin_earthquake, #'end_earthquake });
}


void
begin_earthquake(object who, mixed data)
{
    data = ({data == "pk", HERE});
    data[1]->tell_here(
      ":%<me.capname>% points %<me.possessive>% hands at the ground, like trying to \
make surface move.", 0, 0, who, who, 0, 0);
}


status
end_earthquake(object who, mixed data)
{
    object *ob, here, sym;
    string filter;
    int i,dam, yes_hit,skill;
    status pk_not_allowed;

    sym = who->query_guild_object();
    here = data[1];
    if (here != HERE) {
	who->tell_me("Your concentration was broken by the moving!");
	return 0;
    }
    who->add_sp(-cost);
    inc_skills(who,sym,100);

    who->tell_me("You cast the mighty earthquake spell. Ground \
quivers and shakes under the might of " GOD_NAME "!");
    here->tell_here(":%<me.capname>% casts a mighty earthquake spell. \
The ground starts shaking under your feet!", 0, 0, who, who, 0, 0);

    filter = data[0] ? "pk_filter":"mk_filter";
    ob = filter_array(all_inventory(here),filter,TO);
    dam = get_damage(who, sym, data[0]); 
    pk_not_allowed = 0;

    for (i=0;i<sizeof(ob);i++) {
	if(!ob[i]) continue;
	if(!ob[i]->attacked_by(who,-1)) {
	    ob[i] = 0;
	    pk_not_allowed = 1;
	} else {
	    yes_hit = ob[i]->hit_player(dam - random(dam/2), DT_EARTH, -3, who);
	    if(yes_hit&&ob[i]){
		who->attacked_by(ob[i],0);
		ob[i]->tell_me("You are injured by falling rocks and debris.");
	    }
	    else ob[i] = 0;
	}
    }
    here->tell_here("The falling rocks and debris just miss you. \
It seems as if the world is tearing itself apart.", 0, 0, ob, 0, 0);
    if (pk_not_allowed)
	who->tell_me("You feel your Gods displeasure because of your \
attempt to attack players in a place which doesn't allow it.");
    return 1;
}
