//工部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "taiyiyuan"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"采集药材","comment":"大人百忙之余，还为太医局找来合用的药材，感激不尽。\n","reward":3+random(9),"range":"3-11"]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}
int ask_task()
{
	int n;
    object me=this_player();
    object ob=this_object(),gy;
	string *drug=({"鸡血藤","薄荷","鱼腥草","常山","当归","丁香","茯苓","覆盆子","合欢","荆芥","地骨皮","蛇床子","生甘草"});
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			n=random(sizeof(drug));
			if (DASONG_D->get_my_pin(me)<5)
			command("say 我这里缺少药材，大人能帮我找一味"+drug[n]+"吗？");
			else
			message_vision("$N苦着脸，对$n道：我这里缺少药材，你去找一味"+drug[n]+"回来吧。\n",ob,me);
			me->set_temp("songtasks/taiyiyuan/drug",drug[n]);
			me->set_temp("songtasks/taiyiyuan/target",n+1);
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
