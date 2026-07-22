#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int damage;
      
      	damage = me->query_maxkee()/100+1;
      	tell_object(me, "突然你感觉背部疼痛异常，刚才被无常爪抓伤的地方好象要裂开了似的，鲜血也从口中喷了出来！\n");
      	tell_room(environment(me), HIR + me->name()+"突然一言不发，蹬蹬磴倒退了数步，接着哇得一声吐出口鲜血来！\n" NOR,({ me }));
      	me->receive_wound("kee", damage);
      	me->receive_damage("kee", damage);
      	COMBAT_D->report_status(me,1);
	me->set_temp("death_msg","被地府无常爪索魂而死。\n");
      	me->apply_condition("hell_zhua", duration - 1);
       	if( duration < 1 )
	{
		if( me->query_temp("death_msg")=="被地府无常爪索魂而死。\n" )
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
	if( !fam || fam!="方寸山三星洞" )
		return 0;
	if( random(who->query("max_force"))<500 )
		return 0;
	message_vision(HIC"$N"HIC"口中吱吱乱叫，怒发冲冠，周身冤魂顿时化作飞灰。\n"NOR,who);
	return 1;
}