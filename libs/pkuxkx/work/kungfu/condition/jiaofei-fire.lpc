inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>
 
int update_condition(object me, int duration)
{
    if(me->query("jiaofei/fire_damage") <= 0) 
    {
        tell_object(me, BLU"你身上的火焰终于慢慢熄灭了，你侥幸逃的一死。\n" NOR );
        message("vision", me->name() + "身上的火焰终于慢慢熄灭了。\n",environment(me), me);
        return 0;
    }
        
    tell_object(me, BLU"烈火在你的身上肆虐，烤焦了你的皮肤，烤干了你的血液。\n" NOR );
    message("vision", me->name() + "被大火烧得四肢乱舞，哇哇乱叫，赶快找水救他啊！\n",environment(me), me);
 
	me->receive_damage("qi", me->query("jiaofei/fire_damage"), "熊熊烈火烧");
	me->receive_wound("qi", me->query("jiaofei/fire_damage")/8, "熊熊烈火烧");
    COMBAT_D->report_status(me);
    me->apply_condition("jiaofei-fire", duration - 1);
    if( duration < 1 ) return 0;
    return CND_NO_HEAL_UP;
}

string query_type(object me)
{
        return "fire";
}
