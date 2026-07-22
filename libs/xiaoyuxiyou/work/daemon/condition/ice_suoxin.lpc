// ice_suoxin.c
#include <ansi.h>
#include <combat.h>

int update_condition(object me, int duration)
{
	int damage;
	object target;
	target = me->query_temp("IceSuoxin");
	if( duration < 1 || !target || !living(target) || !target->is_fighting(me) )
	{
		me->delete_temp("IceSuoxin");
		if( me->query_temp("death_msg")=="死了，听说其心冷如寒冰。\n" )
			me->delete_temp("death_msg");
		return 0;
	}
	damage = me->query_maxsen()/15+10;
	me->receive_wound("sen", damage,target,TYPE_CAST);
	me->set_temp("death_msg","死了，听说其心冷如寒冰。\n");
	me->apply_condition("ice_suoxin", duration - 1);

	if( (int)me->query("sen") < (int)me->query_maxsen()/4 )
		message_vision("$N嘴唇乌青发亮，浑身抖个不停，不知道中了什么邪。\n", me);
	else if( (int)me->query("sen") < (int)me->query_maxsen()/2 )
		message_vision("$N嘴唇发青，身子微微发抖，好象冷得厉害。\n", me);		
	else 	message_vision("$N打了个寒颤。\n", me);
	if( duration < 1 ) return 0;
	return 1;
}

int no_apply(object who)
{
	string fam;
	if( !who || !living(who) )
		return 0;
	fam = who->query("family/family_name");
	if( !fam || fam!="火云洞" )
		return 0;
	if( random(who->query("max_force"))<500 )
		return 0;
	message_vision(HIR"$N"HIR"身上隐约火光一闪，结果腾起一阵水雾，身上的寒毒一扫而空。\n"NOR,who);
	return 1;
}