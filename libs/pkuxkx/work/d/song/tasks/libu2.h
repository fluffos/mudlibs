//刑法部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "libu2"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"国子监监考","comment":"这次考试尚算成功，大人果不负我所托，辛苦了。\n","reward":random(8)+4,"range":"4-11"]),
		(["name":"修唐史","comment":"修史的进度极佳，大人辛苦了。\n","reward":3,"range":"3-3"]),
		(["name":"通知觐见","comment":"官员已经来到礼部，有劳大人了。\n","reward":6,"range":"6-6"]),
		(["name":"封禅泰山","comment":"天佑我大宋啊，封禅如此顺利。\n","reward":5,"range":"5-5"]),
	});
int ask_finish()
{
    object me=this_player();
	if (me->query_temp("song_libu2_jinjian")&&this_object()->query("posi")=="礼部尚书")
	{
		if (time()-me->query_temp("song_libu2_jinjian")<300)
		{
			me->add("song/credit",1);
			command("say "+me->query("name")+"大人来了？太好了。");
			me->delete_temp("song_libu2_jinjian");
			tell_object(me,HIC+"你获得了一点大宋功勋。\n"+NOR);
		}
		else
		{
			command("say "+me->query("name")+"大人来迟了。");
			me->delete_temp("song_libu2_jinjian");
		}
		return 1;
	}
	return is_finish(me,DEPART,tasks);
}
int ask_task()
{
    object me=this_player();
    object ob=this_object(),gy,guan,*all;
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		gy=me->query_temp("song_identification");
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：春闱马上就要进行了，本官决定前去国子监监考。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 春闱马上就要进行了，请大人前去国子监监考。");
			else
			message_vision("$N看着$n，道：春闱马上就要进行了，我先派你去国子监监考吧。\n",ob,me);
			message_vision("$N道：到了考官席，你就可以宣布开考(kaikao)了。\n",ob,me);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：修唐史刻不容缓，本官就在这里进行吧(xiushi)。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 修唐史刻不容缓，大人得空就在这里进行吧(xiushi)。");
			else
			message_vision("$N看着$n，道：修唐史刻不容缓，你就在这里进行吧(xiushi)。\n",ob,me);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==3)
		{
			all = DASONG_D->song_all();
			all -=({me});
            guan=all[random(sizeof(all))];
			if (!guan)
			return npc_error_finish(ob,me);
			else
			{
				if (DASONG_D->get_my_pin(me)==1)
				message_vision("$N看着$n，道："+guan->query("name")+"很久没有上朝了，需要通知觐见陛下，本官去通知(notice)他。\n",me,ob);
				else if (DASONG_D->get_my_pin(me)<5)
				command("say "+guan->query("name")+"很久没有上朝了，需要通知觐见陛下，大人请去通知(notice)他。");
				else
				message_vision("$N看着$n，道："+guan->query("name")+"很久没有上朝了，需要通知觐见陛下，你去通知(notice)他。\n",ob,me);
				me->set_temp("songtasks/libu2/find_officer",guan->query("id"));
			}
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==4)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：年年风调雨顺，天佑我大宋，应该封禅泰山了，本官自会去处理。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<5)
			command("say 年年风调雨顺，天佑我大宋，应该封禅泰山了，大人有暇请去处理一下。");
			else
			message_vision("$N看着$n，道：年年风调雨顺，天佑我大宋，应该封禅泰山了，你去办好这件事。\n",ob,me);
			tell_object(me,"在这里指定(zhiding)一名大明官员，有了帮手，你们一起去泰山封禅台封禅(fengshan)吧。\n");
			tell_object(me,HIR+"如果指定的助手是机器人，你就欲哭无泪了，所以指定之前，最好先和要指定的对象通个气。\n"+NOR);
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
