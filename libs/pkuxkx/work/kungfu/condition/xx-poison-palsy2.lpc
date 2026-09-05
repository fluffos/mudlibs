// 星宿麻痹 Zine 23 oct 2010
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
        int lv;
        lv=me->query_skill("poison",1)/3;
        lv=lv+1;
        if (lv>4)
        {
            lv=4;
        }
        if( duration < 1 ) return 0;
        if (me->query("con")/6 > duration)//高根骨减少发作次数
        {
            tell_object(me, HIW "你运起本门纯正内功，强行控制住周身气息。\n" NOR );
            return 0;
        }
        
        if( !living(me) )
                message("vision", me->name() + "周身肌肉不受控制地乱动起来。\n", environment(me), me);
        else
        {
                tell_object(me, WHT "你周身肌肉不受控制地乱动起来，痛苦异常。\n" NOR );
                if(environment(me) && environment(me)->query("real_dark") != 1)
                {
                message("vision", me->name() + "周身肌肉不受控制地乱动起来，痛苦异常。\n",
                        environment(me), me);
                }
        }
		F_POISON->poison_eff(me,"xx-poison-palsy2",(["busy":({4,lv}),]),1); 
        me->apply_condition("xx-poison-palsy2", duration - 1);
        return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
