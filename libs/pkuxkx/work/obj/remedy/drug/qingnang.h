#include <ansi.h>
#define ALLOW_SHIKE 5
#include "eat.h"

int do_eat(string arg)
{
	mixed *tm=localtime(time());
    string date=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
	object me=this_player(),ob=this_object();
	if (!can_eat(ob,arg)) return 0;
	if (ob->query("qingnang")==1&&time()<me->query("tianmuQuests/dashigu/dashi_eat"))
	{
		write("你最近已经服用过"+ob->query("name")+"了，每四十八小时只能服用一"+ob->query("unit")+"。\n");
		return 1;
	}
	if (ob->query("qingnang")==2&&time()<me->query("tianmuQuests/dashigu/kanli_eat"))
	{
		write("你最近已经服用过"+ob->query("name")+"了，每七十二小时只能服用一"+ob->query("unit")+"。\n");
		return 1;
	}
	if (ob->query("qingnang")==3&&me->query("tianmuQuests/dashigu/shike_eat")!=date)
	{
		me->set("tianmuQuests/dashigu/shike_eat",date);
		me->set("tianmuQuests/dashigu/shike_eat_times",0);
	}
	if (me->query("tianmuQuests/dashigu/shike_eat_times")>=ALLOW_SHIKE)
	{
		write(ob->query("name")+"你今日已经服用过"+chinese_number(ALLOW_SHIKE)+ob->query("unit")+"了，再次服用恐将伤害身体。\n");
		return 1;
	}
	message_vision("$N十分小心地服下了一"+ob->query("unit")+ob->query("name")+"。\n",me);
	if (ob->query("qingnang")==1)
	{
		if ((F_PRO->pro_class(me)=="fighter"&&time()<me->query("double_reward"))||(F_PRO->pro_class(me)!="fighter"&&time()<me->query("pro_double_reward")))
		{
			tell_object(me,"你现在正处于双倍奖励状态中或同类药性相冲。\n");
			return 1;
		}
		if (me->query("level") < 50)
		{
			 return notify_fail("你的等级太低了，使用此等高级丹药肯定没有效果的！\n");
		}
		me->set("tianmuQuests/dashigu/dashi_eat",time()+172800);
		tell_object(me,HIG+"你服下了一"+ob->query("unit")+ob->query("name")+HIG+"，觉得灵台清明，正是修行的好时候。\n"+NOR);
		if (F_PRO->pro_class(me)=="fighter")
		{
			me->set("doublereward",time()); //赋值到系统狂欢变量1
			me->set("double_reward",time()+1800);  //赋值到系统狂欢变量2
		}
		else
		{
			me->set("pro_double_reward",time()+1800);
		}
	}
	if (ob->query("qingnang")==2)
	{
		me->set("tianmuQuests/dashigu/kanli_eat",time()+259200);
		me->set("tianmuQuests/dashigu/kanli_effect",time()+10800);
	}
	if (ob->query("qingnang")==3)
	{
		me->add("tianmuQuests/dashigu/shike_eat_times",1);
		F_POISON->detoxicate(me,"all_poisons");
		message_vision(HIG+"$N"+HIG+"服下"+ob->query("name")+HIG+"之后，身上所有毒素都被压制住了。\n"NOR,me);
	}
	destruct(ob);
	return 1;
}

