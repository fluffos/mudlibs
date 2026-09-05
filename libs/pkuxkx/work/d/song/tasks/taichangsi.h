//刑法部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "taichangsi"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"打扫太庙","comment":"简直是焕然一新啊。\n","reward":3+random(3),"range":"3-5"]),
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
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：天子就要驾临太庙祭祀，本官需要去处理一下。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 天子就要驾临太庙祭祀，大人有暇请去处理一下。");
			else
			message_vision("$N看着$n，道：天子就要驾临太庙祭祀，你去办好这件事。\n",ob,me);
			tell_object(me,"为完成这个任务，在太庙布置(buzhi)一下吧。\n");
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
