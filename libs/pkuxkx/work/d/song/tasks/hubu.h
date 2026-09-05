//刑法部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "hubu"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"江南地图造册","comment":"地图造册完成？看来你还真不简单啊。\n","reward":5+random(6),"range":"5-10"]),
		(["name":"帮助编制户籍","comment":"你简直是神算啊。\n","reward":1+random(4),"range":"1-4"]),
		(["name":"户部库房抓内鬼","comment":"内鬼抓到了？真的啊！\n","reward":2+random(2),"range":"2-3"]),
		(["name":"整理户部库房","comment":"居然整理得井井有条！\n","reward":10+random(2),"range":"10-11"]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}
int ask_task()
{
    object me=this_player();
    object ob=this_object(),gy,xinzha;
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		gy=me->query_temp("songtasks/guanyin");
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			xinzha=new("/d/song/obj/xinzha");
            xinzha->move(me);
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N对着$n道：江南历经兵乱，很多地区地图缺失，我去监督"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 江南历经兵乱，很多地区地图缺失，大人去监督"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"。");
			else
			{
				message_vision("$N看着$n，道：江南历经兵乱，很多地区地图缺失，我先派你去"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"吧。\n",ob,me);
				message_vision("$N给了$n一封信扎。\n",ob,me);
			}
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			this_object()->question(me);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==3)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：户部库房的宝钞最近总是失窃，本官前去坐镇。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 户部库房的宝钞最近总是失窃，大人去监督一下。");
			else
			message_vision("$N看着$n，道：户部库房的宝钞最近总是失窃，我派你去看看吧。\n",ob,me);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==4)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：户部库房的堆放的货品过于凌乱，本官去整理(zhengli)一下。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 户部库房的堆放的货品过于凌乱，大人能去整理(zhengli)一下吗？");
			else
			message_vision("$N看着$n，道：户部库房的堆放的货品过于凌乱，你去整理(zhengli)一下吧。\n",ob,me);
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
