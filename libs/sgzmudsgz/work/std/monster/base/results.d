//filename: /std/monster/base/results.c
// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <combat.h>
#define MESS "/daemons/messages_d"
inherit CLASS_COMBAT_RESULT;
object query_weapon();
object query_target();
object query_horse();
void simple_action(string msg, array obs...);
varargs mixed *action(mixed *, mixed, object, object);
void inform(mixed *, mixed, object);
string default_message(int, int);
void unwield();
void die();
void stun();
void knock_out();
void hurt_us(int);
static void print_one_result(class combat_result result) {
	object me,target,my_wep,t_wep,my_horse,t_horse;
	int m_lev,t_lev;
	string my_wep_type,t_wep_type;
    string *msgs;
    string message, mess1,mess2;
    object *combat_who;
	me=this_object();my_wep=me->query_weapon();my_horse=environment(me);
	target=query_target();t_wep=target->query_weapon();t_horse=environment(target);
	m_lev=FIGHT_D->get_att_abi(me);
	m_lev/=20;
	t_lev=FIGHT_D->get_att_abi(target);
	t_lev/=20;
	my_wep_type=my_wep->get_type(); if(!my_wep_type) my_wep_type="unarmed";
	t_wep_type=t_wep->get_type(); if(!t_wep_type) t_wep_type="unarmed";
	mess2="";
    switch(result->special)
    {
	case RES_PARRY: // include 
		mess1=MESSAGES_D->get_fight_message(my_wep_type,"attack",m_lev);
		mess2=MESSAGES_D->get_fight_message(t_wep_type,"parry",t_lev);
		break;
	case RES_DODGE:
		mess1=MESSAGES_D->get_fight_message(my_wep_type,"attack",m_lev);
		if(t_horse->is_horse())
			mess2=MESSAGES_D->get_fight_message(t_wep_type,"dodge-on-horse",t_lev);
		else
			mess2=MESSAGES_D->get_fight_message(t_wep_type,"dodge",t_lev);
		break;
	case RES_TALK:
        mess2="other";
		if(random(2))
			mess2="angry";
		if (m_lev<t_lev)
			if(random(2))
				mess2="praise";
        message=MESSAGES_D->get_detail_messages("combat-msg",mess2);
		me->targetted_action(message,target);
		return;
		
	case RES_HIT:
		mess1=MESSAGES_D->get_fight_message(my_wep_type,"hit",m_lev);
		break;
	case RES_MISS:
		mess1=MESSAGES_D->get_fight_message(my_wep_type,"miss",m_lev);
		break;
	case RES_WAIT:
		if(my_horse->is_horse())
			mess1=MESSAGES_D->get_fight_message(my_wep_type,"wait-on-horse",m_lev);
		else
			mess1=MESSAGES_D->get_fight_message(my_wep_type,"wait",m_lev);
		break;
	default:
		if(my_horse->is_horse())
			mess1=MESSAGES_D->get_fight_message(my_wep_type,"wait-on-horse",m_lev);
		else
			mess1=MESSAGES_D->get_fight_message(my_wep_type,"wait",m_lev);
		break;
    }
    combat_who = ({ me, target });
    msgs = action( combat_who, mess1, my_wep,t_wep,my_horse,t_horse);
    inform( combat_who, msgs, environment() );
	if(sizeof(mess2)) {
	    msgs = action( combat_who, mess2, my_wep,t_wep,my_horse,t_horse);
		inform( combat_who, msgs, environment() );
	}
}
//:FUNCTION print_result
//Print the result of a round of combat
void print_result(class combat_result array arg) {
    foreach (mixed tmp in arg)
    print_one_result(tmp);
}
class combat_result array negotiate_result(class combat_result array result) {
//    result = query_weapon()->adjust_my_result(result);
//    result = query_target()->adjust_result(result);
    return result;
}
static void do_one_result(class combat_result res) {
/*    int s = res->special;
    if (s & RES_NONE)
        return;
    if (s & RES_DISARM) {
        object w = query_weapon();
        unwield();
        w->move(environment());
    }
    if (s & RES_FATAL) {
        die();
        return;
    }
    if (s & RES_KNOCKDOWN)
        stun();
    if (s & RES_KNOCKOUT)
        knock_out();
    hurt_us(res->damage); */
    if (res->special==RES_HIT)
    {   string p_tmp;
	hurt_us(res->damage);
        p_tmp=this_object()->diagnose();
	this_object()->simple_action(p_tmp);
    }
    this_object()->simple_action("\n");
    
}
/* This is actually a misnomer.  It does the result of a round.
 * This is the function to call if you want to do damage to a
 * player (from a spell, etc).
 */
//:FUNCTION do_damage
//Apply a combat result to us.
void do_damage(mixed arg) {
    if (arrayp(arg))
        foreach (mixed res in arg)
            do_one_result(res);
    else
        do_one_result(arg);
}
