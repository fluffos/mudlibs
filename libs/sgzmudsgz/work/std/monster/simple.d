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
private class combat_result make_result(int att_ab,int att_pow, int def_ab, int def_pow)
{
    class combat_result ret = new(class combat_result);
    int tmp,tmp2;
    if(random(4)==0)
    {
	ret->special=RES_TALK;
  	ret->damage=0;
	return ret;
    }
    tmp=att_ab-def_ab+500;
    tmp2=random(1000);
    if(tmp2<tmp)
    {
	ret->special=RES_HIT;
	tmp=att_pow-def_pow+50;
        if(tmp<1)
                tmp=1;
	ret->damage=random(tmp)/3;
	return ret;
    }
    if(random(2))
    {
	ret->special=RES_PARRY;
	ret->damage=0;
	return ret;
    }
    if(random(3))
    {
	ret->special=RES_DODGE;
	ret->damage=0;
	return ret;
    }
    ret->special=RES_WAIT;
    ret->damage=0;
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
int query_horse_att_ab()
{
	int p_res=0;
        object env = environment(this_object());
        if(env->is_horse()) // 骑在马上
        {
		p_res=env->query_attack_ability();
        }
	return p_res;
}
int query_horse_def_ab()
{
	int p_res=0;
        object env = environment(this_object());
        if(env->is_horse()) // 骑在马上
        {
		p_res=env->query_defence_ability();
        }
	return p_res;
}
int query_horse_att_pow()
{
	int p_res=0;
        object env = environment(this_object());
        if(env->is_horse()) // 骑在马上
        {
		p_res=env->query_attack_power();
        }
	return p_res;
}
int query_armor_att_ab()
{
	int p_res=0;
        mixed stat;
        foreach (object ob2 in all_inventory(this_object())) 
        {
                
                stat=ob2-> ob_state() ;
                if(stringp(stat))
                {
			p_res+=ob2->query_attack_ability();
		}
	}
	return p_res;
}
int query_armor_def_ab()
{
	int p_res=0;
        mixed stat;
        foreach (object ob2 in all_inventory(this_object())) 
        {
                
                stat=ob2-> ob_state() ;
                if(stringp(stat))
                {
			p_res+=ob2->query_defence_ability();
		}
	}
	return p_res;
}
int query_armor_def_pow()
{
	int p_res=0;
        mixed stat;
        foreach (object ob2 in all_inventory(this_object())) 
        {
                
                stat=ob2-> ob_state() ;
                if(stringp(stat))
                {
			p_res+=ob2->query_defence_power();
		}
	}
	return p_res;
}
int query_weapon_att_ab()
{
	int p_res=0;
        object obw=this_object()->query_weapon();
        if((objectp(obw))&&(obw!=this_object()))
        {
		p_res=obw->query_attack_ability();
        }
	return p_res;
}
int query_weapon_def_ab()
{
	int p_res=0;
        object obw=this_object()->query_weapon();
        if((objectp(obw))&&(obw!=this_object()))
        {
		p_res=obw->query_defence_ability();
        }
	return p_res;
}
int query_weapon_att_pow()
{
	int p_res=0;
        object obw=this_object()->query_weapon();
        if((objectp(obw))&&(obw!=this_object()))
        {
		p_res=obw->query_attack_power();
        }
	return p_res;
}
int query_att_ab()
{
	int p_cur_hp,p_cur_max_hp,p_max_hp;
	int p_wuli,p_weapon_att;
	int p_armor_att,p_horse_att;
	int p_res,p_tmp;
	p_cur_hp=query_cur_hp();
	p_cur_max_hp=query_cur_max_hp();
	p_max_hp=query_sg_max_hp();
	p_wuli=this_object()->query_sk_level("sk_wuli");
	p_res=p_wuli*10;
	p_tmp=100;
	if(p_max_hp)
	{
		p_tmp=100*p_cur_max_hp/p_max_hp;
		p_tmp+=100;
	}
	p_res=p_res*p_tmp/200;
	p_tmp=100;
	if(p_cur_max_hp)
	{
		p_tmp=100*p_cur_hp/p_cur_max_hp;
		p_tmp+=100;
	}
	p_res=p_res*p_tmp/200;
	p_armor_att=query_armor_att_ab();
	p_weapon_att=query_weapon_att_ab();
	p_horse_att=query_horse_att_ab();
	p_res=p_res+p_armor_att+p_horse_att+p_weapon_att;
	return p_res;
}
int query_att_pow()
{
	int p_cur_hp,p_cur_max_hp,p_max_hp;
	int p_wuli,p_weapon_att;
	int p_horse_att;
	int p_res,p_tmp;
	p_cur_hp=query_cur_hp();
	p_cur_max_hp=query_cur_max_hp();
	p_max_hp=query_sg_max_hp();
	p_wuli=this_object()->query_sk_level("sk_wuli");
	p_res=p_wuli*2;
	p_tmp=100;
	if(p_max_hp)
	{
		p_tmp=100*p_cur_max_hp/p_max_hp;
		p_tmp+=100;
	}
	p_res=p_res*p_tmp/200;
	p_tmp=100;
	if(p_cur_max_hp)
	{
		p_tmp=100*p_cur_hp/p_cur_max_hp;
		p_tmp+=100;
	}
	p_res=p_res*p_tmp/200;
	p_weapon_att=query_weapon_att_pow();
	p_horse_att=query_horse_att_pow();
	p_res=p_res+p_horse_att+p_weapon_att;
	return p_res;
}
int query_def_ab()
{
	int p_cur_hp,p_cur_max_hp,p_max_hp;
	int p_wuli,p_weapon_def;
	int p_armor_def,p_horse_def;
	int p_res,p_tmp;
	p_cur_hp=query_cur_hp();
	p_cur_max_hp=query_cur_max_hp();
	p_max_hp=query_sg_max_hp();
	p_wuli=this_object()->query_sk_level("sk_wuli");
	p_res=p_wuli*8;
	p_tmp=100;
	if(p_max_hp)
	{
		p_tmp=100*p_cur_max_hp/p_max_hp;
		p_tmp+=100;
	}
	p_res=p_res*p_tmp/200;
	p_tmp=100;
	if(p_cur_max_hp)
	{
		p_tmp=100*p_cur_hp/p_cur_max_hp;
		p_tmp+=100;
	}
	p_res=p_res*p_tmp/200;
	p_armor_def=query_armor_def_ab();
	p_weapon_def=query_weapon_def_ab();
	p_horse_def=query_horse_def_ab();
	p_res=p_res+p_armor_def+p_horse_def+p_weapon_def;
	return p_res;
}
int query_def_pow()
{
	int p_cur_hp,p_cur_max_hp,p_max_hp;
	int p_wuli;
	int p_armor_def;
	int p_res,p_tmp;
	p_cur_hp=query_cur_hp();
	p_cur_max_hp=query_cur_max_hp();
	p_max_hp=query_sg_max_hp();
	p_wuli=this_object()->query_sk_level("sk_wuli");
	p_res=p_wuli*2;
	p_tmp=100;
	if(p_max_hp)
	{
		p_tmp=100*p_cur_max_hp/p_max_hp;
		p_tmp+=100;
	}
	p_res=p_res*p_tmp/200;
	p_tmp=100;
	if(p_cur_max_hp)
	{
		p_tmp=100*p_cur_hp/p_cur_max_hp;
		p_tmp+=100;
	}
	p_res=p_res*p_tmp/200;
	p_armor_def=query_armor_def_pow();
	p_res=p_res+p_armor_def;
	return p_res;
}
class combat_result array take_a_swing(object target)
{
    int diff=0;
    class combat_result array result;
    int p_m_att_ab,p_t_def_ab;
    int p_m_att_pow,p_t_def_pow;
    p_m_att_ab=query_att_ab();
    p_m_att_pow=target->query_att_pow();
    p_t_def_ab=target->query_def_ab();
    p_t_def_pow=target->query_def_pow();
    return ({ make_result(p_m_att_ab,p_m_att_pow,p_t_def_ab,p_t_def_pow) });
}
