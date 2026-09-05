inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int remove_eff(object me)
{
    if ( objectp(me) )
      me->delete_temp("no_dazhi-wuding");
    return 1;
}

int update_condition(object me, int duration)
{
    int buff;
    if( duration < 1 ) 
    {
        buff=(40-(int)me->query_skill("yizhi-chan",1)/40);
        if (buff<10)
        {
            buff=10;
        }
        call_out("remove_eff",buff,me);
        me->delete_temp("dazhi-wuding");
        return 0;
    }
    else
    {
        if ((int)me->query("neili")<(int)me->query("max_neili")/3)
        {
            me->delete_temp("dazhi-wuding");
            tell_object(me,"你内力不足，再也压制不住闭下的要穴。\n");
        }
        me->apply_condition("dazhi-wuding", duration - 1);
        return 1;
    }
}
