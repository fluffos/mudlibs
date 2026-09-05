#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "jianyuan"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"提供建议","comment":"又提了一条建议！\n","reward":2,"range":"2-2"]),
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
			command("say 大宋草创，还有很多不合理的地方，谏院的作用就是提供建议，大人的建议非常关键。");
			tell_object(me,"你可以在谏院大厅post你的建议内容，完成任务。内容需要被核定后才能发放奖励，差给予灌水内容或者重复内容，言之有物将获得中评，优评给予经常的内容。\n");
			tell_object(me,"分别可获得扣两点大宋功勋度、加两点大宋功勋度以及加四点大宋功勋度的处理。\n");
			tell_object(me,"如果觉得无甚内容（建议，意见）可说，可直接在这里输入giveup，放弃任务，将没有任何cd，重新回政事堂获取新任务。\n");
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
