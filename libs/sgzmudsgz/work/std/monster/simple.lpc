// Updated by stefan on 10 Jan 1997
// modified by fire on March 1 1998
/* Do not remove the headers from this file! see /USAGE for more info. */
// the simple combat module; used when COMBAT_STYLE is COMBAT_SIMPLE in
// /include/config_combat.h
#include <combat.h>
#include <classes.h>
inherit __DIR__ "base";
string default_message(int dam, int them) {
    if (dam <= 0) return "!none";
    if (dam == 1) return "!light";
    return "!serious";
}
void fight_reward(int p_reward)
{
	object o=this_object();
	string skill,w_id,p_id;
	object wep;
	int wxxy_level,wep_level,wep_exp;
	wep=o->query_weapon();
	if(!wep->sg_obj()) 
		skill="unarmed";
	else {
		w_id=wep->query_id()[0];
		skill=OBJ_D->get_obj(w_id,"sub_type");
	}
	if(!random(3)) // 1 / third get reward on horse
	{
		object env;
		env=environment(o);
		if(env->is_horse())
			skill="horse";
		else
			skill="dodge";
	}
	o->award_exp(p_reward,skill);

	wxxy_level=o->query_sk_level("sk_wuli");
	wep_level=o->query_sk_level(skill);
	wep_exp=o->query_sk_exp(skill);
	if((wxxy_level>wep_level)&&(wep_exp>((wep_level+1)*(wep_level+1))))
	{
		o->set_sg_skill(skill,wep_level+1,0);
		tell(o,"%^H_MAGENTA%^你的「"+SG_SKILL_D->query_name(skill)
			+"」进步了。%^RESET%^\n");
	}
}
private class combat_result make_result(int p_hit,int p_hurt)
{
    class combat_result ret = new(class combat_result);
	ret->damage=p_hurt;
	ret->special=RES_HIT;
	if(!p_hit) {
		switch(random(6))
		{
		case 0: 
			ret->special=RES_TALK;
			break;
		case 1:
			ret->special=RES_DODGE;
			break;
		case 2:
			ret->special=RES_MISS;
			break;
		case 3:
			ret->special=RES_WAIT;
			break;
		default:
			ret->special=RES_PARRY;
		}
	}
    return ret;
}
void mudlib_setup() {
    ::mudlib_setup();
    
    /* self is an M_DAMAGE_SOURCE. initialize it. */
    set_combat_messages("combat-unarmed");
    //The bonus we get for fighting barehanded. Usually negative (weaponshelp)
    set_wield_bonus(-3);
    /* by pinging query_weapon(), we will default to self as a weapon */
    (void)query_weapon();
}
/* This is the big honking "take a swing" subroutine.  Normally,
it it called from heart_beat(), but can be called from elsewhere
to implement multiple attacks, etc.  Note that the fight must
already be started, though.  It takes a swing at the current
target. */
//:FUNCTION take_a_swing
//Take a swing at the person we are attacking
class combat_result * take_a_swing(object target)
{
    class combat_result * result;
	int p_hit,p_hurt=0,p_reward;
	p_hit=FIGHT_D->prb_hit(this_object(),target);
	if(p_hit){
		p_hurt=FIGHT_D->hurt_point(this_object(),target);
		if((this_object()->query_link())&&(!target->query_link()))
		{
			p_reward=FIGHT_D->reward(this_object(),target);
			fight_reward(p_reward);
		}
	}
    return ({ make_result(p_hit,p_hurt) });
}
