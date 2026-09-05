//工部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "gongbu"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"嘉会门外屯田","comment":"屯田完成，京城的粮食更有保障了。\n","reward":3+random(2),"range":"3-4"]),
		(["name":"运送物资","comment":"真是干吏啊，物资输送一丝不差。\n","reward":8+random(6),"range":"8-13"]),
		(["name":"修缮京师建筑","comment":"真是干吏啊，修缮完成，皇城一新啊。\n","reward":4+random(4),"range":"4-7"]),
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
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			if (gy->prepare_yuhen(me)==1)
			command("whisper "+me->query("id")+" 朝廷有一批物资要从"+gy->query_temp("songtasks/"+DEPART+"/yuhen_from_area")+"的"+gy->query_temp("songtasks/"+DEPART+"/yuhen_from_short")+
				"运送到"+gy->query_temp("songtasks/"+DEPART+"/yuhen_to_area")+"的"+gy->query_temp("songtasks/"+DEPART+"/yuhen_to_short")+"，就偏劳大人去押运(yayun)一下了。");
			else
			return npc_error_finish(ob,me);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==3)
		{
			if (gy->prepare_yingshan(me)!=1)
			return npc_error_finish(ob,me);
			else
			{
				command("whisper "+me->query("id")+" 现在"+gy->query_temp("songtasks/gongbu/yingshan")+"，破旧不堪。");
				tell_object(me,"修缮的命令是xiushan。\n");
			}
		}
		if (DASONG_D->get_my_pin(me)==1)
		message_vision("$N看着$n，道：工部最近有些忙不过来？我去帮助"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"一下。\n",me,ob);
		else if (DASONG_D->get_my_pin(me)<5)
		command("say 工部事物繁杂，大人可以帮我去"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"吗？");
		else
		message_vision("$N看着$n，道：工部事物繁多，我先派你去"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"吧。\n",ob,me);
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
