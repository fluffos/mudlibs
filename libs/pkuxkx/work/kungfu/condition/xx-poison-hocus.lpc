// 星宿麻痹 Zine 23 oct 2010
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>


int update_condition(object me, int duration)
{
        int poison=me->query_skill("poison",1)/100;
        if (poison<1)
        {
            poison=1;
        }
        if( duration < 1 ) 
        {
            tell_object(me, HIW "你莫名其妙地压制住了丹田中乱窜的气息。\n" NOR );
			F_POISON->poison_eff(me,"xx-poison-hocus",(["armor":({3,me->query_temp("poison-hocus-count")*2}),"dexerity":({3,me->query_temp("poison-hocus-count")}),]),1); 
            me->delete_temp("poison-hocus-count");
            return 0;
        }
        if (random(10)==6)//偶然事件自行痊愈
        {
            tell_object(me, HIW "你莫名其妙地压制住了丹田中乱窜的气息。\n" NOR );
			F_POISON->poison_eff(me,"xx-poison-hocus",(["armor":({3,me->query_temp("poison-hocus-count")*2}),"dexerity":({3,me->query_temp("poison-hocus-count")}),]),1); 
            me->delete_temp("poison-hocus-count");
            return 0;
        }
        
        if( !living(me) )
                message("vision", me->name() + "丹田中气息乱窜，手脚渐渐不协调起来。\n", environment(me), me);
        else
        {
                tell_object(me, WHT "你暗道一声不妙，似乎失去了对身体的控制。\n" NOR );
                if(environment(me) && environment(me)->query("real_dark") != 1)
                {
                message("vision", me->name() + "丹田中气息乱窜，手脚渐渐不协调起来。\n",
                        environment(me), me);
                }
        }
        
		F_POISON->poison_eff(me,"xx-poison-hocus",(["armor":({3,-me->query_temp("poison-hocus-count")*2}),"dexerity":({3,-me->query_temp("poison-hocus-count")}),]),1); 
        me->add_temp("poison-hocus-count",poison);
        return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
