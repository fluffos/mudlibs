//工部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "shuishi"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"太湖水匪","comment":"太湖水匪整编新军完成，不错。\n","reward":6+random(2),"range":"6-7"]),
		(["name":"长江巡防","comment":"巡防完成，大功一件啊。\n","reward":2+random(3),"range":"2-4"]),
		(["name":"督造战舰","comment":"战舰造成，我大宋又添一利器。\n","reward":6+random(4),"range":"6-9"]),
		(["name":"操舟训练","comment":"训练完成，我大宋又添一水战强将。\n","reward":4+random(2),"range":"4-5"]),
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
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：朝廷现在最缺一支劲旅，我去整编太湖水匪吧。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<4)
			command("say 朝廷现在最缺一支劲旅，大人请去整编太湖水匪吧。");
			else
			message_vision("$N看着$n，道：朝廷现在最缺一支劲旅，我先派你去整编太湖水匪吧。\n",ob,me);
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==2)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：长江天险，防务不能放松，我去视察一下。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<4)
			command("say 大人有暇请去视察长江防线。");
			else
			message_vision("$N看着$n，道：你去长江防线看看吧。\n",ob,me);
			tell_object(me,"到了建康府附近的渡口，就可以登船(board boat)去视察防线了。\n");
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==3)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：我去水师造船厂看看新舰的建造情况。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<4)
			command("say 大人请去水师造船厂督促新舰建造。");
			else
			message_vision("$N看着$n，道：你去水师造船厂看看新舰的建造。\n",ob,me);
			tell_object(me,"到了水师造船厂，主要要看的就是新舰的龙骨。\n");
		}
		if (me->query_temp("songtasks/"+DEPART+"/task")==4)
		{
			if (DASONG_D->get_my_pin(me)==1)
			message_vision("$N看着$n，道：我去试试水师的战舰。\n",me,ob);
			else if (DASONG_D->get_my_pin(me)<4)
			command("say 大人请去试试操作水师的战舰。");
			else
			message_vision("$N看着$n，道：你去练习操作水师的战舰。\n",ob,me);
			tell_object(me,"到了钱塘江边就会看到水师的训练战舰。\n");
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
