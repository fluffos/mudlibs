#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int damage;
      	damage = me->query_maxkee();
      	damage/= 100;
      	if( damage<150 )
		damage = 150;
      	tell_object(me, HIR"突然你感觉胸口疼痛异常，刚才被「万佛朝宗」拍中的肋骨处好象要裂开了似的，鲜血也从口中喷了出来！\n"NOR);
      	message("vision",HIR + me->name()+"突然一言不发，双手捂胸，蹬蹬磴倒退了数步，接着哇得一声吐出口鲜血来！\n" NOR,environment(me),({ me }));
      	me->receive_wound("kee", damage);      
      	COMBAT_D->report_status(me,1);
	me->set_temp("death_msg","佛印内伤发作死了。\n");
      	me->apply_condition("dashouyin", duration - 1);
	if( duration < 1 )
	{
		if( me->query_temp("death_msg")=="佛印内伤发作死了。\n" )
			me->delete_temp("death_msg");
		return 0;
	}
   	return CND_CONTINUE;
}