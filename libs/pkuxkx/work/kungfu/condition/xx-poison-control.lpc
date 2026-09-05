// 星宿麻痹 Zine 23 oct 2010
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>



int update_condition(object me, int duration)
{
        
        if( duration < 1 ) 
        {
            tell_object(me, HIW "你运转内力，发觉体内奇怪的气息已经被化解得干干净净。\n" NOR );
            me->delete_temp("poison-control");
            return 0;
        }
        
        if( !living(me) )
                message("vision", me->name() + "手臂上升起一道淡淡的黑线。\n", environment(me), me);
        else
        {
                tell_object(me, WHT "你运转内力，似乎有些不妥，却有说不上来。\n" NOR );
                if(environment(me) && environment(me)->query("real_dark") != 1)
                {
                message("vision", me->name() + "手臂上升起一道淡淡的黑线。\n",
                        environment(me), me);
                }
        }
        
        
        me->set_temp("poison-control",1);
        return CND_CONTINUE;
}

string query_type(object me)
{
        return "poison";
}
