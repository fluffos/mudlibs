#include "priest_spell.h"

void begin_summon(object who, mixed victim);
status do_summon(object who, mixed victim);

void
create_spell() {
    dif = 0;
    lvl = 15;
    cost = 70;
    skills_used = ({SK_SERENITY, SK_SPIRITS, SK_FORCES});
    skill_p = ({30,50,20});
    funs = ({ #'begin_summon, #'do_summon });
}


void
begin_summon(object who, mixed data)
{
    object *slaves;
    int i;

    data = 0;
    slaves = SLAVE_D->query_slaves(who);
    for(i=sizeof(slaves);--i>=0;) {
	if(slaves[i]->is_priest_angel()) {
	    who->tell_me("But your guardian angel is already with you!");
	    return;
	}
    }
    // TO DO: write new messages...
    who->tell_me("You pray for " GOD_NAME " to send an angel to help and \
protect you.");
    environment(who)->tell_here(":%<me.capname>% starts praying.",
      0,0,who,who,0,0);
    data = 1;
}


status
do_summon(object who, mixed data)
{
    object sym, angel;
    int skill;

    if(!data) return 0;

    sym = who->query_guild_object();
    skill = get_skill(sym);

    if(DELAY_D->query_delay(who, DELAY_TYPE_SUMMON)<0) {
	who->tell_me("You feel your guardian angel is not yet \
ready to return back to you.");
	return 1;
    }

    who->add_sp(-cost);
    if( skill_roll(sym, skill)> 0) {

	DELAY_D->set_delay(who, DELAY_TYPE_SUMMON, SUMMON_DELAY);
	angel = clone_object(PRIEST_MON_DIR "angel");
	angel->set_owner(who, skill);
	move_object(angel, HERE);
	who->tell_me("You succeeded! Your guardian angel appears in front of you.");
	return 1;
    }
    who->tell_me("Your prayer failed!");
    return 1;
}
