// buqu.c 
// Zine 2012/10/14
#include <ansi.h>
#include "special_permit.h"
inherit F_CLEAN_UP;
int help(object me);
int buqu(object me)
{
    int ap,dp;
    if (me)
    {
        if (!me->is_fighting())
        {
        
            ap=(int)me->query_temp("mingspecial/buquap");
            dp=(int)me->query_temp("mingspecial/buqudp");
            me->delete_temp("mingspecial/buquap");
            me->delete_temp("mingspecial/buqudp");
            me->delete_temp("mingspecial/buqu");
            if (wizardp(me))
            {
                tell_object(me,"ap:"+ap+"dp:"+dp+"\n");
            }
            me->add_temp("apply/attack", -ap);
            me->add_temp("apply/damage", -ap);
            me->add_temp("apply/armor",  -dp);
            me->add_temp("apply/parry",  -dp);
            me->add_temp("apply/dodge",  -dp);
            tell_object(me,"力战之后，你不由精神略显萎靡。\n");
            if (me->query("neili")>=2000)
            {
                me->add("neili",-2000);
            }
            if (me->query("neili")<2000)
            {
                me->add("max_neili",-1);
            }
            return 1;
        }
        else
        {
            remove_call_out("buqu");
            call_out("buqu",1,me);
            return 1;
        }
    }
}

int main(object me,string arg)
{
    object room=environment(me);
    object *enemy; //对手
    int count,ap,dp; //对手的数量
    string need="qunzhan";
	if (arg=="-h")
	return help(me);
    if (special_permit(me,need)==0)
    {
		return 1;
    }
    if (!me->is_fighting())
    {
        tell_object(me,"没有对手，你怎么发挥乱战中的优势呢？\n");
        return 1;
    }
    if (me->query_temp("mingspecial/buqu"))
    {
        tell_object(me,"你正在使用群战特技。\n");
        return 1;
    }
    else
    {
        enemy=me->query_enemy();
        count=sizeof(enemy);
        ap=10-(int)me->query("mingpin");
        ap=ap*ap;
        dp=(10-(int)me->query("mingpin"))*count;
        if (wizardp(me))
            {
                tell_object(me,"ap:"+ap+"dp:"+dp+"\n");
            }
        me->add_temp("apply/attack", ap);
        me->add_temp("apply/damage", ap);
        me->add_temp("apply/armor",  dp);
        me->add_temp("apply/parry",  dp);
        me->add_temp("apply/dodge",  dp);
        me->set_temp("mingspecial/buquap",ap);
        me->set_temp("mingspecial/buqudp",dp);
        me->add("neili",500+random(500));
        message_vision(RED"$N陷入敌人围攻却傲然不惧，攻守之间反更见自如。\n"NOR,me);
        me->set_temp("mingspecial/buqu",1);
        remove_call_out("buqu");
        call_out("buqu",1,me);
        return 1;
    }
}
int help(object me)
{
    write("
指令格式 : ming wencai
不屈，面对多个敌人时攻击防御增加，需要大明特技群战。
"    );
    return 1;
}
