//刑法部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "sansishi"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"监督铁矿","comment":"完成的还不错嘛。\n","reward":3+random(3),"range":"3-5"]),
		(["name":"度支造册","comment":"任务这么顺利的完成了？\n","reward":1+random(4),"range":"1-4"]),
		(["name":"户籍造册","comment":"户籍造册进行得不错，我大宋明年应有更多的赋税！\n","reward":4+random(5),"range":"4-8"]),
		(["name":"征收赋税","comment":"今年税收看来是足额啊。\n","reward":4+random(5),"range":"4-8"]),
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
	string *taskwhere=({"镇江","苏州","扬州","江州","岳阳","南昌","泉州","福州"});
	string *taskloc=({"/d/zhenjiang/","/d/suzhou/","/d/city/","/d/jiangzhou/","/d/yueyang/","/d/nanchang/","/d/quanzhou2/","/d/fuzhou/"});
    object where;
	int n;
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		gy=me->query_temp("song_identification");
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			n=random(sizeof(taskwhere));
			where=TASK_D->random_room(taskloc[n]);
			me->set_temp("songtasks/sansishi/task1_where",where);
			me->set_temp("songtasks/sansishi/task1_area",taskwhere[n]);
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N对着$n道：听说"+taskwhere[n]+"的铁矿出了点问题，我去监督(jiandu)一下。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say "+taskwhere[n]+"的铁矿出了点问题，大人去监督(jiandu)一下吧。\n");
			else
			message_vision("$N看着$n，道："+taskwhere[n]+"的铁矿出了点问题，你去监督(jiandu)一下吧。\n",ob,me);
			tell_object(me,"到了地头的车马行，上车(hire)就会被送到铁矿了。\n");
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			call_out("question",1,me);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==3)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：我去帮忙把户籍造册吧。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 大人帮忙把户籍造册吧。");
			else
			message_vision("$N看着$n，道：我派你去户籍造册吧。\n",ob,me);
			tell_object(me,"户籍造册需要先到户部尚书处帮忙(request)，然后回到这里造册(zaoce)。记得要记住两地的平民人数啊。\n");
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==4)
		{
			n=random(sizeof(taskwhere));
			where=TASK_D->random_room(taskloc[n]);
			me->set_temp("songtasks/sansishi/task4_where",where);
			me->set_temp("songtasks/sansishi/task4_area",taskwhere[n]);
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：本官去"+taskwhere[n]+"的"+where->query("short")+"征收(zheng)税赋。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 大人能去"+taskwhere[n]+"的"+where->query("short")+"征收(zheng)税赋吗？");
			else
			message_vision("$N看着$n，道：你去"+taskwhere[n]+"的"+where->query("short")+"征收(zheng)税赋吧。\n",ob,me);
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
