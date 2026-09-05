//兵部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "dianqian"
mapping *tasks=({
		(["name":"宫中巡视","comment":"宫中巡视完成，你去休息吧。\n","reward":3+random(3),"range":"3-5",]),
		(["name":"守宫门","comment":"守宫门完成，你去休息吧。\n","reward":2+random(3),"range":"2-4",]),
		(["name":"调兵巡逻皇城","comment":"皇城巡逻完成，你去休息吧。\n","reward":5+random(5),"range":"5-9",]),
		(["name":"换防捧日卫驻地","comment":"换防完毕，你去休息吧。\n","reward":3+random(4),"range":"3-6",]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}

int ask_task()
{
    object me=this_player();
    object ob=this_object();
	string *gates=({"和宁门","丽正门"});
	int n;
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			if (DASONG_D->get_my_pin(me)<5)
			command("say 将军你可代我在宫中巡视(xunshi)一番？");
			else
			command("say 你在宫中巡视(xunshi)一番吧。");
			me->set_temp("songtasks/pass_palace",1);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			n=random(sizeof(gates));
			me->set_temp("songtasks/"+DEPART+"/gate",gates[n]);
			if (DASONG_D->get_my_pin(me)<5)
			command("say 将军你可代我去值守(zhishou)"+gates[n]+"？");
			else
			command("say 你值守(zhishou)"+gates[n]+"吧。");
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==3)
		{
			if (DASONG_D->get_my_pin(me)<5)
			command("say 将军可从殿前都驻地调兵(diao)，出和宁门，绕宫墙巡逻一周后回到和宁门瓮城。");
			else
			command("say 你从殿前都驻地调兵(diao)，出和宁门，绕宫墙巡逻一周后回到和宁门瓮城。");
			tell_object(me,"任务中何处停驻(tingzhu)，何处疾行(jixing)，早有安排，不可乱来。你先自己去绕宫墙一周，自有军士和你说明。\n");
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==4)
		{
			if (DASONG_D->get_my_pin(me)<5)
			command("say 将军可从殿前都驻地调兵(diao)，带领此营官兵前去捧日卫驻地换防。");
			else
			command("say 你从殿前都驻地调兵(diao)，带领此营官兵前去捧日卫驻地换防。");
		}
        pre_1pin(me,DEPART,tasks);
        return 1;
    }
}



