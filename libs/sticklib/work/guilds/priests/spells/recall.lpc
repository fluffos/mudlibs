#include "priest_spell.h"

#define SAFE_PLACE PRIEST_ROOM_DIR "guild_room"

void begin_teleport(object who, mixed victim);
status teleport(object who, mixed victim);

void
create_spell() {
    dif = -20;
    duration = 3;
    lvl = 16;
    cost = 60;
    skills_used = ({SK_SERENITY, SK_SPIRITS});
    skill_p = ({30,70});
    funs = ({ #'begin_teleport, #'teleport });
}

void
begin_teleport(object who, mixed data)
{
    data = 1;
    if(who->query_attack()) {
	who->tell_me("You can't concentrate enough file fighting.");
	data = 0;
	return;
    }
    HERE->tell_here(":%<me.capname>% utter%<me.ending_s>% a reverent \
prayer to " GOD_NAME ".",0,0,0,who,0,0);
}


status
teleport(object who, mixed data)
{
    int skill;
    object sym, last_room;

    if(!data) return 0;
    sym = who->query_guild_object();
    skill = get_skill(sym);
    inc_skills(who,sym,100);
    who->add_sp(-cost);

    if((skill_roll(sym, skill)<=0) || HERE->query(PREVENT_TELEPORT_FROM)) {
	who->tell_me("You fail, " GOD_NAME " is not on your side!");
	HERE->tell_here(":%<me.capname>% looks rather dissapointed.",
	  0,0,who,who,0,0);
	return 1;
    }
    // player still needs 60 spell points so that he can cast this spell,
    // but who cares -- Chopin
    if(critical_success)
	who->add_sp(cost/3);

    who->tell_me("You succeed, " GOD_NAME " must surely be on your side!"
      ,0,0,who,0,0);
    last_room = environment(who);
    who->move_player("X", SAFE_PLACE);
    if(SLAVE_D->query_slaves(who))
	SLAVE_D->player_moved(who, "X", "", last_room);
    return 1;
}
