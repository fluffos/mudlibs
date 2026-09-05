// jili.c 
// Zine 2012/10/14
#include <ansi.h>
#include "special_permit.h"
inherit F_CLEAN_UP;
int help(object me);
int main(object me,string arg)
{
    object room=environment(me);
    int ap,dp,i,count=0;
    object *all=all_inventory(room);
    string need="guwu";
	if (arg=="-h")
	return help(me);
    if (special_permit(me,need)==0)
    {
		return 1;
    }
    if (me->query("neili")<5000)
    {
        tell_object(me,"你此刻体力虚弱，不能使用鼓舞特技。\n");
        return 1;
    }
    else
    {
        ap=7-(int)me->query("mingpin");
        ap=ap*ap;
        dp=10-(int)me->query("mingpin");
        dp=dp*dp;
        message_vision(MAG"$N慷慨陈词：国家危难之际，匹夫当以颈上热血以报！\n"NOR,me);
        me->add("neili",-2000);
        me->add_busy(random(5));
        for (i=0;i<sizeof(all);i++)
        {
            if ((all[i]->query("mingpin")||all[i]->query("ming/tj/pin")||(all[i]->is_army()&&all[i]->query("side")=="ming"))&&!all[i]->query_temp("mingspecial/jiligot"))
            {
                count=count+1;
                if (all[i]->is_character())
                {
                    all[i]->add_temp("apply/attack", ap);
                    all[i]->add_temp("apply/damage", ap);
                    all[i]->add_temp("apply/armor",  dp);
                    all[i]->add_temp("apply/parry",  dp);
                    all[i]->set_temp("mingspecial/jiligot",1);
                    all[i]->set_temp("mingspecial/jiliap",ap);
                    all[i]->set_temp("mingspecial/jilidp",dp);
                    all[i]->apply_condition("damingjili", 2+random(15-(int)me->query("mingpin")));
                    tell_object(all[i],"听了"+me->query("name")+"的鼓舞之辞，你不由热血澎湃起来。\n");
                }
                if (all[i]->is_army()&&me->query("ming/energy")>10)
                {
                    me->add("ming/energy",-10);
                    tell_object(me,"你消耗了10点行动力，激励了"+all[i]->query("name")+"的士气！\n");
                    all[i]->add("shiqi",10);
                    message_vision(HIW"$N中众人应道：“天佑大明！”\n"NOR,all[i]);
                }
            }
        }
        if (count==0)
        {
            tell_object(me,"你喊了半天，发现周身根本没有大明的人！\n");
        }
        return 1;
    }
}
int help(object me)
{
    write("
指令格式 : ming wencai
增加队友的攻防，需要大明特技鼓舞。
"    );
    return 1;
}
