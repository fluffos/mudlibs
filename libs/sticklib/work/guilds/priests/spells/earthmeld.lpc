/*
 * earthmeld: player can meld to the earth, but this spell works only outdoors.
 * Currently in testing mode, players can't use yet.
 * I think there should be more checks or something.. it's a bit too simply now imo
 */

#include "priest_spell.h"

void begin_earthmeld(object who, mixed victim);
status do_earthmeld(object who, mixed victim);

#define SENSE_RANK 10

void
create_spell() {
    // testing = 1; // players can't use yet
    dif = 30;
    lvl = 19;
    cost = 50;
    duration = 3; // 3 rounds when in combat, otherwise 1.5
    skills_used = ({SK_SERENITY, SK_NATURE, SK_FORCES});
    skill_p = ({30,50,20});
    funs = ({ #'begin_earthmeld, #'do_earthmeld });
}


void
begin_earthmeld(object who, mixed data)
{
    object ob;
    if(HERE->query(ROOM_WD) != WD_OUTDOORS) {
	who->tell_me("You look at the floor, but don't think it would be \
suitable for melding into it.");
	data = 0;
	return;
    }
    data = HERE;
    who->tell_me("You kneel down, touch the ground and start praying.");
    if(who->query_invis())
	HERE->tell_here("You hear someone praying.", who);
    else
	HERE->tell_here(":%<me.capname>% kneel%<me.ending_s>% down, touch\
%<me.ending_es>% the ground and start%<me.ending_s>% praying.",
	  0,0,who,who,0,0);
}


status
do_earthmeld(object who, mixed data)
{
    object sym, temp_room, cur_room;
    int skill;
    object ob;

    sym = who->query_guild_object();
    skill = get_skill(sym);
    inc_skills(who, sym, 100);
    who->add_sp(-cost);
    if(data != HERE) {
	who->tell_me("Your concentration breaks as you move to other room");
	return 1;
    }
    if(skill_roll(sym, skill) > 0) {
	temp_room = clone_object(PRIEST_ROOM_DIR "earth_meld_room");
	ob = clone_object(PRIEST_OBJ_DIR "earth_meld_obj");
	ob->set_pl(who, get_skill_rank(skill2pex(skill)) > SENSE_RANK);
	cur_room = HERE;
	temp_room->set_previous_room(cur_room, who, ob);

	who->tell_me("You meld to the ground!");
	who->move_player("Vmelds to the ground", temp_room);
	move_object(ob, cur_room);

	return 1;
    }
    who->tell_me("Your prayer failed!");
    if(!who->query_invis())
	HERE->tell_here(":%<me.capname>% looks rather dissapointed.",
	  0,0,who,who,0,0);
    return 1;
}
