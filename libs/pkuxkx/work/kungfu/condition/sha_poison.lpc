// Modified by whuan,铁砂掌之毒
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;
        if( !living(me) )
                message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
        else
        {
                tell_object(me, HIR "你只觉毒气攻心，顿时感到一股莫名的恶心，全身瘫软无力！\n" NOR );
                message("vision", me->name() + "脸色霎地变的煞白，全身不停的颤抖。\n",
                        environment(me), me);
        }
		F_POISON->poison_eff(me,"sha_poison",(["qi":({0,(random(duration/10+2)+1)*10}),"jing":({1,(random(duration/10+2)+1)*10}),]),1); 
        me->apply_condition("sha_poison", duration - 1);
        return CND_CONTINUE;

}

string query_type(object me)
{
        return "poison";
}
