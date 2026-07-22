// moon_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("sen", duration);
	me->receive_damage("sen", duration);
	me->receive_damage("kee", duration);
	me->receive_wound("kee", duration);
	me->set_temp("death_msg","精力耗尽而死。\n");
	me->apply_condition("moon_poison", duration-1);
	tell_object(me, HIG "你感觉身体一点点虚弱下去！\n" NOR );
	if( duration < 1 )
	{
		if( me->query_temp("death_msg")=="精力耗尽而死。\n" )
			me->delete_temp("death_msg");
		return 0;	
	}
	return 1;
}

int no_apply(object who)
{
	string fam;
	if( !who || !living(who) )
		return 0;
	fam = who->query("family/family_name");
	if( !fam || fam!="南海普陀山" )
		return 0;
	if( random(who->query("max_force"))<500 )
		return 0;
	message_vision(HIY"$N"HIY"身上佛光一闪，结果诸多幻象顿如井中水月。\n"NOR,who);
	return 1;
}