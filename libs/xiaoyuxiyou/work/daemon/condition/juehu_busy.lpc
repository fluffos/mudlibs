//Cracked by Roath
//xiangsi.c
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) 
	{
		if( me->query_temp("death_msg")=="九阴绝户内伤发作死了。\n" )
			me->delete_temp("death_msg");
		return 0;
	}
   	if( !living(me) ) 
		message("vision", HIR""+me->name() + "只感到下体一阵刺痛，体内精元不断外泄，顿时觉的四肢无力，两腿不停颤抖。\n"NOR, environment(me), me);
	else 
	{
      		tell_object(me, HIR "你身中的九阴绝户内伤发作了。\n" NOR );
      		message("vision", HIR""+me->name() + "只感到下体一阵刺痛，体内精元不断外泄，顿时觉的四肢无力，两腿不停颤抖。\n"NOR,environment(me), me);
   	}
   	me->set_temp("death_msg","九阴绝户内伤发作死了。\n");
   	me->receive_wound("kee", 80);
   	me->receive_damage("kee", 100);
   	me->receive_wound("sen", 80);
   	me->receive_damage("sen", 100);
   	me->apply_condition("juehu_busy", duration - 1);
	return 1;
}

int no_apply(object who)
{
	string fam;
	if( !who || !living(who) )
		return 0;
	fam = who->query("family/family_name");
	if( !fam || fam!="陷空山无底洞" )
		return 0;
	if( random(who->query("max_force"))<500 )
		return 0;
	message_vision(HIR"$N"HIR"周身血气冲天，煞气滚滚，诸恶勿近。\n"NOR,who);
	return 1;
}