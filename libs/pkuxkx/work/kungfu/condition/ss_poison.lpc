inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( duration < 1 )
    {
        me->delete_temp("death_cond_origin/ss_poison");
        return 0;
    }

    if( !living(me) )
    {
            message("vision", me->name() + "身子扭来扭去，痛苦地哼了一声。\n", environment(me), me);
    }
    else
    {
            tell_object(me, HIB "突然你倒在地上，滚来滚去，双手抓脸，又撕烂了胸口衣服，跟着猛力撕抓胸口，竟似要挖出自己的心肺一般。\n" NOR );
            message("vision", me->name() + "突然倒在地上，滚来滚去，双手抓脸，又撕烂了胸口衣服，跟着猛力撕抓胸口，竟似要挖出自己的心肺一般。\n",
                    environment(me), me);
    }
    me->set_temp("death_cond_id", "ss_poison");
	F_POISON->poison_eff(me,"ss_poison",(["qi":({1,15 + random(36)}),"jing":({1,20+random(101)}),]),1); 
    me->apply_condition("ss_poison", duration - 1);

    return CND_CONTINUE;
}

string query_type(object me)
{
    return "poison";
}

