//工部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "dalisi"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"复核案卷","comment":"大人果然是断案如神啊。\n","reward":1+random(5),"range":"1-5"]),
		(["name":"回复刑部","comment":"大人效率可真是高啊。\n","reward":1+random(4),"range":"1-4"]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}
int ask_task()
{
    object me=this_player();
    object ob=this_object(),gy,an;
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			if (DASONG_D->get_my_pin(me)<5)
			command("say 宗卷室有一件案子正等着复核(fuhe)，请大人协助完成。");
			else
            command("say 宗卷室有一件案子正等着复核(fuhe)，你快去把它完成。");
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			an=new("/d/song/obj/an");
			an->move(this_object());
			an->set("owner",me);
			if (DASONG_D->get_my_pin(me)<5)
			command("say 这里有一份案子已经通过复核，请大人代为递送到(fangzhi)刑部库房。");
			else
            command("say 这里有一份案子已经通过复核，你快去把它递送到(fangzhi)刑部库房。");
			command("give "+me->query("id")+" an juan");
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
