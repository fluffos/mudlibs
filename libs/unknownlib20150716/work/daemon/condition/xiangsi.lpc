//Cracked by Roath
//xiangsi.c
#include <ansi.h>

int update_condition(object me, int duration)
{
	int p;
   	duration=duration-1;
	if( duration < 1 ) 
	{
		if( me->query_temp("death_msg")=="情毒发作死了。\n" )
			me->delete_temp("death_msg");
		return 0;
	}
   	me->apply_condition("xiangsi", duration);	
	p = me->query_maxkee()/100+100;
	if( !living(me) )
      		message("vision", HIR""+me->name() + "身中情毒，痛苦的按着胸口．\n"NOR, environment(me), me);
	else 
	{
      		tell_object(me, HIR "情毒发作了。\n" NOR );
      		message("vision", HIR""+me->name() + "身中情毒，痛苦的按着胸口．\n"NOR,environment(me), me);
   	}
   	me->set_temp("death_msg","情毒发作死了。\n");
   	me->receive_wound("kee", p);
   	me->receive_damage("kee", p);
   	return 1;
}

int no_apply(object who)
{
	string fam;
	if( !who || !living(who) )
		return 0;
	fam = who->query("family/family_name");
	if( !fam || fam!="五庄观" )
		return 0;
	if( random(who->query("max_force"))<500 )
		return 0;
	message_vision(HIC"$N"HIC"背后隐现人参果树幻象，整个人静如高山，忘情而立。\n"NOR,who);
	return 1;
}