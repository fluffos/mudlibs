#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int p;
	p = 500;
	if( !living(me) )
      		message("vision", me->name()+"使劲地打了个喷嚏！\n", environment(me), me);
	else 
	{
      		tell_object(me, "你觉得鼻子里面痒痒的，打了个大喷嚏。\n");
      		message("vision", HIR""+me->name() + "身中情毒，痛苦的按着胸口．\n"NOR,environment(me), me);
   	}
   	me->set_temp("death_msg","脑裂而亡了。\n");
   	me->receive_wound("kee", p);
   	me->receive_damage("kee", p);
   	me->apply_condition("xiangsi", duration - 1);
	if( duration < 1 ) 
	{
		if( me->query_temp("death_msg")=="脑裂而亡了。\n" )
			me->delete_temp("death_msg");
		return 0;
	}
   	return CND_CONTINUE;	
}

int no_apply(object who)
{
	string fam;
	if( !who || !living(who) )
		return 0;
	fam = who->query("family/family_name");
	if( !fam || fam!="五庄观" )
		return 0;
	if( random(who->query("max_force"))<300 )
		return 0;
	message_vision(HIC"$N"HIC"背后隐现人参果树幻象，整个人静如高山，忘情而立。\n"NOR,who);
	return 1;
}