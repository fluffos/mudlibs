#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object target;
	target = me->query_temp("HellSuoming");
	if( !target || !living(target) || !target->is_fighting(me) )
	{
		me->delete_temp("HellSuoming");
		if( me->query_temp("death_msg")=="被地府冤魂索去了性命。\n" )
			me->delete_temp("death_msg");
		return 0;
	}	
	
      	tell_object(me, "你突听耳边传来声声悲寒哭声：还。。。我。。。命。。。来。。。\n");
      	tell_room(environment(me), me->name()+"突然面露惊恐之色，索索寒蝉，神智有些不清！\n"NOR,({ me }));
      	me->receive_wound("kee", duration,target,TYPE_PERFORM);
      	COMBAT_D->report_status(me,1);
	me->set_temp("death_msg","被地府冤魂索去了性命。\n");
	return 1;
}

int no_apply(object who)
{
	string fam;
	if( !who || !living(who) )
		return 0;
	fam = who->query("family/family_name");
	if( !fam || fam!="方寸山三星洞" )
		return 0;
	if( random(who->query("max_force"))<300 )
		return 0;
	message_vision(HIC"$N"HIC"口中吱吱乱叫，怒发冲冠，周身冤魂顿时化作飞灰。\n"NOR,who);
	return 1;
}