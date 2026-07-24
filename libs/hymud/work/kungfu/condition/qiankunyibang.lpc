
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        int damage, p;
        string msg;
      
        damage = me->query_condition("qiankunyibang")/5 +2;
if (userp(me))
	{
	 damage *= me->query_con();
}
else
	{
 damage *= random(30)+1;		
}		
      
        tell_object(me, "突然你感觉胸口疼痛异常，浑身无力，骨头像散架似的，鲜血从伤口口中涌了出来！\n");
message("vision", me->name() + "突然一言不发，双手捂胸，蹬蹬磴倒退了数步，接着哇得一声吐出口鲜血来！\n",
            environment(me), me);
//        tell_room(environment(me), HIR + me->name()+"突然一言不发，双手捂胸，蹬蹬磴倒退了数步，接着哇得一声吐出口鲜血来！\n" NOR,({ me }));
        me->receive_damage("qi", damage/2);
        me->receive_wound("qi", damage/2);
        me->start_busy(random(2));
        me->apply_condition("qiankunyibang", duration - 1);
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
