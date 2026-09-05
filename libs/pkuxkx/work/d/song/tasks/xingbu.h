//刑法部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "xingbu"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"往刑部大牢运送物资","comment":"不错不错，又是大功一件。\n","reward":2+random(6),"range":"2-7"]),
		(["name":"调查凶案","comment":"这么快就破了这宗无头案？又是大功一件。\n","reward":1+random(4),"range":"1-4"]),
		(["name":"太湖缉凶","comment":"太湖缉凶那么快回来了？真是后生可畏啊。\n","reward":4+random(4),"range":"4-7"]),
		(["name":"追查朝廷钦犯","comment":"听说钦犯已经被捉回来了，呵呵，不错不错。\n","reward":6+random(4),"range":"6-9"]),
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
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：刑部最近有些忙不过来？我去帮助"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 刑部事物繁杂，大人可以帮我去"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"吗？");
			else
			message_vision("$N看着$n，道：刑部事物繁多，我先派你去"+tasks[me->query_temp("songtasks/"+DEPART+"/task")-1]["name"]+"吧。\n",ob,me);
		}
		gy=me->query_temp("song_identification");
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		tell_object(me,"你应该先去临安府府尹那里去要个批文。\n");
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			if (gy->prepare_xiongan(me)==1)
			{
				if (DASONG_D->get_my_pin(me)==1)
				message_vision("$N道：听说"+gy->query_temp("songtasks/gongbu/xiongan_where")->query("short")+"最近出了一起凶杀案，我去查看(chakan)一下。\n",me);
				else if (DASONG_D->get_my_pin(me)<5)
				command("say "+gy->query_temp("songtasks/gongbu/xiongan_where")->query("short")+"最近出了一起凶杀案，请大人去查看(chakan)一下。");
				else
				command("say "+gy->query_temp("songtasks/gongbu/xiongan_where")->query("short")+"最近出了一起凶杀案，你去查看(chakan)一下。");
			}
			else
			return npc_error_finish(ob,me);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==3)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N道：听说最近有一名朝廷重犯在太湖上出没，我去把他捉回来\n",me);
			else if (DASONG_D->get_my_pin(me)<5)
			command("whisper "+me->query("id")+" 最近有一名朝廷重犯在太湖上出没，请大人去把他捉回来，如遇反抗，可就地正法。");
			else
			command("whisper "+me->query("id")+" 最近有一名朝廷重犯在太湖上出没，你去把他捉回来，如遇反抗，可就地正法。");
			tell_object(me,HIC+"太湖共有四处码头，分布在归云庄、嘉兴、慕容和苏州，你可以征用随便任何一处的船只，在码头enter即可。\n"+NOR);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==4)
		{
			if (gy->prepare_zhuicha(me)!=1)
			return npc_error_finish(ob,me);
			else
			{
				if (DASONG_D->get_my_pin(me)==1)
				message_vision("$N翻了一下宗卷，道："+gy->query_temp("songtasks/xingbu/taofan_area")+"的"+gy->query_temp("songtasks/xingbu/taofan_short")+"的巨盗？我去把他抓回来。\n",me);
				else if (DASONG_D->get_my_pin(me)<5)
				command("whisper "+me->query("id")+" 最近有一名朝廷钦犯在"+gy->query_temp("songtasks/xingbu/taofan_area")+"的"+gy->query_temp("songtasks/xingbu/taofan_short")+"留下行踪，请大人去把他抓回来。");
				else
				command("whisper "+me->query("id")+" 最近有一名朝廷钦犯在"+gy->query_temp("songtasks/xingbu/taofan_area")+"的"+gy->query_temp("songtasks/xingbu/taofan_short")+"留下行踪，你去把他抓回来。");
				gy->delete_temp("songtasks/xingbu");
			}
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
