//工部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "yushitai"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"蛛丝马迹","comment":"大人真是剥茧抽丝的一把好手啊。\n","reward":4+random(3),"range":"4-6"]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}
int ask_task()
{
    object me=this_player();
    object ob=this_object(),gy;
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		gy=me->query_temp("song_identification");
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			command("say 大人可代我在大堂升堂(shengtang)问案吗？");
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
