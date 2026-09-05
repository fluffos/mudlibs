//兵部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "dushui"
mapping *tasks=({
		(["name":"长江筑堤","comment":"长江南岸的决口都被堵住了。\n","reward":2+random(2),"range":"2-3",]),
		(["name":"钱塘江筑堤","comment":"希望来年海潮不会冲毁庄稼。\n","reward":2+random(2),"range":"2-3",]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}

int ask_task()
{
    object me=this_player();
    object ob=this_object(),wg;
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			if (DASONG_D->get_my_pin(me)<5)
			command("say 大人可以视察一下长江南岸的水情吗？");
			else
			command("say 你去查看一下长江南岸的水情吧。");
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			if (DASONG_D->get_my_pin(me)<5)
			command("say 大人可以帮助检查一下钱塘江的堤防吗？");
			else
			command("say 你去检查一下钱塘江的堤防吧。");
		}
        ob->pre_1pin(me,DEPART,tasks);
        return 1;
    }
}



