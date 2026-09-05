//工部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#include "armytask.h"
#define DEPART "longwei"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"城南绿林","comment":"城南尽头的绿林整编新军完成，不错。\n","reward":6+random(2),"range":"6-7"]),
		(["name":"招募新军","comment":"新军招来，你下去去休息吧。\n","reward":2+random(5),"range":"2-6",]),
		(["name":"突袭敌匪","comment":"敌匪消灭，你下去去休息吧。\n","reward":6+random(7),"range":"6-12",]),
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
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		gy=me->query_temp("song_identification");
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：朝廷现在最缺一支劲旅，我去整编城南尽头绿林里的豪杰吧。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<4)
			command("say 朝廷现在最缺一支劲旅，大人请去整编城南尽头绿林里的豪杰吧。");
			else
			message_vision("$N看着$n，道：朝廷现在最缺一支劲旅，我先派你去整编城南尽头绿林里的豪杰吧。\n",ob,me);
		}
		if (member_array(me->query_temp("songtasks/"+DEPART+"/task"),({2,3}))!=-1)
		{
			armytask(me,ob,gy,DEPART);
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
